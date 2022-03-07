

// Program for LCD Interfacing with 8051 Microcontroller (AT89S52) 
#include<reg51.h>
#define display_port P2    //Data pins connected to port 2 on microcontroller
sbit rs = P3^3;  //RS pin connected to pin 2 of port 3
sbit rw = P3^4;  // RW pin connected to pin 3 of port 3
sbit e =  P3^5;  //E pin connected to pin 4 of port 3
sbit s2=P1^6;
sbit m1=P1^3;
sbit m2=P1^4;
void run(void)
{
	m1=1;
	m2=0;
}
void stop(void)
{
	m1=1;
	m2=1;
}
unsigned char flag=0;
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

void lcd_data(unsigned char disp_data)  //Function to send display data to LCD
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}
void lcd_str(const unsigned char*str ,unsigned char num)
{
	unsigned char i;
	for(i=0;i<num;i++)
	{
		lcd_data(str[i]);
	}
}

 void lcd_init()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    lcd_cmd(0x06);  // turn display ON, cursor blinking
    lcd_cmd(0x0c);  
	  lcd_cmd(0x01); // bring cursor to position 1 of line 1
    
}
void main()
{
	lcd_init();
while(1)
{
	lcd_cmd(0x01);
	if(s2==0)
	{
		stop();
		lcd_cmd(0x82);
		lcd_str("Pump" ,4);
		lcd_cmd(0xc3);
		lcd_str("OFF",3);
		msdelay(100);
	}

	else if(s2==1)
	{	
		run();
		lcd_cmd(0x01);
		lcd_cmd(0x82);
		lcd_str("Pump" ,4);
		lcd_cmd(0xc3);
		lcd_str("ON",2);
     msdelay(100);
}
}
}