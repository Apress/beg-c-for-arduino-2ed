/* Listing 8-2. Minimum and maximum temperature program.
 
 Purpose: find the minimum and maximum values of an array of 
 data values
 
 Dr. Purdum, Nov. 22, 2014
 */
#include <stdio.h>
#define READINGSPERDAY 24
#define VERYHIGHTEMPERATURE 200
#define VERYLOWTEMPERATURE -200

int todaysReadings[] = {
  62, 64, 65, 68, 70, 70, 71, 72, 74, 75, 76, 78,
  79, 79, 78, 73, 70, 70, 69, 68, 64, 63, 61, 59};

void setup() {                      
  int lowTemp;
  int hiTemp;
  int retVal;

  Serial.begin(9600); 

  Serial.println("=== Before function call:");
  Serial.print("The lvalue for lowTemp is: ");  
  Serial.print((long) &lowTemp, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) lowTemp, DEC);
  Serial.print("The lvalue for hiTemp is: ");  
  Serial.print((long) &hiTemp, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) hiTemp, DEC);

  retVal = CalculateMinMax(todaysReadings, &lowTemp, &hiTemp);

  Serial.println("=== After the function call:");
  Serial.print("The lvalue for lowTemp is: ");  
  Serial.print((long) &lowTemp, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) lowTemp, DEC);
  Serial.print("The lvalue for hiTemp is: ");  
  Serial.print((long) &hiTemp, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) hiTemp, DEC);
  Serial.println("\n");
}
void loop() {
} 

/*****
 * 	Purpose: Get the daily temperature reading (READINGSPERDAY) and 
 * 		set the minimum and maximum temperatures for the day.
 * 
 * 	Parameter list:
 * int temps[]                   the array of temperatures
 * 		int *minTemp		pointer to the minimum temperature value
 * 		int *maxTemp		pointer to the maximum temperature value
 * 
 * 	Return value:
 * 		int			the number of readings processed
 *****/
int CalculateMinMax(int temps[], int *minTemp, int *maxTemp)
{
  int j;
  *minTemp = VERYHIGHTEMPERATURE ;	// Make the min temp ridiculously high
  *maxTemp = VERYLOWTEMPERATURE;       // Make the max temp ridiculously low
  for (j = 0; j < READINGSPERDAY; j++) {
    if (temps[j] >= *maxTemp) {
      *maxTemp = temps[j];
    }
    if (temps[j] <= *minTemp) {
      *minTemp = temps[j];
    }
  }
  return j;
}


