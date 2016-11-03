/* Listing 4-3. A switch example. */

char c;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter a letter A - F:");
}

void loop() 
{
  while (true) 
  {
    if (Serial.available() > 0) 
    {
      c = Serial.read();
      c = toupper(c);      // Make it upper case
      switch (c) 
      {
        case 'A':
          Serial.println("Great job");
          break;
        case 'B':      // Note fall-through here...
        case 'C':
          Serial.println("You passed");
          break;
        case 'D':
          Serial.println("You're on the edge");
          break;
        case 'F':
          Serial.println("See you again next semester.");
          break;
        default:
          Serial.println("You can't even follow instructions?");
          break;
      }// END switch
    }// END If Serial available
  }// END Always true
}// END Loop

