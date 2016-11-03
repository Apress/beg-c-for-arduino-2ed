/* Random Number Match
 - WHAT IT DOES: Loops while:
 - Generate random number 0..4999
 - Looks for match with Target
 - If Match, blink "Found" LED
 - increment an int counter
 - when int counter overflows:
   - blink "Recycle LED"
   - Reset int counter = 0
   - increment Recycle counter
 - When Recycle counter = 5, END
 
 - SEE the comments after "//" on each line below
 - CONNECTIONS:
 - "FOUNDIT_PIN" LED and resistor on pin 10
 - "RECYCLE_PIN" LED and resistor on pin 11
 - V1.05 02/23/2015
 Questions: terry@yourduino.com */

/*-----( Import needed libraries )-----*/
//None
/*-----( Declare Constants and Pin Numbers )-----*/
#define MAX 5000L
#define MIN 0L
#define TARGETVALUE 2500L

#define MAXRECYCLES 5
#define PAUSE 1000

#define FOUNDIT_PIN  10	// Green LED
#define RECYCLE_PIN  11	// Red LED


/*-----( Declare objects )-----*/
//None
/*-----( Declare Variables )-----*/
int  analogValueForRandomSeed;
long randomNumber;
int recycleCounter = 0;
int counter = 0;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  Serial.println("Find target among Random numbers");
  pinMode(FOUNDIT_PIN, OUTPUT);     
  pinMode(RECYCLE_PIN, OUTPUT);
  analogValueForRandomSeed = analogRead(A0); 
  Serial.print  ("Analog Value used to seed Random = ");  
  Serial.println(analogValueForRandomSeed, DEC);  
  Serial.println(); 
  randomSeed(analogValueForRandomSeed);

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  while (counter != -1)
  {
    randomNumber = generateRandomNumber();
    if (randomNumber == TARGETVALUE) 
    {
      Serial.print("Counter = ");
      Serial.print(counter, DEC);
      Serial.print("  Recycles = ");
      Serial.println(recycleCounter, DEC);
      digitalWrite(FOUNDIT_PIN, HIGH);
      delay(PAUSE);
      digitalWrite(FOUNDIT_PIN, LOW);
    }//TargetValue
    
    counter++;
    
    if (counter < 0)  // We've overflowed the int
    {       
      counter = 0;
      recycleCounter++;
      Serial.print("int overflow beyond 32767. Recycles = ");
      Serial.println(recycleCounter, DEC);
      digitalWrite(RECYCLE_PIN, HIGH);
      delay(PAUSE);
      digitalWrite(RECYCLE_PIN, LOW);
    }//Overflow

    if (recycleCounter == MAXRECYCLES) 
    {
      FakeAnEnd();                    // End program
    }
    
  }//While Counter

}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//-----------------------
long generateRandomNumber()
{
  return random(MIN, MAX);     // Generate random numbers 0 and 5000
}

//-------------------------------------------------
void FakeAnEnd() 
{	// Fake the end of the program 
  Serial.print("*** THE END ***");
  while (true) 
  {
  }
}


//*********( THE END )***********



