/*Listing 8-3. Modified Blink program.
 
 Blink  by Scott Fitzgerald
 
 Modified by:
 Dr. Purdum, 12/19/2014
 */

#define LED   13

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED, OUTPUT);
}


/*****
 * Purpose: To blink the onboard LED using a pointer
 * 
 * Parameter List:
 * int pin            the pin attached to the LED
 * int *whichState    a pointer to the state variable back in loop()
 * 
 * Return value:
 * n/a
 *****/
void  BlinkLED(int pin, int *whichState)
{
  digitalWrite(pin, *whichState);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  *whichState = !(*whichState);     // Change state 
}

void loop() {
  static int state = HIGH;          // State of LED

  BlinkLED(LED, &state);            // Call function

}


