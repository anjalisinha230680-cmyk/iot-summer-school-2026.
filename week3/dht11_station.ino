#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

const int redLED = 8;
const int greenLED = 9;
unsigned long previousMillis = 0;
const long interval = 2000;

