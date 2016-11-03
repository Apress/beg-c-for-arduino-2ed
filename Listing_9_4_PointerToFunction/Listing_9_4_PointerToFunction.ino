/* Listing 9-4. Using a Pointer to Function 

  Purpose: Show how to use a pointer to function
    
    Dr. Purdum, December 21, 2014
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int number = 50;
  int (*funcPtr)(int n);  // This defines a pointer to function

  funcPtr = DisplayValue;  // This copies the lvalue of DisplayValue
  number = (*funcPtr)(number);
  Serial.print("After return from function, number = ");
  Serial.println(number);
  Serial.flush();
  exit(0);
}

int DisplayValue(int val)
{
  Serial.print("In function, val = ");
  Serial.println(val);
  return val * val;
}

