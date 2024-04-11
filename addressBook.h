// addressBook.h
#ifndef ADRESSLIST
#define ADRESSLIST

#include <stdint.h>

// Bus Address
#define SUPPLIED_BUS 0x1E
#define GROUNDED_BUS 0x1C

// X-MACRO List of registers for easier usage:

// Register Addresses
#define REG(a, b) a = b,
enum {
#include "registers.h"
};
#undef REG

#define REG(a, b) uint8_t a;
typedef struct __attribute__((packed))
{
#include "registers.h"
} config_t;

#undef REG
#endif // ADRESSLIST
