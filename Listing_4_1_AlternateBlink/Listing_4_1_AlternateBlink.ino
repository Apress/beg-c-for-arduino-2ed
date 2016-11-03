/* Listing 4-1. Modified Blink Code
  Alternate Blink
  Turns on one LED on for one second while the other is off, then 
  reverses the LEDs for 1 second, repeatedly.
  Dr. Purdum, 11/13/2014
  */
// Given  each LED pin a name and don't let it be changed by the program:
const int LED1 = 10;
const int LED2 = 11;	

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin  as an output.
  pinMode(LED1, OUTPUT);     
  pinMode(LED2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(LED1, HIGH);   // turn LED on (HIGH is the voltage level )
  digitalWrite(LED2, LOW);    // turn LED off by making the voltage LOW
  delay(1000);                // wait for a second
  digitalWrite(LED1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LED2, HIGH);   // turn LED on (HIGH is the voltage level)
  delay(1000);                // wait for a second
}

