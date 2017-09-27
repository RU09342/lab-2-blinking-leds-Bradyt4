#include <msp430.h>

// SIMPLE BUTTON PRESS
void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
P1DIR |= 0x01; // Set P1.0 to output direction
P1OUT |= BIT1; // Set pull up resistor on P1.1
P1REN |= BIT1; // Enable pull up resistor on P1.1

while (1) // Infinite Loop
{
if ((BIT1 & P1IN)) // active low switch
{
P1OUT &= ~0x01; // if P1.3 is 1(not pressed),reset P1.0
}else
{
P1OUT |= 0x01; // else set P1.0
}
}
}
