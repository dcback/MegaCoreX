#define ledPin  PIN_PA7  
bool state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);  
}

void loop() {
  digitalWrite(ledPin, state);
  delay(1000);  
  state = !state;

  Serial.print("Arduino Pin No : ");
  Serial.println(PIN_PA7);
}
