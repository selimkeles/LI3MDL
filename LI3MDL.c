#include "LI3MDL.h"
#include <stdio.h>

uint8_t* get_full_scale_configuration() {
    uint8_t registerArr[REGISTER_SIZE] = {0};

    for (int i = RESERVED0; i <= INT_THS_H; i++) {
        if (i2c_read(SUPPLIED_BUS, CTRL_REG1, 1, registerArr[i])) {
            if (i2c_read(GROUNDED_BUS, CTRL_REG1, 1, registerArr[i])) {
                return NULL;
            }
        }
    }
    return registerArr;
}

uint8_t get_output_data_rate() {

    uint8_t output_data_rate;

    // returns 1 if faults then try grounded bus address
    if (i2c_read(SUPPLIED_BUS, CTRL_REG1, 1, &output_data_rate)) {
        if (i2c_read(GROUNDED_BUS, CTRL_REG1, 1, &output_data_rate)) {
            return NULL;
        }
    }
    return output_data_rate;
}

int set_output_data_rate(uint8_t data_rate) {

    // returns 1 if faults then try grounded bus address
    if (i2c_write(SUPPLIED_BUS, CTRL_REG1, 1, data_rate)) {
        if (i2c_write(GROUNDED_BUS, CTRL_REG1, 1, data_rate)) {
            return 0;
        }
    }
    return 1;
}