#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

const unsigned char Numbers [16] =
{//	   gfedcba
	0b00111111,// 0
	0b00000110,// 1
	0b01011011,// 2
	0b01001111,// 3
	0b01100110,// 4
	0b01101101,// 5
	0b01111101,// 6
	0b00000111,// 7
	0b01111111,// 8
	0b01101111,// 9
	0b01110111,// a
	0b01111100,// b
	0b00111001,// c
	0b01011110,// d
	0b01111001,// e
	0b01110001// f
	
};


const unsigned char LightShowVals [23] = {
//	   gfedcba
	0b00000000,
	0b00000001,
	0b00000010,
	0b00000100,
	0b00001000,
	0b00010000,
	0b00100000,
	0b00000001,
	0b00100010,
	0b01000000,
	0b00010100,
	0b00001000,
	0b00011100,
	0b01011100,
	0b01111110,
	0b01111111,
	0b01111101,
	0b01101101,
	0b00101101,
	0b00100101,
	0b00100001,
	0b00000001,
	0b00000000
};

void lightShow(){
	int val = 0;
	
	while(1){
		PORTB = LightShowVals[val];
		wait(150);
		val += 1;
		if (val > 22)
		{
			val = 0;
		}
	}
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void display(int digit){
	PORTB = Numbers[digit];
}





int main(){

	DDRB = 0xFF;
	DDRC = 0x00;
	
	lightShow();
	
	
	
}
