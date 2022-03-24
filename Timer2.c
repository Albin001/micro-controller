#include<pic18.h>
void delay(void);
void main()
{
    TRISD=0x00;
    T2CON=0x7F;
    TMR2=0xE2;
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
    while(TMR2IF==0);
    TMR2IF=0;
    TMR2=0xE2;
    
}