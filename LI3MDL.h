#ifndef LI3MDL
#define LI3MDL

#include "i2c.h"
#include "addressList.h"

// Functions desired
uint8_t* get_full_scale_configuration();
uint8_t get_output_data_rate();
int set_output_data_rate(uint8_t data_rate);

#endif