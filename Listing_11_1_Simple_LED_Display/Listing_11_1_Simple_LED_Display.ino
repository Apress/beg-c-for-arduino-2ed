/* Listing 11-1. Simple  LED Display */

int ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11};
#define ARRAYLENGTH(x)  (sizeof(x) / sizeof(x[0]))

void setup()
{
  for (int i = 0; i < ARRAYLENGTH(ledPin); i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < ARRAYLENGTH(ledPin); i++)
  {
    digitalWrite(ledPin[i], HIGH);
    delay(500);
    digitalWrite(ledPin[i], LOW);
  }
}

