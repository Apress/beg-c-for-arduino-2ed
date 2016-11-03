/* Listing 3-1 Add Strings */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String firstName = "Jack ";
  String lastName = "Purdum";
  String fullName = firstName + lastName;
  Serial.println(fullName);
}
void loop() {}

