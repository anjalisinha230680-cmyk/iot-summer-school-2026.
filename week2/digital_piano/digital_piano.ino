void loop() {

  bool b1 = digitalRead(button1) == LOW;
  bool b2 = digitalRead(button2) == LOW;
  bool b3 = digitalRead(button3) == LOW;
  bool b4 = digitalRead(button4) == LOW;

  int pressed = b1 + b2 + b3 + b4;

  // If any two buttons are pressed together
  if (pressed >= 2) {
    tone(buzzer, 392);   // Sol
  }
  else if (b1) {
    tone(buzzer, 262);   // Do
  }
  else if (b2) {
    tone(buzzer, 294);   // Re
  }
  else if (b3) {
    tone(buzzer, 330);   // Mi
  }
  else if (b4) {
    tone(buzzer, 349);   // Fa
  }
  else {
    noTone(buzzer);
  }
}
   
