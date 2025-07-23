#include <Servo.h>

Servo myservo;  
int pos = 0;    
int button_1 = 8;
bool buttonPreviouslyPressed = false;

void setup() {
  myservo.attach(9);
  pinMode(button_1, INPUT_PULLUP);  
  Serial.begin(9600);
}

void loop() {
  bool currentButtonState = digitalRead(button_1) == LOW;

  if (currentButtonState && !buttonPreviouslyPressed) {
    Serial.println("Button Pressed!");

    for(int i = 0; i<=10; i++){
      myservo.write(0);
      delay(500);
      myservo.write(180);
      delay(500);
    }

    

    
  }

  buttonPreviouslyPressed = currentButtonState;
}