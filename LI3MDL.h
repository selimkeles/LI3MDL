// LI3MDL.h
#ifndef LI3MDL
#define LI3MDL

#include "i2c.h"
#include "addressBook.h"

// Functions desired
config_t *scan_all_registers();
uint8_t get_full_scale_configuration();
uint8_t get_output_data_rate();
uint8_t set_output_data_rate(uint8_t *data_rate);
uint8_t enable_interrupt_pin();
uint8_t disable_interrupt_pin();
uint16_t read_axis_output_x();
uint16_t read_axis_output_y();
uint16_t read_axis_output_z();
#endif
