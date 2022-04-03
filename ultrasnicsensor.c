#include<reg51.h>
#include<intrins.h>
#include<math.h>
sfr16 DPTR=0x82;
sbit trig=P3^3;
sbit echo=P3^2;
sbit E=P3^7;
sbit rs=P3^6;
sbit l1=P1^0;
int i,j;
#define data1 P2
unsigned int range=0;
void send_pulse(void);
unsigned char ultrasonic();
void lcd_cmd(unsigned char cd);
void delay(unsigned char count);
void lcd_data(unsigned int);
void main()
{
	TMOD=0x09;
	TH0=0;
	TL0=0;
	TR0=1;
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0E);
	lcd_cmd(0x82);
	lcd_cmd(0x01);
	P3|=(1<<2);
	while(1)
	{
		range=ultrasonic();
		lcd_data((range/100)+48);
		lcd_data(((range/10)%10)+48);
		lcd_data((range%10)+48);
		delay(200);
		if(range>7)
		{
			l1=1;
		}
		else
		{
			l1=0;
		}
		lcd_cmd(0x01);

	}
}
void send_pulse(void)
{
	TH0=0x00;TL0=0x00;
	trig=1;
	_nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	_nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	trig=0;
}
unsigned char ultrasonic()
{
	unsigned char dataD;
	send_pulse();
	while(INT0==0);
	while(INT0==1);
	DPH=TH0;
	DPL=TL0;
	TH0=0xFF;
	TL0=0xFF;
	if(DPTR<38000)
	{
		dataD=DPTR/59;
	}
	else
	{
		dataD=0;
	}
	return dataD;
}
void lcd_cmd(unsigned char cd)
{
	data1=cd;
	rs=0;
	E=1;
	delay(50);
	E=0;
}
void lcd_data(unsigned int d1)
{
	data1=d1;
	rs=1;
	E=1;
	delay(50);
	E=0;
}
void delay(unsigned char count)
{
	for(i=count;i>0;i--)
	   for(j=count;j>0;j--);
}
