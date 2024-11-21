#include<ESP8266WiFi.h>
int trigPin=4;
int echoPin=5;
long duration;
int distance;
void setup(){
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  //WiFi.mode(WIFI_OFF);
}
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration=pulseIn(echoPin, HIGH);

  distance =(duration*0.034) / 2;

  /*if(distance<10.0){
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);
  }*/
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  digitalWrite(12, LOW);
  if(distance>30.0){
    digitalWrite(12, HIGH);
    while(distance>10){
      duration=pulseIn(echoPin, HIGH);
      distance=(duration*0.034)/2;
    }
    digitalWrite(12,LOW);
  }
  delay(500);
}