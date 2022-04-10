/*
 * Created: 08/04/2022 21:28:29
 * Author : Maksym Palii
 */ 

#define __AVR_ATmega328P__
#define F_CPU (1000000)
#define half_period_for_frequency(FR) (F_CPU/(2.0 * FR))

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main(void)
{
    // Configure data direction for pins 0 (port D) as OUTPUT
    DDRD |= _BV(PIND0);
    // Set pin 0 (port D) driven high (one)
    PORTD |= _BV(PIND0);
    // Half-period
    const double HALF_PERIOD = half_period_for_frequency(1);
    //const double HALF_PERIOD = half_period_for_frequency(240);
    //const double HALF_PERIOD = half_period_for_frequency(50);
    //const double HALF_PERIOD = half_period_for_frequency(24);

    while (true) 
    {
        _delay_us(HALF_PERIOD);
        PORTD ^= _BV(PIND0);    // toggle pin
    }
}
