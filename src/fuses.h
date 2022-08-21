
#ifndef _FUSES_H_
#define _FUSES_H_

#include <stdint.h>
#include "pinouts.h"

#define WRITE_FUSE_BITS_COMMAND_BYTE 0b01000000

void select_high_data_byte();
void select_low_data_byte();
void select_extended_data_byte();
void begin_changing_fuse_bits();
void load_data_low_byte(uint8_t data);
void write_fuse_low_bites(uint8_t fuse);
void write_fuse_high_bites(uint8_t fuse);
void write_fuse_extended_bites(uint8_t fuse);

#endif
