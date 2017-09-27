#include <msp430.h>

// SIMPLE BUTTON PRESS 6989
// Added in 2nd led function to be on when not pressed and off when pressed.

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
P1DIR |= BIT0; // Set P1.0 to output direction
P9DIR |= BIT7; // Set P9.7 to output direction

//Setting up pull-up resistor on the P1.1 so that the button grounds the circuit when on
//and enables the circuit when on.
P1OUT |= BIT1; // Set pull up resistor on P1.1
P1REN |= BIT1; // Enable pull up resistor on P1.1

// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings
PM5CTL0 &= ~LOCKLPM5;


while (1) // Infinite Loop
{
if ((BIT1 & P1IN)) // active low switch
{
P1OUT &= ~BIT0; // if P1.1 is 1(not pressed),reset P1.0
P9OUT |= BIT7; // if P1.1 is 1(not pressed), turn on P9.7
}else
{
P1OUT |= BIT0; // else set P1.0
P9OUT &= ~BIT7; // Disable P9.7
}
}
}
