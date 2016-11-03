/* Listing 9-1. Using pointers.
 
 - Variant 3
 
 Purpose: Illustrate pointer arithmetic
 
 Dr. Purdum, Nov. 24, 2014
 */
#include <string.h>  
void setup() {                
  Serial.begin(9600);

  char buffer[50];
  char *ptr;
  int i;
  int length;

  strcpy(buffer, "When in the course of human events");

  ptr = buffer;
  length = strlen(buffer);		// How many chars in quote?
  Serial.print("The lvalue for ptr is: ");
  Serial.print((unsigned int)&ptr);
  Serial.print(" and the rvalue is ");
  Serial.println((unsigned int)ptr);
  while (*ptr) 
  {
    Serial.print(*ptr++);
  }
  // Added variants 2 and 3 

  ptr = buffer;	// Reset the pointer back to buffer[0]...
  Serial.println(""); 	// So the output prints on a new li
  for (i = 0; i < length; i++) 
  {
    Serial.print(*(ptr + i));
  }

}//END Setup


void loop() { 
}



