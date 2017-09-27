#include <msp430.h>


//MULTI_2553

void main(void)
{
     WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT0 + BIT6;   // configure P1.0 and P1.6 as an output.

    //TIMER CONFIG
    CCTL0 = CCIE; // CCR0 interrupt enabled
    TACTL = TASSEL_2 | MC_1 | ID_3; // SMCLK/8, upmode
    CCR0 = 10000; //Set at 12.5Hz
    _BIS_SR(CPUOFF + GIE); // Enter LPM0 w/ interrupt

    while(1)//INFINITE LOOP (Ensures the processor does nothing else.)
    {
    }
}

#pragma vector = TIMER0_A0_VECTOR //Creating timer B0 as an interupt vector
__interrupt void Timer_A (void)
{
    P1OUT ^= BIT0 + BIT6;// toggle P1.0 and P1.6
}
