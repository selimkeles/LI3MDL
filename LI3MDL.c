// LI3MDL.c
#include "LI3MDL.h"
#include <stdio.h>
#include <stdlib.h>

config_t *scan_all_registers() {
    config_t *MAP = malloc(sizeof(config_t));
    if (MAP == NULL) {
        perror("Could not allocate structure");
        return (config_t *)NULL;
    }
    for (int i = RESERVED0; i < LAST_REGISTER; i++) {
        printf("addresses %d: %d\n", i, (uint8_t *)MAP + i);
        if (i2c_read(SUPPLIED_BUS, i, 1, (uint8_t *)MAP + i) != STATUS_OK) {
            if (i2c_read(GROUNDED_BUS, i, 1, (uint8_t *)MAP + i) != STATUS_OK) {
                perror("Could not access the i2c bus");
                free(MAP);
                return (config_t *)NULL;
            }
        }
    }
    return MAP;
}

uint8_t get_full_scale_configuration() {
    uint8_t full_scale_config;
    if (i2c_read(SUPPLIED_BUS, CTRL_REG2, 1, &full_scale_config) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, CTRL_REG2, 1, &full_scale_config) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return 0b11 & (full_scale_config >> 5);
}

uint8_t get_output_data_rate() {
    uint8_t output_data_rate;
    // returns 1 if faults then try grounded bus address
    if (i2c_read(SUPPLIED_BUS, CTRL_REG1, 1, &output_data_rate) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, CTRL_REG1, 1, &output_data_rate) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return output_data_rate;
}

uint8_t set_output_data_rate(uint8_t *data_rate) {
    // returns 1 if faults then try grounded bus address
    if (i2c_write(SUPPLIED_BUS, CTRL_REG1, 1, data_rate) != STATUS_OK) {
        if (i2c_write(GROUNDED_BUS, CTRL_REG1, 1, data_rate) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return 1;
}

uint8_t enable_interrupt_pin() {
    uint8_t enable = 1;
    if (i2c_read(SUPPLIED_BUS, INT_CFG, 1, &enable) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, INT_CFG, 1, &enable) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return 1;
}

uint8_t disable_interrupt_pin() {
    uint8_t enable = 0;
    if (i2c_read(SUPPLIED_BUS, INT_CFG, 1, &enable) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, INT_CFG, 1, &enable) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return 1;
}

uint16_t read_axis_output_x() {
    // We can't make for loop or smth since i2c_read might flush buffer inside
    uint8_t output_h = 0;
    if (i2c_read(SUPPLIED_BUS, OUT_X_H, 1, &output_h) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, OUT_X_H, 1, &output_h) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    uint8_t output_l = 0;
    if (i2c_read(SUPPLIED_BUS, OUT_X_L, 1, &output_l) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, OUT_X_L, 1, &output_l) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return ((uint16_t)output_h << 8) || output_l;
}

uint16_t read_axis_output_y() {
    // We can't make for loop or smth since i2c_read might flush buffer inside
    uint8_t output_h = 0;
    if (i2c_read(SUPPLIED_BUS, OUT_Y_H, 1, &output_h) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, OUT_Y_H, 1, &output_h) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    uint8_t output_l = 0;
    if (i2c_read(SUPPLIED_BUS, OUT_Y_L, 1, &output_l) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, OUT_Y_L, 1, &output_l) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return ((uint16_t)output_h << 8) || output_l;
}
uint16_t read_axis_output_z() {
    // We can't make for loop or smth since i2c_read might flush buffer inside
    uint8_t output_h = 0;
    if (i2c_read(SUPPLIED_BUS, OUT_Z_H, 1, &output_h) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, OUT_Z_H, 1, &output_h) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    uint8_t output_l = 0;
    if (i2c_read(SUPPLIED_BUS, OUT_Z_L, 1, &output_l) != STATUS_OK) {
        if (i2c_read(GROUNDED_BUS, OUT_Z_L, 1, &output_l) != STATUS_OK) {
            perror("Could not access the i2c bus");
            return -1;
        }
    }
    return ((uint16_t)output_h << 8) || output_l;
}
