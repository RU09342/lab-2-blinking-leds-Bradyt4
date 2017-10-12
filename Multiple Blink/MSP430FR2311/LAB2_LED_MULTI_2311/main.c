#include <msp430.h>
/*
 *  MULTI LED 2311
 *
 *  Created on: Sept 20,2017
 *  Last Edited: Oct 11, 2017
 *      Author: Tyler Brady
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT0;   // configure P1.0 as an output.
    P2DIR |= BIT0;   // configure P2.0 as an output.

    PM5CTL0 &= ~LOCKLPM5;// Disable the GPIO power-on default high-impedance mode

    //TIMER CONFIG
    TB0CCTL0 = CCIE; // CCR0 interrupt enabled
    TB0CTL = TBSSEL__SMCLK | MC_1 | ID_3; // SMCLK/8, upmode
    TB0CCR0 = 10000; //Set at 12.5Hz
    _BIS_SR(CPUOFF + GIE); // Enter LPM0 w/ interrupt

    while(1)//INFINITE LOOP (Ensures the processor does nothing else.)
    {
    }
}

#pragma vector = TIMER0_B0_VECTOR //Creating timer B0 as an interupt vector
__interrupt void Timer_B (void)
{
    P1OUT ^= BIT0;// toggle P1.0
    P2OUT ^= BIT0;// toggle P2.0
}
