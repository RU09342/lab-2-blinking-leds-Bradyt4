#include <msp430.h>


//MULTI_5994

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT0 + BIT1;   // configure P1.0 and P1.1 as an output.

    //TIMER CONFIG
    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CTL = TASSEL_2 | MC_1 | ID_3; // SMCLK/8, upmode
    TA0CCR0 = 10000;
    _BIS_SR(CPUOFF + GIE); // Enter LPM0 w/ interrupt

    while(1)//INFINITE LOOP (Ensures the processor does nothing else.)
    {
    }
}

#pragma vector = TIMER0_A0_VECTOR //Creating timer B0 as an interupt vector
__interrupt void Timer_A (void)
{
    P1OUT ^= BIT0 + BIT1;// toggle P1.0 and P1.1
}
