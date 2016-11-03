/* Listing_4_2_AlternateBlink
  Alternate Blink
  Turns on one LED on for one second while the other is off, then reverses the 
  LEDs for 1 second, repeatedly.

  Dr. Purdum, Dec. 15, 2014
  */

  // Give each LED a name:
const int LED1 = 10;
const int LED2 = 11;	
long counter = 0;

// the setup routine runs once when you press reset or apply power:
void setup() {                
  pinMode(LED1, OUTPUT);    
  pinMode(LED2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (counter % 2 == 1) {
    digitalWrite(LED1, LOW);     // turn LED off by making the voltage LOW
    digitalWrite(LED2, HIGH);    // turn LED on (HIGH is the voltage level)
    delay(1000);                 // wait for a second
  }
  if (counter % 2 == 0) {
    digitalWrite(LED1, HIGH);    // turn LED on (HIGH is the voltage level)
    digitalWrite(LED2, LOW);     // turn LED off by making the voltage LOW
    delay(1000);                 // wait for a second
  }
  counter = counter + 1;
}

