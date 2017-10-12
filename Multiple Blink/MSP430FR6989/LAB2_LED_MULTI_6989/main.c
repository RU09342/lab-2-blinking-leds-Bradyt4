#include <msp430.h>

/*
 *  MULTI LED 6989
 *
 *  Created on: Sept 20,2017
 *  Last Edited: Oct 11, 2017
 *      Author: Tyler Brady
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT0;   // configure P1.0 as an output.
    P9DIR |= BIT7;   // configure P9.7 as an output.

    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;


    //TIMER CONFIG
    TA0CCTL0 = CCIE; // CCR0 interrupt enabled
    TA0CTL = TASSEL__SMCLK | MC__UP | ID_3; // SMCLK/8, upmode
    TA0CCR0 = 10000;
    __bis_SR_register(LPM0_bits + GIE); // Enter LPM0 w/ interrupt

    while(1)//INFINITE LOOP (Ensures the processor does nothing else.)
    {
    }
}

#pragma vector = TIMER0_A0_VECTOR //Creating timer A0 as an interrupt vector
__interrupt void Timer_A0 (void)
{
    P1OUT ^= BIT0;// toggle P1.0
    P9OUT ^= BIT7;// toggle P9.7
}
