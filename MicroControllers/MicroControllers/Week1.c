/*
 * Week1.c
 *
 * Created: 5-2-2020 13:03:01
 *  Author: Ties
 */ 
#define F_CPU 8000000

#define OFF 0
#define ON 1

#include <avr/io.h>
#include <util/delay.h>

int main(){
	
	
	
}

void Move_Delay() {
	_delay_ms(500);
}

void opdracht2(){
	DDRD = 0xFF;
	while (1){
		PORTD = 0x04;
		Move_Delay();
		PORTD = 0x02;
		Move_Delay();
	}
}

void opdracht3(){
	DDRD = 0xFF;
	DDRC = 0x00;
	while (1){
		if (PINC & 0x01){
			PORTD = 0x02;
			Move_Delay();
			PORTD = 0x00;
			Move_Delay();
		}
	}
}

void opdracht4(){
	DDRD = 0xFF;
	
	int value = 0x01;
	
	while (1){
		Move_Delay();
		PORTD = value;
		
		value = value << 1;
		
		if(value > 128){
			value = 0x01;
		}
	}
}

void opdracht5(){
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	
	int array[8][8] = {
		{1,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,1,1},
		{0,0,1,1,1,1,0,0},
		{0,1,0,1,1,0,1,0},
		{1,0,1,0,0,1,0,1},
		{1,1,0,0,0,0,1,1},
		{1,1,1,0,0,1,1,1},
		{1,0,1,1,1,1,0,1}
	};
	
	while (1){
		
		for (int i = 0; i < 8; i++)
		{
			int value = arrToBin(array[i]);
			PORTA = value;
			PORTB = value;
			PORTC = value;
			PORTD = value;
			Move_Delay();
		}
	}
}

int arrToBin(int array[]) // 0b11011001
{
	int multiplier = 128;
	int number = 0;
	for (int i = 0; i < 8; i++)
	{
		number += array[i] * multiplier;
		multiplier >>= 1;
	}

	return number;
}

void opdracht6(){
	int state = OFF;
	
	DDRD = 0xFF;
	DDRC = 0x00;
	
	while (1) {
		if (PINC & 0x01) {
			if (state == OFF) {
				state = ON;
				} else {
				state = OFF;
			}
		}
		
		if (state == OFF) {
			PORTD = 0x80;
			_delay_ms(125);
			PORTD = 0x00;
			_delay_ms(125);
			} else {
			PORTD = 0x80;
			_delay_ms(500);
			PORTD = 0x00;
			_delay_ms(500);
		}
	}

}