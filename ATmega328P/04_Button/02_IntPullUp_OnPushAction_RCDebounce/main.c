/*
 * Created: 16/04/2022 18:01:18
 * Author : Maksym Palii
 */ 

#define F_CPU (1000000)

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= _BV(DDD0);		// Configure data direction for pin 0 (port D) as OUTPUT
	PORTD |= _BV(PORTD7);	// Enable internal pull-up resistor pins 7 (port D)

	_delay_ms(2);			// Delay for capacitor charging

	bool button_was_pressed = false;

    while (true) 
    {
		// Check whether the button was pressed and perform a toggle
		if (bit_is_clear(PIND, PIND7) && !button_was_pressed)
		{
			button_was_pressed = true;
			PORTD ^= _BV(PORTD0);
		}

		// Check whether the button was released
		if (bit_is_set(PIND, PIND7) && button_was_pressed)
		{
			button_was_pressed = false;
		}
    }
}
