/* Listing 7-3. Using the static Storage Class. */
void setup() {
  Serial.begin(9600);
}

void loop() {
  while (true) {
    Serial.println(MyCounter());
  }  
}

int MyCounter()
{
   static int counter = 0;
   // do some stuff...
   return ++counter;
}

