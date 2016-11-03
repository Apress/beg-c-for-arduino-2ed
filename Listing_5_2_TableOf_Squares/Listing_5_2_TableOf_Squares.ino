/* Listing 5-2. Table of Squares */

#define MAXLOOP 10

void setup() {
  int squares[MAXLOOP];
  int counter;
  
  Serial.begin(9600);
  // Construct the list
  for (counter = 0; counter < MAXLOOP; counter++) {
    squares[counter] = counter * counter;
  }
  // Display the list
  for (counter = 0; counter < MAXLOOP; counter++) {
    Serial.println(squares[counter]); 
  }  
}

void loop() {
}

