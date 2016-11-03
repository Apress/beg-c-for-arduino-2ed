/* Listing 5-4. Using a while Loop to Find a Target Value */

int searchList[200];

void setup() {
  int index;
  int target = 5343;  		// Part number to find
  
  Serial.begin(9600);
  
  memset(searchList, 0, sizeof(searchList));  // Clear the array
  
  searchList[160] = target;  // Our target
  
  index = 0;                             // Expression1 of well-behaved loop
  
  while (true) {                         // Expression2 of well-behaved loop
    if (searchList[index] == target) {
      break;
    }
    index++;                             // Expression3 of well-behaved loop
  }

  Serial.print("Found target at index = ");  // Display result
  Serial.println(index);
}

void loop() {

}

