// PWM Fading Night Light

const int ledPin = 9;
const int buttonPin = 2;

int mode = 0;
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void loop() {

  bool currentButton = digitalRead(buttonPin);

  if (currentButton == LOW && lastButtonState == HIGH) {
    mode = (mode + 1) % 3;

    if (mode == 0)
      Serial.println("Mode 1: Slow Breathing");
    else if (mode == 1)
      Serial.println("Mode 2: Fast Pulse");
    else
      Serial.println("Mode 3: SOS Pattern");

    delay(200);
  }

  lastButtonState = currentButton;

  if (mode == 0) {
    breathing(15);
  }
  else if (mode == 1) {
    breathing(2);
  }
  else {
    sosPattern();
  }
}

void breathing(int d) {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(d);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(d);
  }
}

void sosPattern() {

  for (int i = 0; i < 3; i++) {
    blink(200);
  }

  for (int i = 0; i < 3; i++) {
    blink(600);
  }

  for (int i = 0; i < 3; i++) {
    blink(200);
  }

  delay(1000);
}

void blink(int t) {
  digitalWrite(ledPin, HIGH);
  delay(t);
  digitalWrite(ledPin, LOW);
  delay(200);
}
