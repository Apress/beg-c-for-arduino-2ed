/* Listing 12-4. A program to test the Dates library routine */
#include <Dates.h>

Dates myDates;

void setup() {
  int i;
  Serial.begin(9600);
  
  for (i = 2000; i < 2016; i++) {
    Serial.print(i);
    Serial.print(" is ");
    if (myDates.IsLeapYear(i) == 0)
      Serial.print("not ");
    Serial.print("a leap year and Easter is on ");
    myDates.myEaster.year = i;
    myDates.GetEaster(&myDates);
    Serial.print(myDates.myEaster.easterStr);
    Serial.print("  ");
    Serial.print(myDates.myEaster.month);
    Serial.print("  ");
    Serial.print(myDates.myEaster.day);
    Serial.print(" ");
    Serial.println(myDates.myEaster.year);
  }
}
void loop() {}


