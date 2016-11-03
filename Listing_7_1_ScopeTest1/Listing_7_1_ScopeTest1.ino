/* Listing 7-1 Scope Test 1 */

#define MAXVAL 1000

void setup()
{
 int x = 5;
 Serial.begin(9600);
 if (x < MAXVAL) {
   int temp;

   temp = x * 100;
   Serial.print("The lvalue for temp is: ");
   Serial.println((long) &temp);
   Serial.print("The rvalue for temp is: ");
   Serial.println((long) temp);
  }
  int temp;
  
  Serial.print("The lvalue for 2nd temp is: ");
  Serial.println((long) &temp);
   Serial.print("The rvalue for temp is: ");
   Serial.println((long) temp);
}

void loop() {}
