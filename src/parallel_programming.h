
#ifndef _PARALLEL_PROGRAMMING_H_
#define _PARALLEL_PROGRAMMING_H_

#include "pinouts.h"

static const pin_t Prog_enable[4] = {BS1, XA0, XA1, PAGEL};
void clear_prog_enable_pins();

void enter_parallel_programming_mode();
void exit_parallel_programming_mode();
void enable_command_loading();
void enable_data_loading();
void load_changes();
void setData(uint8_t data);
void commit_changes();
void power_up_target_device();
void power_down_target_device();
void bring_target_device_reset_high();
void bring_target_device_reset_low();

#endif
