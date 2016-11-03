/* Listing 7-4. Short Program with Error */

extern int number;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  number *= number;
  Serial.println(number);
}

