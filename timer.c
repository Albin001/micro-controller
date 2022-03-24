#include<pic18.h>
void delay(void);
#define led RD0
void main()
{
    TRISD=0x00;
    
    T0CON=0x87;
    TMR0H=0xFB;
    TMR0L=0x6C;
    while(1)
    {  
       
        
        LATD=0x00;
        delay();
        LATD=0xFF;
         delay();
    }
}
void delay(void)
{
    
        while(TMR0IF==0);
        TMR0IF=0;
         TMR0H=0xFB;
         TMR0L=0x6C;
        
        
}