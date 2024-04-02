/*#define F_CPU 1000000UL
#include <avr/io.h>



int main(void)
{  DDRD =0xFF;
	PORTD=0x0;
	TCCR0=0x5;
	TCNT0=0;// 255    1000000/1024=976,5625: 1/976,5625=0,0010235../255= 0,261...
	
	
	while(1)
		{
			if(TCNT0==128)  //255/2=128==0,261/2=0,13..
			{
				PORTD=0x6;
			}
			if(TCNT0==255)  //255/2=128==0,261/2=0,13..
			{
				PORTD=0xFF;
			}
			
			
			}
		
}*/
#define F_CPU 1000000UL
#include <avr/io.h>
int z=0;


int main(void)
{  DDRD =0xFF;         //Timer0
	PORTD=0x0;
	TCCR0=0x5;
	TCNT0=0;// 255    1000000/1024=976,5625: 1/976,5625=0,0010235../255= 0,261...
	
	
	while(1)
	{if(TCNT0==255)
		{z++;
		TCNT0=0;
		}
		if(z==10)  //10 *0,261=2,61 sec
		{
			PORTD=0x6;
		}
		if(z==20)  //255/2=128==0,261/2=0,13..
		{
			PORTD=0xFF;
		}
		if(z>20)
		{
			z=0;
		}
		
		
	}
	
}

