unsigned int count = 0;

void setup() {
  Serial.begin(115200);  // Initialize the serial communication
}

void loop() {
  if (millis() % 1000 == 0) {
    Serial.printf("Count : %d\n", count);  // Print the count value
    delayMicroseconds(1000);
    count++;
  }
}
