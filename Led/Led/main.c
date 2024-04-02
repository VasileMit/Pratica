
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{DDRB=0xFF;

while(1)
{
	PORTB=0x0F;
	_delay_ms(400);
	PORTB=0x0;
	_delay_ms(400);
	PORTB=0x0F;
	_delay_ms(1000);
	PORTB=0x0;
	_delay_ms(1000);
}

}