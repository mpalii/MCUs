/*
 * Created: 18.12.2021 16:04:24
 * Author : Maksym Palii
 */ 

#include <avr/io.h>

int main(void)
{
	// Configure data direction for pin 0 (port D) as OUTPUT
	DDRD |= (1 << DDD0);
	
	// Set pin 0 (port D) driven high (one)
	PORTD |= (1 << PORTD0);
	
	while (1) 
	{
		// No logic
	}
}
