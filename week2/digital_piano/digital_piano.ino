bool majorMode = true;
int majorScale[4] = {262, 294, 330, 349}; // Do, Re, Mi, Fa
int minorScale[4] = {262, 294, 311, 349}; // Do, Re, Me, Fa
void loop() {

  static bool lastModeButton = HIGH;

  if (digitalRead(modeButton) == LOW && lastModeButton == HIGH) {
    majorMode = !majorMode;
    delay(200); // debounce
  }
  lastModeButton = digitalRead(modeButton);

  bool b1 = digitalRead(button1) == LOW;
  bool b2 = digitalRead(button2) == LOW;
  bool b3 = digitalRead(button3) == LOW;
  bool b4 = digitalRead(button4) == LOW;

  int pressed = b1 + b2 + b3 + b4;

  if (pressed >= 2) {
    tone(buzzer, 392);   // Sol
  }
  else if (b1) {
    tone(buzzer, majorMode ? majorScale[0] : minorScale[0]);
  }
  else if (b2) {
    tone(buzzer, majorMode ? majorScale[1] : minorScale[1]);
  }
  else if (b3) {
    tone(buzzer, majorMode ? majorScale[2] : minorScale[2]);
  }
  else if (b4) {
    tone(buzzer, majorMode ? majorScale[3] : minorScale[3]);
  }
  else {
    noTone(buzzer);
  }
}
