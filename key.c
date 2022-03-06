#include<reg51.h>
sbit led1=P2^0;
sbit led2=P2^1;
#define keypad P1
void main(void)
{
	P2=0x00;
	while(1)
	{
		keypad=0x7F;
		if(keypad==0x7E)
		{
			led1=1;
		}
		else if(keypad==0x7D)
		{
			led2=1;
		}
		else if( keypad==0x7B)
		{
			led1=0;
			led2=0;
		}
}
	}