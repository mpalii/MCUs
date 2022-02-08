/*
 * Created: 18.12.2021 16:04:24
 * Author : Maksym Palii
 */ 
#define __AVR_ATmega328P__
#define F_CPU (1000000UL)

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Configure data direction for pin 0 (port D) as OUTPUT
	DDRD |= (1 << DDD0);
	
	while (1) 
	{
		for (char i = 0; i < 6; i++)
		{
			PORTD ^= (1 << PD0);
			_delay_ms(125);
		}
		_delay_ms(5000);
	}
}
