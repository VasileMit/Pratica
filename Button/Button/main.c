#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define  NUMERE PORTD
#define  CIFRE PORTB
unsigned int go[10] ={~0xBF,~0x86,~0xDB,~0xCF,~0xE6,~0xED,~0xFD,~0x87,~0xFF,~0xEF};//Anod
unsigned int r = 0;
unsigned int razr1=0,razr2=0,razr3=0;
unsigned char  bc547=0;
void vse_numere (unsigned int rasbivca_go)

{
	
	razr1=rasbivca_go/100;
	razr2=rasbivca_go%100/10;
	razr3=rasbivca_go%10;
}

ISR (TIMER0_OVF_vect)
{
	if(bc547==1){PORTB=0xE;PORTD=go[razr1];}
	if(bc547==2){PORTB=0xD;PORTD=go[razr2];}
	if(bc547==3){PORTB=0xB;PORTD=go[razr3];}
	

		bc547++;
		if(bc547>3) bc547=1;
}

int main(void)
{   DDRD=0xFF;
	DDRB=0x07;
	
	DDRC&=~((1<<4)|(1<<5));
	
	PORTC|=(1<<4)|(1<<5);
	//PORTB=0x1;
	//PORTD=0x3F;
	
	TCCR0 |=(1<<1);TCCR0&=~((1<<0)|(1<<2));
	TIMSK |=(1<<0);
	TCNT0 = 0;
	sei ();



	while(1)
	{
		vse_numere(r);
		
		if(~PINC&(1<<5))
		{
			r++;
			_delay_ms(300);
			
		}
		if(~PINC&(1<<4))
		{
			r--;
			_delay_ms(300);
			
		}
		
    /*   
		PORTB=0xE;PORTD=go[razr1];//Anod
		_delay_ms(1000);
		PORTB=0xD;PORTD=go[razr2]; //Anod
		_delay_ms(1000);
		PORTB=0xB;PORTD=go[razr3]; //Anod
		_delay_ms(1000);
*/
		
	}

}
