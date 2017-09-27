#include <msp430.h>


//MULTI_5994

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT0 + BIT1;   // configure P1.0 and P1.1 as an output.

    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    //TIMER A0 CONFIG
    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CTL = TASSEL__SMCLK  | MC__UP | ID_3; // SMCLK/8, upmode
    TA0CCR0 = 20000;
    //TIMER A1 CONFIG
    TA1CCTL0 = CCIE; // CCR0 interrupt enabled
    TA1CTL = TASSEL__SMCLK  | MC__UP | ID_3; // SMCLK/8, upmode
    TA1CCR0 = 50000;
    _BIS_SR(CPUOFF + GIE); // Enter LPM0 w/ interrupt



    while(1)//INFINITE LOOP (Ensures the processor does nothing else.)
    {
    }
}

#pragma vector = TIMER0_A0_VECTOR //Creating timer A0 as an interrupt vector
__interrupt void Timer0_A (void)
{
    P1OUT ^= BIT0;// toggle P1.0
}
#pragma vector = TIMER1_A0_VECTOR //Creating timer A1 as an interrupt vector
__interrupt void Timer1_A (void)
{
    P1OUT ^=  BIT1;// toggle P1.1
}
