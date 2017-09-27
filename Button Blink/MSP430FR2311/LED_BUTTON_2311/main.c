#include <msp430.h>

// SIMPLE BUTTON PRESS
void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
P1DIR |= BIT0; // Set P1.0 to output direction
P1OUT |= BIT1; // Set 1.1 as an in
P1REN |= BIT1; // Enable pull up resistor on P1.1

PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

while (1) // Infinite Loop
{
    if ((BIT1 & P1IN)) // active low switch
        {
        P1OUT &= ~BIT0; // if P1.3 is 1(not pressed),reset P1.0
        }
    else
        {
        P1OUT |= BIT0; // else set P1.0
        }
}
}
