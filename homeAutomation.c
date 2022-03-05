#include<reg51.h>
unsigned char mybyte;
sbit led1=P2^0;
sbit led2=P2^1;
sbit led3=P2^2;
sbit led4=P2^3;
void main(void)
{
	P2=0x00;
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	while(1)
	{
		while(RI==0);
		mybyte=SBUF;
		if(mybyte=='A')
		{
			led1=1;
			
	   }
		else if(mybyte=='a')
		{
			led1=0;
		}
		else if(mybyte=='B')
		{
			led2=1;
		}
		else if(mybyte=='b')
		{
			led2=0;
		}
		else if(mybyte=='C')
		{
			
			led3=1;
		
		}
		else if(mybyte=='c')
		{
			led3=0;
		}
		else if(mybyte=='D')
		{
			led4=1;
		}
		else if(mybyte='d')
		{
			led4=0;
		}
		
		RI=0;
}
	}