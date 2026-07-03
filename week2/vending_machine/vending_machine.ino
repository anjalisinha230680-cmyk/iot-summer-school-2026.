const int coinButton = 2;
const int selectButton = 3;
const int cancelButton = 4;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void setup() {
  pinMode(coinButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(cancelButton, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);

  Serial.println("State: IDLE");
}

void loop() {

  updateLEDs();

  switch (currentState) {

    case IDLE:
      if (digitalRead(coinButton) == LOW) {
        currentState = COIN_INSERTED;
        Serial.println("IDLE -> COIN_INSERTED");
        delay(300);
      }
      break;

    case COIN_INSERTED:
      if (digitalRead(selectButton) == LOW) {
        currentState = ITEM_SELECTED;
        Serial.println("COIN_INSERTED -> ITEM_SELECTED");
        delay(300);
      }

      else if (digitalRead(cancelButton) == LOW) {
        currentState = IDLE;
        Serial.println("COIN_INSERTED -> IDLE");
        delay(300);
      }
      break;

    case ITEM_SELECTED:
      currentState = DISPENSING;
      Serial.println("ITEM_SELECTED -> DISPENSING");
      delay(1000);
      break;

    case DISPENSING:
      Serial.println("DISPENSING -> IDLE");
      currentState = IDLE;
      delay(1000);
      break;
  }
}

void updateLEDs() {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  switch (currentState) {

    case IDLE:
      digitalWrite(led1, HIGH);
      break;

    case COIN_INSERTED:
      digitalWrite(led2, HIGH);
      break;

    case ITEM_SELECTED:
      digitalWrite(led3, HIGH);
      break;

    case DISPENSING:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      break;
  }
}
