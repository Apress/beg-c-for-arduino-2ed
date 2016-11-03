/* Listing 13-2. A Simple Interrupt Program  */
#include <avr/interrupt.h>

#define LEDPIN  13

volatile int state = LOW;

void setup() {

  DDRB = DDRB | B00100000;  // Set pin 6 of Port B to output, but...
                            // PORTB6 is digital pin 13
  PORTD |= (1 << PORTD2);   // turn On pin 2 of PORTD

  EICRA |= (1 << ISC00);    // set INT0 to trigger on ANY logic change
  EIMSK |= (1 << INT0);     // Turns on INT0

  sei();                    // turn on interrupts
}

void loop() {
  unsigned long i;
  unsigned long sum = 0;
  
  for (i = 0; i < 4000000; i++)  // Do this just to have 
    sum++;                       // something to interrupt!
}

ISR(INT0_vect)
{
  state = !state;               // Flip its state 
  digitalWrite(LEDPIN, state);  // interrupt code here 
}

