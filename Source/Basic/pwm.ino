// Pin connected to the PWM output
const int pwmPin = 2;  // 4808 PWM Pin : 2, 3, 12, 13, 14, 15, 16, 17

void setup() {
  // Set the PWM pin as an output
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  // Increase the LED step gradually
  for (int step = 0; step <= 255; step++) {
    analogWrite(pwmPin, step);
    delay(10);
  }

  // Decrease the LED step gradually
  for (int step = 255; step >= 0; step--) {
    analogWrite(pwmPin, step);
    delay(10);
  }
}