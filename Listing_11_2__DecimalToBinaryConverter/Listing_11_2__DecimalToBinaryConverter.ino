/*  Listing 11-2. Decimal to Binary Converter  */

int ledPin[] = {4,5,6,7, 8,9,10,11};

#define ARRAYLENGTH(x)  (sizeof(x) / sizeof(x[0]))

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < ARRAYLENGTH(ledPin); i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() 
{
  char buff[4];
  int charsRead;
  int val;
  
  if (Serial.available() > 0) {
    charsRead = Serial.readBytesUntil('\n', buff, 3);
    buff[charsRead] = '\0';
    val = atoi(buff);
    if (val > -1 && val < 256) {
      DisplayBinaryDigit(val);
    }
  }
}

void DisplayBinaryDigit(byte num)
{
  for (int i = 0;i < ARRAYLENGTH(ledPin);i++)
  {
    if (bitRead(num, i) == 1) {
      digitalWrite(ledPin[i], HIGH);
    } else {
      digitalWrite(ledPin[i], LOW);
    }
  }
}


