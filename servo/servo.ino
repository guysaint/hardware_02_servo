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

    // 0 → 180도 회전
    for (pos = 0; pos <= 270; pos += 30) {
      myservo.write(pos);
      delay(20);
    }

    // 180 → 0도 회전
    for (pos = 270; pos >= 0; pos -= 30) {
      myservo.write(pos);
      delay(20);
    }

    Serial.println("Return complete");
  }

  buttonPreviouslyPressed = currentButtonState;
}