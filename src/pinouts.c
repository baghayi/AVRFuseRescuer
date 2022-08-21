#include "pinouts.h"
#include <avr/io.h>

void pinMode(pin_t pin, pin_mode_t mode) {
    if (mode == OUTPUT)
        *(pin.ddr) |= (1 << pin.pin);
    else
        *(pin.ddr) &= ~(1 << pin.pin);
}

void configurePins() {
    pinMode(RESET, OUTPUT);
    pinMode(VCC, OUTPUT);
    pinMode(XA0, OUTPUT);
    pinMode(XA1, OUTPUT);
    pinMode(BS1, OUTPUT);
    pinMode(BS2, OUTPUT);
    pinMode(PAGEL, OUTPUT);
    pinMode(XTAL1, OUTPUT);
    pinMode(WR, OUTPUT);
    pinMode(RDY_BSY, INPUT);
    pinMode(OE, OUTPUT); // Could be Output & also Input.
}

void changeDataPinsMode(pin_mode_t direction) {
    if (direction == OUTPUT)
        digitalWrite(OE, HIGH);
    else
        digitalWrite(OE, LOW);

    for (int i = 0; i < 8; i++) 
        pinMode(DATA[i], direction);
}

void digitalWrite(pin_t pin, digital_value_t value) {
    if(value == HIGH)
        *(pin.port) |= (1 << pin.pin);
    else
        *(pin.port) &= ~(1 << pin.pin);
}

digital_value_t digitalRead(pin_t pin) {
    if (((*pin.data) & (1 << pin.pin)) == 0)
        return LOW;
    else
        return HIGH;
}
