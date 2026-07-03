// Serial Command Interface

const int ledPin = LED_BUILTIN;
int blinkCounter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial Command Interface Ready");
}

void loop() {

  if (Serial.available()) {

    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "LED_ON") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    }

    else if (command == "LED_OFF") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    }

    else if (command.startsWith("BLINK_")) {

      int times = command.substring(6).toInt();

      if (times >= 1 && times <= 9) {

        blinkCounter += times;

        for (int i = 0; i < times; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        }

        Serial.print("Blinked ");
        Serial.print(times);
        Serial.println(" times");
      }
      else {
        Serial.println("ERROR: Unknown command");
      }
    }

    else if (command == "STATUS") {
      Serial.print("LED State: ");

      if (digitalRead(ledPin) == HIGH)
        Serial.println("ON");
      else
        Serial.println("OFF");
    }

    else if (command == "RESET") {
      blinkCounter = 0;
      Serial.println("Blink counter reset");
    }

    else {
      Serial.println("ERROR: Unknown command");
    }
  }
}
