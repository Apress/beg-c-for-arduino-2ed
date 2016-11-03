/*Listing 10-2. Modified dot operator example.

  Purpose: To show the use of the dot operator
  
  Dr. Purdum, December 21, 2014
*/


struct servicePeople {
  int ID;
  char Name[20];
  char PW[10];
  long Phone;
} myServicePeople, yourServicePeople;

struct servicePeople SetPhoneNumber(struct servicePeople temp);   // New

void setup() {
  Serial.begin(9600);
  Serial.print("myServicePeople lvalue: ");
  Serial.print((int) &myServicePeople);
  Serial.print("  yourServicePeople lvalue: ");
  Serial.println((int) &yourServicePeople);
  yourServicePeople.ID = 205;
  Serial.print("myServicePeople.ID rvalue: ");
  Serial.print(myServicePeople.ID);
  Serial.print("  yourServicePeople.ID rvalue: ");
  Serial.println(yourServicePeople.ID);
//  myServicePeople = EmptyFunction(yourServicePeople);  // Changed
  myServicePeople = SetPhoneNumber(yourServicePeople);          // Changed  
  Serial.println("\nAfter assignment:\n");
  Serial.print("myServicePeople.ID rvalue: ");
  Serial.print(myServicePeople.ID);
  Serial.print("  yourServicePeople.ID rvalue: ");
  Serial.println(yourServicePeople.ID);
  Serial.print("A servicePerson structure takes ");
  Serial.print(sizeof(servicePeople));
  Serial.println(" bytes of storage.");
  Serial.print("myServicePeople.Phone rvalue: ");      // New
  Serial.print(myServicePeople.Phone);                 // New 
  
  
  Serial.println();
  Serial.print("yourServicePeople.Phone rvalue: ");  
  Serial.println(yourServicePeople.Phone);      

} 
void loop(){

}
// All lines below are new
struct servicePeople SetPhoneNumber(struct servicePeople temp)
{
  temp.Phone = 2345678;
  return temp;
}

