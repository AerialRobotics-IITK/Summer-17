#include <Servo.h>
Servo test1;
Servo test2;

int distance;

int servo1=9;
int servo2=10;
int led = 11;


const int trigPin = 12;
const int echoPin = 13;

long duration;




void setup() {
   test1.attach(servo1);
   test2.attach(servo2);
   pinMode(trigPin, OUTPUT); /
   pinMode(echoPin, INPUT);
   pinMode(led, OUTPUT); 
   Serial.begin(9600);
}



 
int i=180;

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.println(distance);

  
  int brightness=map(distance ,10,50,255,0);
  analogWrite(led ,brightness);
  
  if(i==0){
    for( i=0;i<180;i+=30){
    test1.write(i);}
      }
  
  if(i>0 && distance<=30){
      i-=5;
    test1.write(i);
      delay(300);
   }
 

 if(i>0 && distance<=30){
      i-=5;  
  test2.write(i);
      delay(300);
    }
  }



