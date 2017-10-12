# Multiple Blink

## Tyler Brady

## Background
* The purpose of this lab was to create code capable of blinking more than one light on the board. The implemention for this lab
was done using timers as I wished to learn more about them before moving to the next lab. By setting up the timer using SMCLK, 
UP mode, and a divider of 8, the interrupt was set up in a way to set the frequency at 12.5Hz. This way the LEDs would be toggled
on and off at a rate of 1/12.5 seconds.

## Devices
* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

## Differences
* The main differences in code exist in differences between timer implementation, as some timers required different macros such as
TASSEL_1 or TASSEL__ACLK. The other major difference between codes was the different pins called in each program, as the led outputs
are different between boards.

## Extra work
* NONE