/**
 * @file main.c
 * @author Maksym Palii
 * @brief Example 05 - EXTERNAL PULL-DOWN resistor R = 22kΩ is used  
 * @version 0.1
 * @date 2022-04-22
 */

#include <avr/io.h>
#include <stdbool.h>

int main(void)
{
    DDRB |= (_BV(DDB0) | _BV(DDB1));    // Configure data direction for pin 0, 1 (port B) as OUTPUT

    bool button_was_pressed = false;

    while (true)
    {
        // check whether button was pressed
        if (bit_is_set(PINC, PINC0) && !button_was_pressed)
        {
            button_was_pressed = true;
            PORTB ^= _BV(PORTB0);
            // some event start
        }
        
        // check whether button was released
        if (bit_is_clear(PINC, PINC0) && button_was_pressed)
        {
            button_was_pressed = false;
            PORTB ^= _BV(PORTB1);
            // some event finish
        }
    }
}
