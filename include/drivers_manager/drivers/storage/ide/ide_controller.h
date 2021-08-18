#ifndef __IDE_COMPATIBILITY_CONTROLLER_H__
#define __IDE_COMPATIBILITY_CONTROLLER_H__

// This class represents the IDE controller (host adapter). It allows you to send data and get data from it's register.

#include <stdint.h>

class IDEController
{
public:
    // The IDE controller has to groups of ports - I call it ports 1 and ports 2.
    IDEController(uint16_t ports1_base, uint16_t ports2_base);

    uint16_t read_data_register();
    uint8_t  read_error_register();
    uint8_t  read_sector_count_register();
    uint8_t  read_sector_number_register();
    uint8_t  read_cylinder_LSB_register();
    uint8_t  read_cylinder_MSB_register();
    uint8_t  read_drive_head_register();
    uint8_t  read_status_register();
    uint8_t  read_alternate_status_register();
    uint8_t  read_driver_address_register();

    void write_data_register(uint16_t data);
    void write_precompensation_register(uint8_t data);
    void write_sector_count_register(uint8_t data);
    void write_sector_number_register(uint8_t data);
    void write_cylinder_LSB_register(uint8_t data);
    void write_cylinder_MSB_register(uint8_t data);
    void write_drive_head_register(uint8_t data);
    void write_command_register(uint8_t data);
    void write_digital_output_register(uint8_t data);

private:
    uint16_t ports1_base, ports2_base;
};
#endif // __IDE_COMPATIBILITY_CONTROLLER_H__