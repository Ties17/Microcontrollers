#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

const unsigned char Numbers [16] =
{//		dPgf edcba
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



int main(){
	init();
	set_cursor(0);
	display_text("H");
	set_cursor(2);
	display_text("Y");
	set_cursor(4);
	display_text("K");
	set_cursor(6);
	display_text("JAntje");
// 	DDRD = 0xFF;
// 	while(1){
// 		for (int i = 0 ; i <= sizeof(Numbers); i++)
// 		{
// 			PORTD = Numbers[i];
// 			_delay_ms(1000);
// 		}
// 		PORTD = 0x00;
// 	}	
}
