/*
  Purpose: Simple program to demonstrate using a pointer
 
 Dr. Purdum, Nov 22, 2014
 
 Result: UNO
 The lvalue for ptrNumber is: 2288 and the rvalue is 26880
 The lvalue for number is: 2286 and has an rvalue of 10
 
 Result: Mega
 The lvalue for ptrNumber is: 8686 and the rvalue is -22528
 The lvalue for number is: 8684 and has an rvalue of 10
 
 
 */
#include <stdio.h>
int counter = 0;
int k;

void setup() {                
  int number = 5;
  int *ptrNumber;

  Serial.begin(9600);   

  Serial.print("The lvalue for ptrNumber is: ");  
  Serial.print((long) &ptrNumber, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) ptrNumber, DEC);

  //=== Put new statements here!
  ptrNumber = &number;
  *ptrNumber = 10;

  // More added here 2
  ptrNumber = &number;
  *ptrNumber = 10;
  k = *ptrNumber;



  Serial.print("The lvalue for number is: ");  
  Serial.print((long) &number, DEC);
  Serial.print(" and has an rvalue of ");
  Serial.println((int) number, DEC);

  // added 2 
  Serial.print("The rvalue for k is: ");
  Serial.println(k, DEC);


}
void loop() {
}




