
#include<pic18.h>
#include<string.h>
#define rs RC0
#define e RC1
int counter1;
unsigned char a;
const unsigned char *a3;
unsigned char a1[4]="1234";
unsigned char a2[4];
char keypad(void);
void lcd_cmd(unsigned char cd);
void lcd_data(unsigned char data);
void lcd_display(const unsigned char *a5);
void delay(int count);
int i,j,j1;
void main()
{
    TRISD=0x00;
    TRISC=0x0C;
    ADCON1=0x0F;
    TRISB=0xF0;
    lcd_cmd(0x38);
    lcd_cmd(0x06);
    lcd_cmd(0x0E);
    lcd_cmd(0x80);
    lcd_cmd(0x01);
    while(1)
    {
        
        
        for(int j1=0;j1<4;j1++)
        {
           a2[j1]=keypad();
           lcd_data(a2[j1]);
           
        }
        
        while(keypad()!='*');
      
           counter1=0;
        
         for(int j1=0;j1<4;j1++)
        {
           
           if(a1[j1]==a2[j1])
           {
               counter1++;
           }
         }
                 
            if( counter1==4)
           {
               lcd_cmd(0xC0);
               lcd_display("Correct");    
           }
            else
            {
                lcd_cmd(0x01);
                lcd_cmd(0xC0);
                lcd_display("incorrect");
            }
           
        
        
      
}
}
void delay(int count)
{
    for(i=count;i>0;i--)
        for(j=count;j>0;j--);
}

void lcd_cmd(unsigned char cd)
{
    PORTD=cd;
    rs=0;
    e=1;
    delay(250);
    e=0;
    //delay(100);
}
void lcd_data(unsigned char data)
{
     
    PORTD=data;
    rs=1;
    e=1;
    delay(250);
    e=0;
    //delay(50);
}
char keypad(void)
{
    while(1)
    {
       
    PORTB=0X7E;
       a=PORTB & 0xF0;
       switch(a)
       {
           case 0X70:
               return '1';
               

            
            
       }
       PORTB=0xBE;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XB0:
           return '2';
           
       }
        PORTB=0xDE;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XD0:
           return '3';
          
       }
         PORTB=0xEE;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XE0:
           return '4';
       }
         PORTB=0x7D;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0X70:
            return '5';
           
       }
          PORTB=0xBD;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XB0:
           return '6';

       }
          PORTB=0xDD;
       a=PORTB & 0xF0;
       switch(a)
       {
           case 0XD0:
           
               return '7';
              
       }
          PORTB=0xED;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XE0:
         
           return '8';
           
             
       }
          PORTB=0x7B;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0X70:
          
           return '9';
            
       }
         PORTB=0xBB;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XB0:
        
           return '0';
          
       }
          PORTB=0xDB;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XD0:
           
           return 'A';
       }
          PORTB=0xEB;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XE0:
          
          return  'B';
           
       }
          PORTB=0x77;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0X70:
        
           return 'C';
       }
          PORTB=0xB7;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XB0:
        
           return 'D'; // to move the coursor  right 
        
       }
          PORTB=0xD7;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XD0:
         
           lcd_cmd(0x01);  // to move the cursor left with blinking
           break;
       }
          PORTB=0xE7;
       a=PORTB & 0xF0;
       switch(a)
       {
       case 0XE0:
           return '*' ;
    } 
    }
}

void lcd_display(const unsigned char *a5)
{
     while(*a5!=0)
    {
        lcd_data(*a5);
        a5++;
    }
}



