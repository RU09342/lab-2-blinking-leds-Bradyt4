#include <msp430.h>

// SIMPLE BUTTON PRESS 5994
void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
P1DIR |= BIT0 + BIT1; // Set P1.0 and 1.1 to output direction
P5OUT |= BIT6; // Set 1.3 as an in
P5REN |= BIT6; // Enable pull up resistor on P5.6

PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

while (1) // Infinite Loop
{
    if ((BIT6 & P5IN)) // active low switch
        {
        P1OUT &= ~(BIT0 + BIT1); // if P1.3 is 1(not pressed),reset P1.0 and P1.1
        }
    else
        {
        P1OUT |= BIT0 + BIT1; // else set P1.0 and P1.1
        }
}
}
