
#include <Servo.h> 
 
Servo right;  // create servo object to control a servo 
Servo left;

const int trigPin = 11; // sets trigPin @pin 11
const int echoPin = 12; // sets echoPin @pin 12

int pos = 0;


int led = 2;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  right.attach(9); // attaches the servo on pin 9 to the servo 
  left.attach(7); // attaches the servo on pin 7 to the servo
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);  
}

void loop()
{
 
  int sensorValue = analogRead(A2); // read the input on analog pin 0:
  
  if (sensorValue> 400) {
  digitalWrite(led, HIGH);
  }

  if (sensorValue< 400) {
    digitalWrite(led, LOW);
  }
  
  /*
  // FIRST HALL
  for(pos = 0; pos <= 300; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    right.write(180);              // tell servo to go to position in variable 'pos' 
    left.write(0);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  // FIRST TURN
  for(pos = 0; pos <=60; pos += 1)     // goes from 180 degrees to 0 degrees 
  {                                
    left.write(0);              // tell servo to go to position in variable 'pos' 
    right.write(90);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  // SECOND HALL
  for(pos = 0; pos <=200; pos += 1)     // goes from 180 degrees to 0 degrees 
  {                                
    left.write(0);              // tell servo to go to position in variable 'pos' 
    right.write(180);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  // SECOND TURN
  for(pos = 0; pos <=60; pos += 1)     // goes from 180 degrees to 0 degrees 
  {                                
    left.write(90);              // tell servo to go to position in variable 'pos' 
    right.write(180);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  // THIRD HALL
  for(pos = 0; pos <= 300; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    right.write(180);              // tell servo to go to position in variable 'pos' 
    left.write(0);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 

  
  // THIRD TURN
  for(pos = 0; pos <=60; pos += 1)     // goes from 180 degrees to 0 degrees 
  {                                
    left.write(90);              // tell servo to go to position in variable 'pos' 
    right.write(180);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  */
      
  if (sensorValue> 400) {
  digitalWrite(led, HIGH);
  }

  if (sensorValue< 400) {
    digitalWrite(led, LOW);
  }
  
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                          
  Serial.print("Sensor Starting, ");
  long duration, inches, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);

    right.write(180);              // tell servo to go to position in variable 'pos' 
    left.write(0);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 

  
    
  int sensorValue = analogRead(A2); // read the input on analog pin 0:
    
  if (sensorValue> 400) {
  digitalWrite(led, HIGH);
  }

  if (sensorValue< 400) {
    digitalWrite(led, LOW);
  }  
  
}

loop; exit(0);

}


long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
} 
