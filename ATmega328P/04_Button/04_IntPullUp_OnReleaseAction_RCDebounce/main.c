/*
 * Created: 16/04/2022 20:15:30
 * Author : Maksym Palii
 */ 

#include <avr/io.h>
#include <stdbool.h>

int main(void)
{
	DDRD |= _BV(DDD0);		// Configure data direction for pin 0 (port D) as OUTPUT
	PORTD |= _BV(PORTD7);	// Enable internal pull-up resistor pins 7 (port D)

	bool button_was_pressed = false;

    while (true) 
    {
		// Check whether the button was pressed
		if (bit_is_clear(PIND, PIND7) && !button_was_pressed)
		{
			button_was_pressed = true;
		}

		// Check whether the button was released and perform toggle
		if (bit_is_set(PIND, PIND7) && button_was_pressed)
		{
			button_was_pressed = false;
			PORTD ^= _BV(PORTD0);
		}
    }
}
