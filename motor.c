#include<reg51.h>
sbit m1=P2^0;
sbit m2=P2^1;
sbit m3=P2^2;
sbit m4=P2^3;
int i,j;
void start(void);
void delay(unsigned char count);
void stop(void);
void backward(void);
void left(void);
void right(void);
void main()
{
	while(1)
	{
		start();
		delay(2000);
		stop();
		delay(2000);
		backward();
		delay(2000);
		left();
		delay(2000);
		right();
		delay(2000);
	}
	
	
}

void start(void)
	{
		m1=1;
		m2=0;
		m3=1;
		m4=0;
	}
	void backward(void)
	{
		m1=0;
		m2=1;
		m3=0;
		m4=1;
	}
	void stop(void)
	{
		m1=1;
		m2=1;
		m3=1;
		m4=1;
	}
	void left(void)
	{
		m1=0;
		m2=0;
		m3=1;
		m4=0;
	}
	void right(void)
	{
		m1=1;
		m2=0;
		m3=0;
		m4=0;
	}
	
	void delay(unsigned char count)
	{
		for(i=count;i>0;i--)
		for( j=count;j>0;j--);
	}