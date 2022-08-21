#include "pinouts.h"
#include "parallel_programming.h"
#include "fuses.h"
#include <util/delay.h>

const pin_t start_btn = {port: &PORTB, data: &PINB, ddr: &DDRB, pin: PB3};

int main(void) {
    configurePins();

    pinMode(start_btn, INPUT);
    digitalWrite(start_btn, HIGH);

    while(1) {
        while(digitalRead(start_btn) == HIGH);
        _delay_ms(200);
        if (digitalRead(start_btn) == LOW) {
            start_operations();
            _delay_ms(500);
        }
    }
}

void start_operations() {
    enter_parallel_programming_mode();

    //execute commands
    write_fuse_low_bites(0x62);
    write_fuse_high_bites(0xD9);
    write_fuse_extended_bites(0xFF);

    exit_parallel_programming_mode();
}
