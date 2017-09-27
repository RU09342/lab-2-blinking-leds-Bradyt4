#include <msp430.h>

// SIMPLE BUTTON PRESS
void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
P1DIR |= BIT0 + BIT6; // Set P1.0 and 1.6 to output direction
P1OUT |= BIT3; // Set 1.3 as an in
P1REN |= BIT3; // Enable pull up resistor on P1.3

while (1) // Infinite Loop
{
    if ((BIT3 & P1IN)) // active low switch
        {
        P1OUT &= ~(BIT0 + BIT6); // if P1.3 is 1(not pressed),reset P1.0
        }
    else
        {
        P1OUT |= BIT0 + BIT6; // else set P1.0
        }
}
}
