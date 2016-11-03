/*
Now it's your turn to provide a solution to a programming problem. 
 Here's the problem. 
 Using the two LED circuit from Chapter 4, Figure 4-1, 
 write a program that calls a function named GetInput() 
 to acquire a single-digit number from the user via the Serial monitor. 
 The numeric value from the user has the following interpretation:
 
 0 = no LEDs lit
 1 = LED1 lit
 2 = LED2 lit
 3 = both LED1 and LED2 lit
 
 Any other entry by the user (i.e., “bad input”) 
 should keep the LEDs in whatever their current state is. 
 GetInput() has a function type specifier of int 
 and the only two values to be returned are 0 on “bad input” or 1 on “good input”. 
 Another function named LightLEDs() is used to turn the two LEDs on /off 
 according to the value entered by the user. 
 Other than setup() and loop(), 
 you can only use the two new functions mentioned above. 
 You are free to use any of the standard library functions.
 
 */

/*-----( Declare Constants and Pin Numbers )-----*/

#define DEBUG   // UNcomment this to turn off print statements
#define LED1  10
#define LED2  11

/*-----( Declare Variables )-----*/
int goodBadFlag;  // Was the input good or bad?
int LEDValue;

void setup()   /****** SETUP: RUNS ONCE ******/  
{  
  Serial.begin(9600);  // NOTE! Set Serial Monitor to "No Line Ending "
  // set pins  as outputs.
  pinMode(LED1, OUTPUT);     
  pinMode(LED2, OUTPUT);
}

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  goodBadFlag = GetInput(&LEDValue);

#ifdef DEBUG	
  Serial.println();
  Serial.print("flag = ");
  Serial.print(goodBadFlag);
  Serial.print("   LEDValue = ");
  Serial.print(LEDValue);
#endif

  LightLEDs(LEDValue);
}// End loop


/************* User written functions  (copied) ****************/

/*
 * This function is used to get a numeric value from the user via the 
 * Serial monitor. Valid input are the values 0 - 3.
 * 
 * Argument list:
 * int *which        the value entered by the user
 * 
 * Return value:
 * int               0 if the value is bad, 1 if good
 */

int GetInput(int *which)
{
  char c;
  int temp = -1;

  *which = temp;
  while (true) {
    if (Serial.available() > 0) {
      c = Serial.read();
      if (isdigit(c)) {      // If they entered a digit character
        temp = c - '0';      // Subtract ASCII zero from the digit character
        if (temp >= 0 && temp < 4) {  // Is the value within range?
          *which = temp;
          return 1;                // Yep, it's good
        }
      }
      return 0;                  // If we get here, it's bad input
    }
  }
}

/*
 * This function is used to illuminate the correct combinations of LED
 * according to the value of which
 * 
 * Argument list:
 * int combo     key for lighting LEDs: 1=none, 1=LED1, 2=LED2, 3=both
 * 
 * Return value:
 * void
 */

void LightLEDs(int combo)
{
  switch(combo) 
  {
  case 0:        // both off
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    break;
  case 1:        // 1 on, 2 off
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    break;
  case 2:        // 1 off, 2 on
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    break;
  case 3:        // both on
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    break;
  default:
    Serial.println("  !! Not valid: must be 0..3 ");
    break;
  }// End switch
  delay(250);   // Good if you type in 1230 <enter>  
}








