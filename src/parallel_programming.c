#include <util/delay.h>
#include "parallel_programming.h"

void enter_parallel_programming_mode() {
    power_down_target_device();
    _delay_us(1);

    power_up_target_device();

    _delay_us(40); // between 20us to 60us
    bring_target_device_reset_high();

    _delay_us(20);
    digitalWrite(WR, HIGH);

    _delay_us(300); // waiting for 300us before giving any commands
}

void exit_parallel_programming_mode() {
    power_down_target_device();
}

void enable_command_loading() {
    digitalWrite(XA1, HIGH);
    digitalWrite(XA0, LOW);
}

void load_changes() {
    digitalWrite(XTAL1, HIGH);
    _delay_us(1);
    digitalWrite(XTAL1, LOW);
}

void enable_data_loading() {
    digitalWrite(XA1, LOW);
    digitalWrite(XA0, HIGH);
}

void setData(uint8_t data) {
    changeDataPinsMode(OUTPUT);
    for(int i = 0; i < 8; i++) {
        digitalWrite(DATA[i], ((data & 1) == 0 ? LOW : HIGH));
        data = data >> 1;
    }
}

void commit_changes() {
    digitalWrite(WR, LOW);
    while(digitalRead(RDY_BSY) == LOW);
    digitalWrite(WR, HIGH); // revert back to its original state
}

void clear_prog_enable_pins() {
    for (int i = 0; i < 4; i++)
        digitalWrite(Prog_enable[i], LOW);
}

void bring_target_device_reset_high() {
    digitalWrite(RESET, HIGH);
}

void bring_target_device_reset_low() {
    digitalWrite(RESET, LOW);
}

void power_up_target_device() {
    digitalWrite(VCC, HIGH);
}

void power_down_target_device() {
    bring_target_device_reset_low();
    digitalWrite(VCC, LOW);
    digitalWrite(BS1, LOW);
    digitalWrite(BS2, LOW);
    digitalWrite(XA0, LOW);
    digitalWrite(XA1, LOW);
    digitalWrite(PAGEL, LOW);
    digitalWrite(XTAL1, LOW);
    digitalWrite(WR, LOW);

    pinMode(OE, OUTPUT);
    digitalWrite(OE, LOW);
}
