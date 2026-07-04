const int trigPin = 9;
const int echoPin = 10;

const int yellowLED = 3;
const int redLED = 4;
const int buzzer = 6;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);


  long duration = pulseIn(echoPin, HIGH);


  float distance = (duration * 0.034) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 50) {

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(buzzer);

    Serial.println("SAFE");
  }

  else if (distance > 20 && distance <= 50) {

    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
    delay(500);

  }

  else if (distance > 10 && distance <= 20) {

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
    delay(200);

  }

  
  else {

    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1000);

    delay(100);

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    delay(100);
  }
}
