#include "drivers/pic/pic.h"
#include "drivers/pit/pit.h"
#include "drivers/terminal/terminal.h"

#include "kernel/gdt/gdt.h"
#include "kernel/idt/idt.h"
#include "kernel/mm/physical_mgr.h"

#include "multiboot/multiboot.h"

#include "utils/bitmap.h"

#include <cstdio.h>
#include <cstdlib.h>

void on_tick(uint32_t unused)
{
    static int counter = 0;
    counter++;
    if (counter % 100 == 0) // This is a second
    {
        int seconds = counter / 100;
        //printf("Second: %d\n", seconds);
    }
}

extern "C" void kernel_main(multiboot_info_t *multiboot_info)
{
    Terminal::initialize();
    printf("Hello! Welcome to AviKernel!\n");

    GDT::initialize();
    PIC::initialize();
    PIC::enable_all_interrupts();
    IDT::initialize();
    asm("sti");
    PIT::initialize(100, on_tick); // Once every 0.01 second
    if (!PhysicalMgr::initialize(multiboot_info->mem_upper * 1024, multiboot_info->mmap_addr, multiboot_info->mmap_length))
        goto iLoop;

    // physical_addr block1 = PhysicalMgr::allocate_block();
    // physical_addr block2 = PhysicalMgr::allocate_block();
    // physical_addr block3 = PhysicalMgr::allocate_block();
    // printf("Block1 = %p, Block2 = %p, Block3 = %p\n", block1, block2, block3);
    // PhysicalMgr::free_block(block2);
    // physical_addr block4 = PhysicalMgr::allocate_block();
    // printf("Block4 = %p\n", block4);

    iLoop:
    while (1)
    {
    }
}