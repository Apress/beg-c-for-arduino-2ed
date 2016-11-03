/* Listing 10-11. Using a typedef. */
typedef struct Students 
{
   char name[20];
   int year;
   float gpa;
} STUDENTS;

void setup() {
  Serial.begin(9600);

  STUDENTS myClass[20];
  strcpy(myClass[0].name, "Jack Purdum");
  myClass[0].year = 3;
  myClass[0].gpa = 3.99;  // Never liked psychology
  
  Serial.print("Name: ");
  Serial.print(myClass[0].name);
  Serial.print("   Class: ");
  Serial.print(myClass[0].year);
  Serial.print("   gpa: ");
  Serial.println(myClass[0].gpa);
}

void loop() {
}

