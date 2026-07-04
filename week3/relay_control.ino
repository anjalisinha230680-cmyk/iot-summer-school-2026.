#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int relayPin = 8;      
const int buttonPin = 3;

bool relayState = false;
bool manualMode = false;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(relayPin, LOW);
}

void loop() {

  float temperature = dht.readTemperature();

  bool buttonState = digitalRead(buttonPin);


  if (lastButtonState == HIGH && buttonState == LOW) {

    manualMode = !manualMode;

    if (manualMode)
      relayState = !relayState;
  }

  lastButtonState = buttonState;

  if (!manualMode) {

    if (temperature > 32) {
      relayState = true;
    }

    else if (temperature < 28) {
      relayState = false;
    }
  }

  digitalWrite(relayPin, relayState);

  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.print(" C | Relay : ");

  if (relayState)
    Serial.println("ON");
  else
    Serial.println("OFF");

  delay(2000);
}
