/* Listing 13-1. Countdown LED Display.

  Program is a quick-count stopwatch. The code starts with zero and
  counts up from there. No protection rollover. Base code by Blair Thompson.
  
  Modified by Dr. Purdum, 12/26/2014
*/
#include <LedControl.h>    // From Arduino LedControl library

int DIN    = 10;
int LOADCS = 11;
int CLK    = 13;

int ledBrightness = 5;    // range is 0-15.  0=lowest, 15 = full power

// DIN, CLK, Load/CS, 8 digits
LedControl myLEDs = LedControl(DIN, CLK, LOADCS, 8); 
int hundredths0, hundredths1;
int seconds0, seconds1;
int minutes0, minutes1;
int hours0, hours1;

void setup()
{
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LOADCS, OUTPUT);

  myLEDs.shutdown(0, false);               // Wake 'em up
  
  Reset();
  myLEDs.setIntensity(0, ledBrightness  ); //set the brightness
}

void loop()
{
  BumpFrame();  // Bump the necessary display digits
}

/*****
  This function increments the hundredths of a second counter and
  rolls to the next digit as needed.
  
  Parameter List:
    void
    
  Return value:
    void
*****/
void  BumpFrame()
{
  delay(10);    // Count to 99 from 0 every second
  
  myLEDs.setDigit(0, 0, hundredths0++, false);  // Update last digit
  if (hundredths0 == 10) {
    hundredths1++;
    hundredths0 = 0;
  }
  if (hundredths1 < 9) {                        // Time to roll over?
    myLEDs.setDigit(0, 1, hundredths1, false);  // Nope
  } else {
    hundredths1 = 0;
    myLEDs.setDigit(0, 1, hundredths1, false);  // Yep
    BumpSeconds();
  }
}

/*****
  This function increments the seconds counter and
  rolls to the next digit as needed.
  
  Parameter List:
    void
    
  Return value:
    void
*****/
void  BumpSeconds()
{
  seconds0++;          // Bump the seconds count
  if (seconds0 == 10) {
    seconds1++;
    seconds0 = 0;
  }
  myLEDs.setDigit(0, 2, seconds0, true);     // update units 

  if (seconds1 < 6) {
    myLEDs.setDigit(0, 3, seconds1, false);  // Update tens
  } else {
    seconds1 = 0;
    seconds0 = 0;
    myLEDs.setDigit(0, 3, seconds1, false);  // Reset and update minutes
    BumpMinutes();
  }
}

/*****
  This function increments the minutes counter and
  rolls to the next digit as needed.
  
  Parameter List:
    void
    
  Return value:
    void
*****/
void  BumpMinutes()
{
  minutes0++;            // Works the same as seconds, only for minutes:
  if (minutes0 == 10) {
    minutes1++;
    minutes0 = 0;
  }
  myLEDs.setDigit(0, 4, minutes0, true); 

  if (minutes1 < 6) {
    myLEDs.setDigit(0, 5, minutes1, false);  
  } else {
    minutes1 = 0;
    minutes0 = 0;
    myLEDs.setDigit(0, 5, minutes1, false);  // Need to update hours
    BumpHours();
  }
}

/*****
  This function increments the hours counter and
  rolls to the next digit as needed.
  
  Parameter List:
    void
    
  Return value:
    void
*****/
void  BumpHours()
{
  hours0++;            // Works same as minutes...
  if (hours0 == 10) {
    hours1++;
    hours0 = 0;
  }
  myLEDs.setDigit(0, 6, hours0, true);

  if (hours1 < 6) {
    myLEDs.setDigit(0, 7, hours1, false); // Nothing left to bump, so reset
  } else {
    hours1 = 0;
    hours0 = 0;
    Reset();
  }
}

/*****
  This function resets the digits to zero
  
  Parameter List:
    void
    
  Return value:
    void
*****/
void Reset()
{
  myLEDs.setDigit(0, 0, 0, false);    
  for (int i = 1; i < myLEDs.getDeviceCount(); i++) {
    myLEDs.setDigit(0, i, 0, (i % 2 == 0) ? true : false); 
  }
}

