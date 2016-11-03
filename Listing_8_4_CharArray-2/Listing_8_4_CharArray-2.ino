/* Listing 8-4. Display character array.
 
 Purpose: Display a character array using array indexes
 
 Dr. Purdum, Nov 22, 2014
 */

void setup() {                
  char greet[6];
  int i;

  Serial.begin(9600);                   

  greet[0] = 'H';	// Initialize the array with some characters
  greet[1] = 'e';	// the slow way...
  greet[2] = 'l';
  greet[3] = 'l';
  greet[4] = 'o';
  greet[5] = '\0';	// null termination character 

  for (i = 0; i < 5; i++) {

    //    Serial.print(greet[i]);
    //    Serial.print(*(greet + i));    //Version 2
    Serial.print(*(greet + i * sizeof(char)));  // Version 3  
  }
}
void loop() {
}




