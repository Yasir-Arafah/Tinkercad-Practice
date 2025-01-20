#include<Servo.h>

Servo servo;

int sigPin =3;

int duration;
int distance;


void setup()
{
  servo.attach(2);
  Serial.begin(9600);
  servo.write(0);
  
}

void loop()
{
  pinMode(sigPin,OUTPUT);
  digitalWrite(sigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(sigPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(sigPin,LOW);
  
  pinMode(sigPin,INPUT);
  duration = pulseIn(sigPin,HIGH);
  
  distance = (0.034*duration)/2;

  Serial.println(distance);
  
  if(distance<100)
  {
    servo.write(90);

  }
  else
  {
     servo.write(0);
  }
}