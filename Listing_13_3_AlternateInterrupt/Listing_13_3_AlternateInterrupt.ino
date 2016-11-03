/* Listing 13-3. Alternative Interrupt Program */
#include <avr/interrupt.h>

#define LEDPIN  13

volatile int state = LOW;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  
  attachInterrupt(0, myISR, CHANGE);
  sei();                    // turn on interrupts
}

void loop() {
  unsigned long i;
  unsigned long sum = 0;
  
  for (i = 0; i < 4000000; i++)  // Do this just to have 
    sum++;                       // something to interrupt!
}

void myISR()
{
  state = !state;
  digitalWrite(LEDPIN, state);/* interrupt code here */
}

