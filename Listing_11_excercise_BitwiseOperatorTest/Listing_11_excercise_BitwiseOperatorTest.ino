/*
  Bitwise operator test. The user can test the AND, 
  OR, XOR, and NOT bitwise operators. The user enters 
  test data using the Serial monitor in the form:
 2,8,64
 
    TestToPerform,Operand1,Operand2
   
   As it stands, the comman operator separates fields
   in the input stream
   
   Dr. Purdum, December 24, 2014
*/ 
  
  
#define AND  1
#define OR   2
#define XOR  3
#define NOT  4

#define COMMA  ","    // Used to separate input arguments

int ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11};
#define ARRAYLENGTH(x)  (sizeof(x) / sizeof(x[0]))
int GetBitwiseTestParameters(int *which, int *op1, int *op2);

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < ARRAYLENGTH(ledPin); i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
  Serial.println("Bitwise Operators: 1 = AND, 2 = OR, 3 = XOR, and 4 = NOT");
  Serial.println("Enter Bitwise Operator COMMA Operand1 COMMA Operand2");
}

void loop()
{
  int whichTest = 0;
  int operand1;
  int operand2;

  GetBitwiseTestParameters(&whichTest, &operand1, &operand2);
  if (whichTest != 0) {
    ShowTest(whichTest, operand1, operand2);
    whichTest = operand1 = operand2 = 0;
  }
}

/***** 
  This function applies the operands and bitwise operator and displays
  the results
  
  parameter list:
    int which      which bitwise operation to use
    int op1        first operand
    int op2        second operand
    
  Return value:
    void
*****/
void ShowTest(int which, int op1, int op2)
{
  byte result;
  
  switch (which) 
  {
    case AND:  
      result = op1 & op2;
      break;
    case OR:
      result = op1 | op2;
      break;
    case XOR:
      result = op1 ^ op2;
      break;
    case NOT:
      result = ~op1;
     break;
    default:
      break;
  }
  DisplayBinaryDigit((byte) op1);
  delay(1000);
  DisplayBinaryDigit((byte) op2);
  delay(1000);
  DisplayBinaryDigit(result);
    
}
/***** 
  This function takes the string entered by the user via the
  Serial monitor and parses it into its relevant parts
  
  parameter list:
    int *which      pointer to which bitwise operation to use
    int *op1        pointer to first operand
    int *op2        pointer to second operand
    
  Return value:
    void
*****/
int GetBitwiseTestParameters(int *which, int *op1, int *op2)
{
  char buff[10];
  char *ptr;
  int charsRead;
  int temp;
  
  if (Serial.available() > 0) {
    charsRead = Serial.readBytesUntil('\n', buff, 9);
  }
  if (charsRead > 9) {
    return 0;          // Too many characters
  }
  buff[charsRead] = NULL;  // Make into a string
  ptr = strtok(buff, COMMA);
  *which = atoi(buff);
  ptr = strtok(NULL, COMMA);
  *op1 = atoi(ptr);
  ptr = strtok(NULL, COMMA);  
  *op2 = atoi(ptr);  
}

/***** 
  This function displays a byte value as a binary number
  on the LEDs.
  
  parameter list:
    int num      the value to display
    
  Return value:
    void
*****/
void DisplayBinaryDigit(byte num)
{
  for (int i = 0; i < ARRAYLENGTH(ledPin); i++)
  {
    if (bitRead(num, i) == 1) {
      digitalWrite(ledPin[i], HIGH);
    } else {
      digitalWrite(ledPin[i], LOW);
    }
  }
}


