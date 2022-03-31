#include<pic18.h>
#define RS RC1
#define E RC2
#define led RC3
#define led1 RC4
void lcd_cmd(unsigned char cd);
void lcd_init(void);
int i,j;
void delay(unsigned int count);
void lcd_data(unsigned int data);
void main()
{
    unsigned int a,b,c,d;
    TRISD=0x00;
    TRISC=0x00;
    ADCON0=0x03;
    ADCON1=0x00;
    ADCON2=0x00;
    lcd_cmd(0x38);
    lcd_cmd(0x06);
    lcd_cmd(0x0F);
    lcd_cmd(0x01);
    lcd_cmd(0x80);
    while(1)
    {
    GODONE=1;
    while(GODONE==1);
    a=ADRESH;
    if(a>122)
    {
    b=((a/100)+48);
    lcd_data(b);
    c=((a%100)/10+48);
    lcd_data(c);
    d=((a%10)+48);
    lcd_data(d);
    lcd_cmd(0x01);
    led=1;
    led1=0;
    }
    else
    {
      b=((a/100)+48);
    lcd_data(b);
    c=((a%100)/10+48);
    lcd_data(c);
    d=((a%10)+48);
    lcd_data(d);
    lcd_cmd(0x01);
    led=0; 
    led1=1;
    }
    }
    
}
void lcd_cmd(unsigned char cd)
{
    PORTD=cd;
    RS=0;
    E=1;
    delay(100);
    E=0;
  
}
void lcd_data(unsigned int data)
{
    PORTD=data;
    RS=1;
    E=1;
    delay(150);
    E=0;
}
void delay(unsigned int count)
{
    for(i=count;i>0;i--)
        for(j=count;j>0;j--);
}
