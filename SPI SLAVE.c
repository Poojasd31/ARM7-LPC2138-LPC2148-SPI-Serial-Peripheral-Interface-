#include<lpc214x.h>
#include "PLL.h"

#define led1 17
#define led2 18
#define sw1 14
#define sw2 15

#define sck 4
#define miso 5
#define mosi 6

void spi_init(void);
void tx(unsigned int);
char rx(void);

int main()
{
	char ch;
	PINSEL0=0x00005500;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;
	IODIR0=((1<<led1)|(1<<led2)|(0<<sw1)|(0<<sw2)|(0<<sck)|(0<<mosi)|(1<<miso));
	
	PLL_SET();
	spi_init();
	IOSET0=(1<<led1);
	IOSET0=(1<<led2);
	
	
	while(1)
	{
		ch=rx();
		if(ch=='A')
		{
			IOCLR0=(1<<led1);
			IOSET0=(1<<led2);
		}
		else if(ch=='B')
		{
			IOCLR0=(1<<led2);
			IOSET0=(1<<led1);
		}
	}
}
	


void spi_init()
{
	//S0SPCR=0x00000844;
	S0SPCR = 0x00000004;
	//S0SPCCR=8;
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
