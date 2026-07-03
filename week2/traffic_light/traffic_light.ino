// Traffic Light Controller with Pedestrian Button

const int redLED = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int buttonPin = 7;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void showRed(unsigned long duration) {
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  Serial.print(millis());
  Serial.println(" ms : RED ON");

  delay(duration);
}

void showYellow(unsigned long duration) {
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);

  Serial.print(millis());
  Serial.println(" ms : YELLOW ON");

  delay(duration);
}

void showGreen(unsigned long duration) {
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);

  Serial.print(millis());
  Serial.println(" ms : GREEN ON");

  delay(duration);
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {
    showRed(8000);
    return;
  }

  showRed(5000);

  if (digitalRead(buttonPin) == LOW) {
    showRed(8000);
    return;
  }

  showYellow(2000);

  if (digitalRead(buttonPin) == LOW) {
    showRed(8000);
    return;
  }

  showGreen(4000);
}
