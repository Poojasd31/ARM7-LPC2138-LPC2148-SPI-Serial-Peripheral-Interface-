#include<lpc214x.h>
#include "PLL.h"

#define led1 17
#define led2 18
#define sw1 15
#define sw2 16

#define sck 4
#define miso 5
#define mosi 6

void spi_init(void);
void tx(unsigned int);
char rx(void);

int main()
{
	PINSEL0=0x00001500;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;
	IODIR0=((1<<led1)|(1<<led2)|(0<<sw1)|(0<<sw2)|(1<<sck)|(1<<mosi)|(0<<miso));
	
	PLL_SET();
	spi_init();
	IOSET0=(1<<led1);
	IOSET0=(1<<led2);
	
	while(1)
	{
		if(!(IOPIN0&(1<<sw1)))
		{
			tx('A');
			IOCLR0=(1<<led1);
			IOSET0=(1<<led2);
		}
		else if(!(IOPIN0&(1<<sw2)))
		{
			tx('B');
			IOCLR0=(1<<led2);
			IOSET0=(1<<led1);
		}
	}
	
}

void spi_init()
{
	//S0SPCR=0x000008E4;
	S0SPCR = 0x00000024; 
	//S0SPCCR=0x08;
	S0SPCCR=10;
}
void tx(unsigned int a)
{
	S0SPDR=a;
	while(!(S0SPSR&(1<<7)));
}
char rx()
{
	while(!(S0SPSR&(1<<7)));
	return S0SPDR;
}
