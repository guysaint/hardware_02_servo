#include <Servo.h>

Servo myservo;  
int pos = 0;    
int button_1 = 8;

void setup() {
  myservo.attach(9);
  pinMode(button_1, INPUT_PULLUP);  
  Serial.begin(9600);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);             
    delay(15);                     
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(15);                     
  }
}
