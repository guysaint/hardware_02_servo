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
  if (digitalRead(button_1) == LOW) {
    Serial.println("Button Pressed!");
    for (pos = 0; pos <11; pos += 1){
      myservo.write(pos);
      delay(15);
      
    }
  Serial.println("forward");                    
  }
}

