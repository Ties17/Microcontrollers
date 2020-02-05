/*
 * MicroControllers.c
 *
 * Created: 5-2-2020 10:44:24
 * Author : Ties
 */ 
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

void Move_Delay() {
	_delay_ms(500);
}


int main(void)
{
    opdracht1();
}

void opdracht1(){
	 DDRD = 0xFF;
	 while (1){
		 PORTD = 0x04;
		 Move_Delay();
		 PORTD = 0x02;
		 Move_Delay();
	 }
}

