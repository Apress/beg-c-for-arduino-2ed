/* Listing 12-2. The Dates.h header file (Modified in Chapter 14 to add Julian )

  Dates.h - Library for finding is a year is a leap year
       and the date for Easter for a given year.
  Created and modified by: Dr. Jack Purdum, Dec. 25, 2014
  Released into the public domain.
*/
#ifndef Dates_h          // If we haven't read this file before...
  #define Dates_h        // ...read it now. This prevents double-including

  #include "Arduino.h"   // Not needed for our code, but often included
  
  class Dates
  {
  
    private:
      char today[4];            // Hold string for day of week
	  
    public:
      #define ASCIIZERO 48     // character for 0 in ASCII
	  



    struct easter {
      int month;
      int day;
      int year;
      int leap;
      char easterStr[11];
    };
    struct easter myEaster;
                                // Function prototypes:
    int IsLeapYear(int year);
    void GetEaster(Dates *myEaster);
    char * DayOfTheWeek(int day, int month, int year);
    char *GetDayOfWeek();
    int julian(int day, int month, int year);  // New method
        
  };
#endif     // Don't forget this!

