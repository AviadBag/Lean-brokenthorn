#include "fs/vfs/vfs.h"
#include "kernel/panic.h"

#include <posix/errno.h>
#include <cstdio.h>

VFS::VFS()
{
    // Descriptors 0, 1, 2 are reserved
    for (int i = 0; i <= 2; i++)
        file_descriptors[i].in_use = true;
}

int VFS::allocate_descriptor()
{
    int desct = -1;

    // Find the first unused descriptor
    for (int i = 0; i < VFS_OPEN_FILES_MAX; i++)
    {
        if (!file_descriptors[i].in_use)
        {
            desct = i;
            break;
        }
    }

    return desct;
}

void VFS::free_descriptor(int desct)
{
    if (!file_descriptors[desct].in_use)
        panic("VFS::free_descriptor() -> trying to free a descriptor which is not in use! (descriptor %d)", desct);

    file_descriptors[desct].in_use = false;
}

void VFS::mount_fs(Path where, Path device, FS *what)
{
    if (device.is_folder() && !device.is_root())
        panic("VFS::mount_fs() -> Given a folder as a device!");

    if (!where.is_folder())
        panic("VFS::mount_fs() -> Where to mount must be a folder!");

    MountedFS mfs;
    mfs.mount_path = where;
    mfs.fs = what;
    what->mount(device);
    mounted_fss.append(mfs);
}

FS *VFS::get_fs(Path path)
{
    size_t max = 0;
    FS *fs;

    Path debug_path;

    for (int i = 0; i < mounted_fss.size(); i++)
    {
        MountedFS mounted_fs = mounted_fss.get(i);

        if (mounted_fs.mount_path.get_depth() <= path.get_depth())
        {
            bool found = true;
            for (int j = 0; j < mounted_fs.mount_path.get_depth(); j++)
            {
                if (mounted_fs.mount_path.get_part(i) != path.get_part(i))
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                size_t n = mounted_fs.mount_path.get_depth() + 1;
                if (n > max)
                {
                    max = n;
                    fs = mounted_fs.fs;
                    debug_path = mounted_fs.mount_path;
                }
            }
        }
    }

    return max == 0 ? nullptr : fs;
}

int VFS::open(const char *path, int oflag, ...)
{
    // I must declare the variables at the beginning, because else - it does not allow me to use 'goto'.
    int desct;
    bool exist;
    FS *fs;

    // Allocate the descriptor!
    desct = allocate_descriptor();
    if (desct == -1) // There is no a free descriptor
    {
        set_errno(EMFILE);
        goto exit_err;
    }

    // Retrieve the corresponding filesystem
    fs = get_fs(path);
    if (!fs)
    {
        set_errno(ENOENT);
        goto exit_err_cleanup;
    }

    exist = fs->file_exist(path);

    /* -------- Treat the various cases regarding the file existance. -------- */
    // Case 1 - O_CREAT and O_EXCL = fail if file exist.
    if ((oflag & O_CREAT) && (oflag & O_EXCL) && exist)
    {
        set_errno(EEXIST);
        goto exit_err_cleanup;
    }
    // Case 2 - O_CREAT is clear and the file does not exist; or path is empty.
    if ((!(oflag & O_CREAT) && !exist) || !(*path))
    {
        set_errno(ENOENT);
        goto exit_err_cleanup;
    }

    // Create the file if needed
    if (O_CREAT && !exist)
    {
        fs_status_code code = fs->create_file(path);
        switch (code)
        {
        case FS_NOT_ENOUGH_MEMORY:
            panic("FS::open() -> Not enough memory!");
            break;
        case FS_UNSUPPORTED_OPERATION:
            set_errno(EACCES);
            goto exit_err_cleanup;
        case FS_OK:
            break;
        default:
            panic("FS::open() -> unimplemented return code while trying to create a file");
        }
    }

    return desct;

// Special exists
exit_err_cleanup:
    free_descriptor(desct);
exit_err:
    return -1;
}
