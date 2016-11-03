/* Listing 9-1. Using pointers.

 - Variant 2
 
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

  for (i = 0; i < length; i++) 
  {
    Serial.print(*(ptr + i));
  }

}//END Setup


void loop() { 
}


