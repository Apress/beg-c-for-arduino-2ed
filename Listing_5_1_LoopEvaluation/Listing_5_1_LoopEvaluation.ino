/* Listing 5-1. Demonstrate Loop Evaluation */
void setup() {
  int k;
  
  Serial.begin(9600);
  
  for (k = 0, Serial.print("Exp1 k = "), Serial.println(k);  // Expression 1
       Serial.print("Exp2 k = "), Serial.println(k), k < 10; // Expression 2
       k++, Serial.print("Exp3 k = "),  Serial.println(k)) { // Expression 3

    Serial.print("In loop body, k squared = ");   // for Loop statement body   
    Serial.println(k * k);
    delay(1000);
  }
}

void loop() {}

