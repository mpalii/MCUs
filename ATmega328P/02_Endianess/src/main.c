/*
 * Created: 03/04/2022 19:48:32
 * Author : Maksym Palii
 */ 

#include <avr/io.h>
#include <stdbool.h>

int main(void)
{
    // Configure data direction for pins 0-7 (port D) as OUTPUT
    DDRD = 0xFF;	// Show result in port D

    uint16_t value = 544;    // aka MSB [0000 0010]  LSB [0010 0000] or (512 + 32)

    uint8_t *first_byte_address = (uint8_t *) &value;
    
    // Show result in port D
    PORTD = *first_byte_address;            // LSB [0010 0000]
    //PORTD = *(first_byte_address + 1);      // MSB [0000 0010]

    while (true) 
    {
		  // No logic
    }
}

