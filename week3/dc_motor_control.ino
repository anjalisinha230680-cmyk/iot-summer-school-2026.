const int enA = 9;      
const int in1 = 7;
const int in2 = 8;

const int potPin = A0;
const int dirButton = 2;
const int startStopButton = 3;

bool direction = true;     
bool motorRunning = true;

bool lastDirButton = HIGH;
bool lastStartButton = HIGH;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(dirButton, INPUT_PULLUP);
  pinMode(startStopButton, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  
  int potValue = analogRead(potPin);

  
  int speedValue = map(potValue, 0, 1023, 0, 255);

  
  int speedPercent = map(speedValue, 0, 255, 0, 100);

  
  bool currentDirButton = digitalRead(dirButton);

  if (lastDirButton == HIGH && currentDirButton == LOW) {
    direction = !direction;
  }

  lastDirButton = currentDirButton;

  bool currentStartButton = digitalRead(startStopButton);

  if (lastStartButton == HIGH && currentStartButton == LOW) {
    motorRunning = !motorRunning;
  }

  lastStartButton = currentStartButton;

  if (motorRunning) {

    analogWrite(enA, speedValue);

    if (direction) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    } else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }

  } else {

    analogWrite(enA, 0);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }

  Serial.print("Direction : ");

  if (direction)
    Serial.println("Forward");
  else
    Serial.println("Reverse");

  Serial.print("Speed     : ");
  Serial.print(speedPercent);
  Serial.println("%");

  Serial.print("State     : ");

  if (motorRunning)
    Serial.println("Running");
  else
    Serial.println("Stopped");

  Serial.println("--------------------");

  delay(300);
}
