#include "fuses.h"
#include "pinouts.h"
#include "parallel_programming.h"

void select_high_data_byte() {
    digitalWrite(BS1, HIGH);
    digitalWrite(BS2, LOW);
}

void select_low_data_byte() {
    digitalWrite(BS1, LOW);
    digitalWrite(BS2, LOW);
}

void select_extended_data_byte() {
    digitalWrite(BS1, LOW);
    digitalWrite(BS2, HIGH);
}

void begin_changing_fuse_bits() {
    enable_command_loading();
    digitalWrite(BS1, LOW);
    setData(WRITE_FUSE_BITS_COMMAND_BYTE); // loading fuse changing command
    load_changes();
}

void load_data_low_byte(uint8_t data) {
    enable_data_loading();
    setData(data);
    load_changes();
}

void write_fuse_low_bites(uint8_t fuse) {
    begin_changing_fuse_bits();
    load_data_low_byte(fuse);
    commit_changes();
}

void write_fuse_high_bites(uint8_t fuse) {
    begin_changing_fuse_bits();
    load_data_low_byte(fuse);
    select_high_data_byte();
    commit_changes();
    select_low_data_byte();
}

void write_fuse_extended_bites(uint8_t fuse) {
    begin_changing_fuse_bits();
    load_data_low_byte(fuse);
    select_extended_data_byte();
    commit_changes();
    select_low_data_byte();
}
