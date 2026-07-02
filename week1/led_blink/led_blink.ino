int count = 0;
int sensorPin = AO;
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(sensorPin)
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500); 
  count++;
  Serial.print("Blink count:");
  Serial.println(count);
}
