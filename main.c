/*
 Author: Jackson
 File: night rider
 Date: 04/10/24
 Description: This program performs the night rider LED with port B
 intended effect shown here https://www.youtube.com/watch?v=U_2VISCBFc8
 */

// attach LEDS to R(X) 0-7 to configure the circuit for usage


#include <xc.h>
#pragma config FOSC = HS // Oscillator Selection bits
#pragma config WDTE = OFF // Watchdog Timer Enable bit
#pragma config PWRTE = OFF // Power-up Timer Enable bit
#pragma config BOREN = ON // Brown-out Reset Enable bit
#pragma config LVP = OFF // Low-Voltage (Single-Supply)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit
#pragma config WRT = OFF // Flash Program Memory Write Enable bits
#pragma config CP = OFF // Flash Program Memory Code Protection bit
#define _XTAL_FREQ 20000000 //specify the crystal frequency as 20 MHz

// Define pointers to registers
volatile unsigned char *PORTB_Ptr = &PORTB;


// Function to turn on given current user-defined LED,
// Turns off previous user-defined LED, and the user-defined amount of delay

void ledChoice(int rbCurr, int rbPrev) { 
    *PORTB_Ptr &= ~(1 << rbPrev); // Clear previous LED using bitmask with all bits set to 1 except the corresponding bit
    *PORTB_Ptr |= (1 << rbCurr); // Set current LED
    __delay_ms(50); // Delay
}

// this is the main function; it executes the sequence order of the LEDs in order 

void main(void) { 
    TRISB = 0x00; //set the PORTB pins as output by setting TRISB to 0
    PORTB = 0x00; //Make all output of RB0 low by setting all bits to 0
    int sequence[] = {0,1,2,3,4,5,6,7};// LED sequence is defined as an array so that it may be referenced by the function
    int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);
   
    // Loop through the given  sequence using the modulus operator
    while (1) { // Infinite loop
        // Forward sequence
        for (int i = 0; i < sequenceLength; i++) {
            ledChoice(sequence[i], sequence[(i - 1 + sequenceLength) % sequenceLength]);
	
        }
        // Backward sequence
        for (int i = sequenceLength - 2; i >= 0; i--) {
            ledChoice(sequence[i], sequence[(i + 1) % sequenceLength]);
        }
    }
}
