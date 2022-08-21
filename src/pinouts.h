
#ifndef _PINOUTS_H_
#define _PINOUTS_H_

#include <avr/io.h>
#include <stdint.h>

typedef enum {
    INPUT = 0, OUTPUT = 1
} pin_mode_t;

typedef enum {
    LOW = 0, HIGH = 1
} digital_value_t;

typedef struct pin {
    volatile uint8_t * port;
    volatile uint8_t * ddr;
    uint8_t pin;
    volatile uint8_t * data;
} pin_t;

static const pin_t RESET = {port: &PORTB, ddr: &DDRB, pin: PB1};
static const pin_t VCC = {port: &PORTB, ddr: &DDRB, pin: PB0};

static const pin_t BS1 = {port: &PORTD, ddr: &DDRD, pin: PD0};
static const pin_t BS2 = {port: &PORTD, ddr: &DDRD, pin: PD1};
static const pin_t XA0 = {port: &PORTD, ddr: &DDRD, pin: PD2};
static const pin_t XA1 = {port: &PORTD, ddr: &DDRD, pin: PD3};
static const pin_t PAGEL = {port: &PORTD, ddr: &DDRD, pin: PD4};
static const pin_t XTAL1 = {port: &PORTD, ddr: &DDRD, pin: PD5};
static const pin_t WR = {port: &PORTD, ddr: &DDRD, pin: PD6}; // Active-Low
static const pin_t RDY_BSY = {port: &PORTD, ddr: &DDRD, data: &PIND, pin: PD7}; // High means ready & LOW means busy
static const pin_t OE = {port: &PORTB, ddr: &DDRB, data: &PINB, pin: PB2}; // OUTOUT WHEN OE is low

static const pin_t DATA_BIT0 = {port: &PORTB, ddr: &DDRB, data: &PINB, pin: PB4};
static const pin_t DATA_BIT1 = {port: &PORTB, ddr: &DDRB, data: &PINB, pin: PB5};
static const pin_t DATA_BIT2 = {port: &PORTC, ddr: &DDRC, data: &PINC, pin: PC0};
static const pin_t DATA_BIT3 = {port: &PORTC, ddr: &DDRC, data: &PINC, pin: PC1};
static const pin_t DATA_BIT4 = {port: &PORTC, ddr: &DDRC, data: &PINC, pin: PC2};
static const pin_t DATA_BIT5 = {port: &PORTC, ddr: &DDRC, data: &PINC, pin: PC3};
static const pin_t DATA_BIT6 = {port: &PORTC, ddr: &DDRC, data: &PINC, pin: PC4};
static const pin_t DATA_BIT7 = {port: &PORTC, ddr: &DDRC, data: &PINC, pin: PC5};
static const pin_t DATA[8] = {DATA_BIT0, DATA_BIT1, DATA_BIT2, DATA_BIT3, DATA_BIT4, DATA_BIT5, DATA_BIT6, DATA_BIT7};


void pinMode(pin_t, pin_mode_t);
void digitalWrite(pin_t, digital_value_t);
digital_value_t digitalRead(pin_t);
void configurePins();
void changeDataPinsMode(pin_mode_t);

#endif
