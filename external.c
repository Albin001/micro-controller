#include<reg51.h>
#define led P1
sbit led2=P2^0;
void delay(unsigned int d)
{
	while(d--);
}
void ex1() interrupt 0
{
  
	led2=!led2;

}
void ex2() interrupt 2
{
  
	led2 =0;
	led=0x00;

}
void main()
{
	led=0x00;
	led2=0x00;
	
	TCON=0x05;
	IE=0x85;
	while(1)
	{
	led =0x01;
	delay(5000);
	led=0x02;
	delay(5000);
	led=0x04;
	delay(5000);
	led=0x08;
	delay(5000);
	led =0x10;
	delay(5000);
	led=0x20;
	delay(5000);
	led=0x40;
	delay(5000);
	led=0x80;
	delay(5000);
	
	
	}
}