#include<reg51.h>
void delay(unsigned char count);
unsigned char i,j;
void main()
{
	P2=0X00;
	while(1)
	{
		P2=0xFD;
		delay(1000);
		P2=0x0D;
		delay(1000);
		P2=0xDB;
		delay(1000);
		P2=0xF3;
		delay(1000);
		P2=0x27;
		delay(1000);
		P2=0xB7;
		delay(1000);
		P2=0xBF;
		delay(1000);
		P2=0xE3;
		delay(1000);
		P2=0xFF;
		delay(1000);
		P2=0xE7;
		delay(1000);
	}
}
void delay(unsigned char count)
{
	for(i=count;i>0;i--)
	   for(j=count;j>0;j--);
}