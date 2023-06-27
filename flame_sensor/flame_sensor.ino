const int flamePin = 4;
int Flame = HIGH;
int led = 2;

void setup() 
{  
  pinMode(led, OUTPUT);
  
  pinMode(flamePin, INPUT);
  serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame == LOW)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
