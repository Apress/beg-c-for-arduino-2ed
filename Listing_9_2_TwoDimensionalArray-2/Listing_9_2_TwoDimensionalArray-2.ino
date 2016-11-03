/* Listing 9-2. Using  a two-dimensional array of chars

  Purpose: To illustrate the relationship between two-dimensional
    arrays and pointers.
    
    Dr. Purdum, December 20, 2014
  */
#define DAYSINWEEK 7
#define CHARSINDAY 10


void setup() 
{
  
static char days[DAYSINWEEK][CHARSINDAY] = 
     {"Sunday", "Monday", "Tuesday","Wednesday", 
      "Thursday", "Friday", "Saturday"};  
  
  int i, j;
  Serial.begin(9600);   // Serial link to PC
 
  for (i = 0; i < DAYSINWEEK; i++) {
    Serial.print((int) &days[i][0]);  // Show the lvalue
    Serial.print(" ");
    for (j = 0; days[i][j]; j++) {
      Serial.print(days[i][j]);    // Show each char
    }
    Serial.println();
  }
}

void loop() 
{
  

}


