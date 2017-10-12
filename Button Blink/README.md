# Simple Blink

#Tyler Brady

##Background
*The purpose of this lab was to create code capable of making a LED on the board to blink. This could be done in a variety of ways, 
however since timers were still unknown at the time of writing, the actual implementation consisted of using methods to delay the
processor from progressing through the code, either by clogging it up with empty for loops, or the delay cycles command.

##Devices
*MSP430G2553
*MSP430FR2311
*MSP430FR5994
*MSP430FR6989
*MSP430F5529

##Differences
*The main differences in board's code was either in implementation, using either a for/while loop to delay the processor, 
or simply just using the delay cycles function built into the processor. While a smaller difference between boards was the pins used
as some boards used different pins to control the built in LEDs.

##Extra work
*The extra work performed in this lab can be found under the MSP430F5529. The work done was to create code where when the button
connected to Pin 1.1 was pressed, the speed at which the LED would blink would get faster until resetting back to base. This was done
using an interrupt to check when the button was pressed and a variable which would count states, moving between them as on the interrupts
trigger.