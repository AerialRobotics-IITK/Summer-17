#include<Servo.h>
Servo quad;
int trigPin=12;
int echoPin=11;

long duration;
int distance;
int ch1;
int servopin=9;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(ch1,INPUT);
pinMode(servopin,OUTPUT);
quad.attach(servopin);
quad.writeMicroseconds(1100); 
Serial.begin(9600);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print(": ");
//Serial.println(distance);
     
  ch1 = pulseIn(5, HIGH, 25000); // Read the pulse width of 
ch1= constrain(ch1,1100,1920);
 
  Serial.println(ch1);
  if(distance>30)
  {
    quad.write(ch1);
    
  }
else if(distance<30)
{
  quad.write(1100);
}


  
}
