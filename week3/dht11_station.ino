#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


const int redLED = 8;
const int greenLED = 9;

unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float tempC = dht.readTemperature();
    float humidity = dht.readHumidity();
    float tempF = (tempC * 9.0 / 5.0) + 32;

    if (isnan(tempC) || isnan(humidity)) {
      Serial.println("ERROR,ERROR,ERROR,ERROR");
      return;
    }

  
    unsigned long timestamp = currentMillis / 1000;

    Serial.print(timestamp);
    Serial.print(",");
    Serial.print(tempC);
    Serial.print(",");
    Serial.print(tempF);
    Serial.print(",");
    Serial.println(humidity);

  
    if (tempC > 35 || humidity > 80) {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
    } else {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
  }
}
