/* Listing 3-2. A Program to Concatenate Character Arrays */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  char myName[12] = "Jack ";
  char lastName[] = "Purdum";
  strcat(myName, lastName);   // A standard library function to concatenate character arrays

  Serial.println(myName);
}
void loop() {}


