typedef struct Students
{
  char name[20];
  int year;
  float gpa;
} STUDENTS;

void setup() {
  int i;

  Serial.begin(9600);

  STUDENTS myClass[20] = {
    {"Katie Mohr", 4, 3.30},
    {"John Purdum", 1, 3.30},
    {"Jane Holcer", 2, 3.80}
  };

  for (i = 0; i < sizeof(myClass) / sizeof(myClass[0]); i++) {
    Serial.print("Name: ");
    Serial.print(myClass[i].name);
    Serial.print("   Class: ");
    Serial.print(myClass[i].year);
    Serial.print("   gpa: ");
    Serial.println(myClass[i].gpa);
  }
}

void loop() {
}

