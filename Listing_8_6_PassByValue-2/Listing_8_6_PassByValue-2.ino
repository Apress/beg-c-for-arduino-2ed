/*  Listing 8-6. Pass-by-Value
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int number = 10;
  
  Serial.print("lvalue for number is ");
  Serial.print((int) &number);
  Serial.print(" rvalue for number is ");
  Serial.println(number);
//  SquareIt(number);
  SquareIt(&number);  // Variation 2
  Serial.print("After call: rvalue for number is ");
  Serial.println(number);
 
}

void loop() {}

void SquareIt(int *temp)
{
  Serial.print("In SquareIt(), lvalue for temp is ");
  Serial.print((int) &temp);
  Serial.print("  rvalue for temp is ");
  Serial.println((int) temp);
  *temp = *temp * *temp;
  Serial.print("The new rvalue for temp is ");
  Serial.println(*temp);
}
/*  Version 1 

void SquareIt(int temp)
{
  Serial.print("In SquareIt(), lvalue for temp is ");
  Serial.print((int) &temp);
  Serial.print("  rvalue for temp is ");
  Serial.println(temp);
  temp *= temp;
  Serial.print("The new rvalue for temp is ");
  Serial.println(temp);
}
*/

