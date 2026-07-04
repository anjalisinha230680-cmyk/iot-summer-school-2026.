#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const int ldrPin = A0;
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();


  int ldrValue = analogRead(ldrPin);

  int lightPercent = map(ldrValue, 0, 1023, 0, 100);

  String lightCondition;

  if (lightPercent >= 50)
    lightCondition = "Bright";
  else
    lightCondition = "Dark";

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = (duration * 0.034) / 2;

  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time      : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp      : ");
  Serial.print(temp);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Light     : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(lightCondition);
  Serial.println(")");

  Serial.print("Distance  : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("==================");

  delay(5000);
}
