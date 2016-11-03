/* Listing 14-5. Using the Dates Library */
#include "Dates.h"

Dates myDates;          // This calls the default constructor 

void setup() {
  int i;
  int total;

  Serial.begin(9600);
//Dates myDates;        // Default constructor, no initializer 
//Dates myDates(2015);  // Constructor with initializer

  for (i = 2000; i < 2017; i++) {
    Serial.print(i);
    Serial.print(" is ");
    if (myDates.IsLeapYear(i) == 0) {
      Serial.print("not ");
    }
    Serial.print("a leap year, Easter is on: ");
    myDates.myEaster.year = i;
    myDates.GetEaster(&myDates);
    total = myDates.julian(3, 5, i);
    Serial.print(myDates.myEaster.easterStr);
    Serial.print("  jullian days to May 3: ");
    Serial.println(total);
  }
}
void loop() {}

