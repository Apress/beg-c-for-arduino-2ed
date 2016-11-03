/* Listing 8-4. Display character array.
 
 Purpose: Display a character array using array indexes
 
 Dr. Purdum, Nov 22, 2014
 */

void setup() {       
  Serial.begin(9600);     
  char greet[6];
  char *ptr;
  int i;
  
  greet[0] = 'H';
  greet[1] = 'e';
  greet[2] = 'l';
  greet[3] = 'l';
  greet[4] = 'o';
  greet[5] = '\0';
 

  Serial.print(greet);

}

void loop() {
}




