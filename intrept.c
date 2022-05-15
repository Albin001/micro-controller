#include<reg51.h>
#define led P2
sbit rs=P1^0;
sbit e=P1^1;
void lcd_cd(unsigned char cd);
void lcd_data(unsigned char data1);
void delay(unsigned char count);
unsigned char i,j;
unsigned char count;
void int1() interrupt 0
{
	count++;
}
void main()
{
	lcd_cd(0x38);
	lcd_cd(0x06);
	lcd_cd(0x0E);
	lcd_cd(0x80);
	lcd_cd(0x01);
	TCON=0x01;
	IE=0x81;
	while(1)
	{
	led=count;
	lcd_data(count + 48);
	delay(1000);
	lcd_cd(0x01);
	}
}
void lcd_cd(unsigned char cd)
{
	P2=cd;
	rs=0;
	e=1;
	delay(100);
	e=0;
}
void lcd_data(unsigned char data1)
{
	P2=data1;
	rs=1;
	e=1;
	delay(100);
	e=0;
}
void delay(unsigned  char count)
{
	for(i=count;i>0;i--)
	for(j=count;j>0;j--);
}
