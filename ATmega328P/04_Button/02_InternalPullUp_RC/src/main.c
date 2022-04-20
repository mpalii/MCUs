/**
 * @file main.c
 * @author Maksym Palii
 * @brief Example 02 - INTERNAL PULL-UP resistor is used, R = 2.2kΩ and C = 0.1µF is used for debouncing  
 * @version 0.1
 * @date 2022-04-20
 */

#define F_CPU (1000000)

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (_BV(DDB0) | _BV(DDB1));    // Configure data direction for pin 0, 1 (port B) as OUTPUT
    PORTC |= _BV(PORTC0);               // Enable internal pull-up resistor pin 0 (port C)

    //_delay_ms(2);                     // FIX: delay for capacitor charging

    bool button_was_pressed = false;

    while (true)
    {
        // check whether button was pressed
        if (bit_is_clear(PINC, PINC0) && !button_was_pressed)
        {
            button_was_pressed = true;
            PORTB ^= _BV(PORTB0);
            // some event start
        }
        
        // check whether button was rekeased
        if (bit_is_set(PINC, PINC0) && button_was_pressed)
        {
            button_was_pressed = false;
            PORTB ^= _BV(PORTB1);
            // some event finish
        }
    }
}
