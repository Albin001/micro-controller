#include<pic18.h>
void delay(void);
int i;
void main()
{
    
    TRISD=0x00;
    T3CON=0xB1;
    TMR3H=0x85;
    TMR3L=0xEE;
    while(1)
    {
        LATD=0xFF;
        delay();
        LATD=0x00;
        delay();
    }
}
void delay(void)
{
    for(i=4;i>0;i--)
    {
        while(TMR3IF==0);
        TMR3IF=0;
        TMR3H=0x85;
        TMR3L=0xEE;
    }
}
