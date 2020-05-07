/*
 * Week3.c
 *
 * Created: 2/12/2020 1:28:53 PM
 *  Author: brand
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#define F_CPU 8000000

#include <avr/interrupt.h>
#include <util/delay.h>

#include "lcd.h"

int value = 5;

int main()
{	
	DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input	
	init();
	_delay_ms(1000);
	
	while(1){
		lcd_write_command(0x01);
		_delay_ms(250);
		set_cursor(0);
		_delay_ms(250);
		display_text("hmmm");
		_delay_ms(1500);
	}
}