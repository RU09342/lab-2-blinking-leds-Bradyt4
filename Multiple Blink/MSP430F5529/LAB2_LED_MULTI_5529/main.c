#include <msp430.h>
/*
 *  MULTI LED 5529
 *
 *  Created on: Sept 20,2017
 *  Last Edited: Oct 11, 2017
 *      Author: Tyler Brady
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT0;   // configure P1.0 as an output.
    P4DIR |= BIT7;   // configure P4.7 as an output.

    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CTL = TASSEL_2 | MC_1 | ID_3; // SMCLK/8, upmode
    TA0CCR0 = 10000; //Set at 12.5Hz
    _BIS_SR(CPUOFF + GIE); // Enter LPM0 w/ interrupt

    while(1) //INFINITE LOOP
    {
    }
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
    P1OUT ^= BIT0;// toggle P1.0
    P4OUT ^= BIT7;// toggle P4.7
}
