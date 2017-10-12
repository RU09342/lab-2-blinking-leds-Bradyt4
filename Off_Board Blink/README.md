# Off Board Blink

## Tyler Brady

## Background
* The requirement for this part of the lab was to use the MSP430G2553 to power an off-board set up. This could only be done on the
G2553 since this is the only board capable of having its processor removed and used alone. The circuit design itself is simple 
with most the processors board being used to supply power, ground, test, and reset. This supplys a 3.3V supply power to the board,
a ground, and the ability to write to the processor without putting it onto the board. The code used was the 2553's multi blink.

## Usage
* In order to use this code the circuit pictured below within the GIF must be created and the 2553 proccessor removed and placed onto the board. If done correctly this code will blink
each LED.

## Devices
* This project was performed soley on the G2553 as it is the only removable processor.

## Extra work
* In this project the board was also tied to Test and Reset located on the board so that the code could be written onto the device
without placing the chip back into the board.

* ![Example Gif](https://github.com/RU09342/lab-2-blinking-leds-Bradyt4/blob/master/Off_Board%20Blink/Working.gif)

