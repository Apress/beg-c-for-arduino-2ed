/*  Listing 13-4. Ultrasound Sensor Program
  Code is taken from 
     http://www.arduino.cc/en/Tutorial/Ping
  and was written by David Mellis and modified
  by Tom Igoe.

  Modified by Dr. Purdum for sound speed at
  72 degrees F.
  1/2/2105
*/

int triggerPin = 8;
int echoPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  long roundTrip;
  float cm;
  
  digitalWrite(triggerPin, LOW); // Trigger a short low pulse 
  delayMicroseconds(2);          // before the HIGH pulse
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  roundTrip = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(roundTrip);
  float inch = cm / 2.54;         // Figure out inches
  Serial.print(cm);
  Serial.print(" cm or ");
  Serial.print(inch);
  Serial.print(" inches");
  Serial.println();
  delay(1000);
} 
/*****
  This function calculates how far the pulse travels to
  strike and object and return. The air temp is assumed
  to be 72F.
  
  Parameter list:
    long microseconds    the time of the pulse
    
  Return value:
    float                centimeters to and from target
    *****/
float microsecondsToCentimeters(long microseconds){
  return (microseconds*0.034495)/2;
}

