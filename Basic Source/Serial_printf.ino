// Serial.printf Function
int ch = 65;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.printf("Run time = %ld, ASCII value = %d, chacter = %c\n", millis(), ch, ch);
  ch++;
  if (ch > 90) ch = 65;

  delay(1000);
}
