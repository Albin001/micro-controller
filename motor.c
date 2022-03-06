#include<reg51.h>
sbit m1=P2^0;
sbit m2=P2^1;
void delay(unsigned int count)
{
	
	while(count)
	{
		unsigned int i;
		i=115;
		while(i>0)
			i--;
		count--;
	}
}
void forward(void)
{
	m1=1;
	m2=0;
}
void stop(void)
{
	m1=1;
	m2=1;
}
void backward(void)
{
	m1=0;
	m2=1;
}
void main()
{
	P2=0x00;
	
	while(1)
	{
		
   forward();
		delay(2000);
		backward();
		delay(2000);
		stop();
		delay(2000);
		
 }
	}