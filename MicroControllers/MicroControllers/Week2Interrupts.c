#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int value = 1;


int main() {
	
	DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input	
	
	EICRA |= 0x0B;
	EIMSK |= 0x03;
		
	sei();
	
	while(1){
		
	}
};

ISR(INT0_vect){
	PORTD = value;
	shift();
}

ISR(INT1_vect){
	PORTD = value;
	shift();
}

void shift(){
	value = value << 1;
	
	if (value > 128)
	{
		value = 1;
	}
}