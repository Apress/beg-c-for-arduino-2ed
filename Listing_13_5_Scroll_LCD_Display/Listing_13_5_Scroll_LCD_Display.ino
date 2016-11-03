/* Figure 13-4. Scroll LCD Display */

//#define DEBUG    // Uncomment if you want to add debug prints

#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads

#include <LiquidCrystal_I2C.h>
#define COLS      16
#define ROWS       2
#define PAUSE    500

// For the Yourduino I2C LCD display:
// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol

                      // Set the LCD I2C address
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
char msg1[] = "From: Jill";
char msg2[] = "We will meet for lunch at noon at the Twin Lakes Restaurant";


void setup() 
{
#ifdef DEBUG
  Serial.begin(9600);      // For debugging, if needed...
#endif
  lcd.begin(COLS, ROWS);   // init lcd for 16 chars 2 lines

}


void loop()
{
  int len;
  len = strlen(msg1);
  if (len > COLS) {        // Truncate From details if too long
    msg1[COLS] = '\0';
  }
  lcd.setCursor(0,0);      //Start at character 4 on line 0
  lcd.print(msg1);
  len = strlen(msg2);
  if (len <= COLS) {       // Second part short enough to fit?
    lcd.setCursor(1, 0);
    lcd.print(msg2);
  } else {
    ScrollDisplay(msg2, 1); // Need to scroll the message
  }
  delay(4000);
}

/*****
  The purpose of this function is to scroll a message across
  a line of the display.
  
  Parameter list:
    char msg[]        the message to scroll
    int row           the row for scrolling
    
  Return value:
    void
*****/
void ScrollDisplay(char msg[], int row)
{
  int i;
  int j;
  char window[COLS + 1];  // Enough room for message + null
  
  strncpy(window, msg, COLS);
  window[COLS + 1] = '\0';
  lcd.setCursor(0, row);        // Show first part...
  lcd.print(window);
  delay(PAUSE);
  
  j = COLS;
  do {
    for (i = 0; i < COLS - 1; i++) {  // Copy old part
      window[i] = window[i + 1];
    }
    window[i] = msg[j];               // Add new characcter
    lcd.setCursor(0, row);
    lcd.print(window);
    delay(PAUSE);
  }while (msg[++j]);
  
} 

