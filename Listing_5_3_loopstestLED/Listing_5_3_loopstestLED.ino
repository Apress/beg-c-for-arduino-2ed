/* Listing 5-3. A for loop test program. */

#define LED_PIN 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int counter;
  
  for (counter = 0; counter < 1000; counter++) {
    if (counter % 2 == 0) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
    delay(500);
  }
}

