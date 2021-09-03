#include <Arduino.h>
#define pausePin A0
#define L1 2
#define L2 3
#define L3 4

#define R4 5
#define R5 6
#define R6 7



#define pausePin A0
unsigned long inflateTime = 30000; //variable
unsigned long deflateTime = 100000; //variable
unsigned long waitTime = 300000-deflateTime; //variable

void setup() {
Serial.begin(9600);
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);

pinMode(R4,OUTPUT);
pinMode(R5,OUTPUT);
pinMode(R6,OUTPUT);

pinMode(pausePin, INPUT);

digitalWrite(L1,LOW);
digitalWrite(L2,LOW);
digitalWrite(L3,LOW);

digitalWrite(R4,LOW);
digitalWrite(R5,LOW);
digitalWrite(R6,LOW);

delay(3000);
//3000 = 3s

}

void loop() {
for (size_t i = 1; i <= 50; i++) //variable no of cycles
  {
  while (digitalRead(pausePin))
  {
  delay(2000);
  }
    
    //initialise everything to LOW
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);

   // Inflate IBO

  delay(100);
  digitalWrite(L1,HIGH);
  delay(inflateTime);

  digitalWrite(L1,LOW);
  delay(1000);

   // Fully inflated IBO - Time to deflate

  digitalWrite(L2,HIGH);
  delay(100);
  digitalWrite(L3,HIGH);
  delay(deflateTime);

   // Deflation complete - STOP!  

  delay(100);
  digitalWrite(L3,LOW);
  
  // Wait for 
  delay(waitTime);
  digitalWrite(L2,LOW);  
    
  Serial.println(i);
  }
  while (true)
  {
    /* code */
  }
  
}