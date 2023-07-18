#define ledPin 7

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (millis() % 1000 == 0) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    delay(1);
  }
}
