/*
 * Created: 27/03/2022 16:53:21
 * Author : Maksym Palii
 */ 

#define __AVR_ATmega328P__

#include <avr/io.h>
#include <stddef.h>

int main(void)
{
	// Configure data direction for pins 0-7 (port D) as OUTPUT
	DDRD = 0xFF;
	
	// Implementation-specific data type, for ATmega328P is a 'long unsigned int'
	size_t result;
	
	//result = sizeof(char);
	//result = sizeof(unsigned char);
	//result = sizeof(signed char);
	
	//result = sizeof(int);
	//result = sizeof(unsigned int);
	//result = sizeof(signed int);
	
	//result = sizeof(long int);
	//result = sizeof(long unsigned int);
	//result = sizeof(long signed int);
	
	//result = sizeof(long long int);
	//result = sizeof(long long unsigned int);
	//result = sizeof(long long signed int);
	
	//result = sizeof(short int);
	//result = sizeof(short unsigned int);
	//result = sizeof(short signed int);
	
	//result = sizeof(float);
	
	//result = sizeof(double);
	//result = sizeof(long double);
	
	//result = sizeof(void);
	
	//result = sizeof(char *);
	//result = sizeof(int *);
	//result = sizeof(long *);
	//result = sizeof(long long *);
	//result = sizeof(float *);
	//result = sizeof(double *);
	//result = sizeof(void *);
	
	//result = sizeof(uint8_t);
	//result = sizeof(int8_t);
	
	//result = sizeof(uint16_t);
	//result = sizeof(int16_t);
	
	//result = sizeof(uint32_t);
	//result = sizeof(int32_t);
	
	//result = sizeof(uint64_t);
	//result = sizeof(int64_t);
	
	//result = sizeof(0xFF);
	//result = sizeof(0xffFF);
	//result = sizeof(0xFFffFF);
	result = sizeof(0xFFffFFffFFffFF);
	
	// Show result in port D
	PORTD = result;

    while (1) 
    {
		// No logic
    }
}


