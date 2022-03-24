
#include<pic18.h>
void delay(void);
void main()
{
    TRISD=0x00;
    T1CON=0xB1;
    TMR1H=0x85;    
    TMR1L=0xEE;
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
    
        while(TMR1IF==0);
         TMR1IF=0;
         TMR1H=0x85;
         TMR1L=0xEE;
        
        
}