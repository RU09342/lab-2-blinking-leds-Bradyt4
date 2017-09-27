//BUTTON PRESS CHANGE SPEED (TIMER ISSUES?) *NEEDS INTERUPT IMPLEMENTATION
#include <msp430.h>
void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
TA0CCTL0 = CCIE; // CCR0 interrupt enabled
TA0CTL = TASSEL_2 | MC_1 | ID_3; // SMCLK/8, upmode
TA0CCR0 = 0;                            //No downtime
P1DIR |= 0x01; // Set P1.0 to output direction
P1OUT |= BIT1; // Set pull up resistor on P1.1
P1REN |= BIT1; // Enable pull up resistor on P1.1

P1IE |= BIT1;                   // P1.1 interrupt enabled
P1IES |= BIT1;                  // P1.1 Hi/lo edge
P1IFG &= ~BIT1;                 // P1.1 IFG cleared

_BIS_SR(CPUOFF + GIE);          // Enter LPM0 w/ interrupt

while (1) // Infinite Loop
{}
}


// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
   P1OUT ^= BIT0;                          // Toggle P1.0
}

unsigned int x = 0;
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    __delay_cycles(100000)
    switch(x)
    {
    case(0):
        TA0CCR0 = 10000;
        x++;
        break;
    case(1):
        TA0CCR0 = 20000;
        x++;
        break;
    case(2):
        TA0CCR0 = 30000;
        x++;
        break;
    case(3):
        TA0CCR0 = 0;
        x=0;
        break;
    }
P1IFG &= ~BIT1; //Trying to correct button bounce.


}
