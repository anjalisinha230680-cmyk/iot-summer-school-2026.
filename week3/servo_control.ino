#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int buttonPin = 2;

bool lastButtonState = HIGH;

void setup() {

  myServo.attach(9);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  int potValue = analogRead(potPin);

  
  int angle = map(potValue, 0, 1023, 0, 180);


  myServo.write(angle);


  Serial.print("Servo Angle: ");
  Serial.println(angle);

  
  bool buttonState = digitalRead(buttonPin);


  if (lastButtonState == HIGH && buttonState == LOW) {

    
    for (int i = 0; i <= 180; i++) {
      myServo.write(i);
      delay(10);
    }

    
    for (int i = 180; i >= 0; i--) {
      myServo.write(i);
      delay(10);
    }
  }

  lastButtonState = buttonState;

  delay(100);
}
