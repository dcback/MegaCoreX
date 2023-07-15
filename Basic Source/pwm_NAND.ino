#include <Logic.h>

// Pin connected to the PWM output
const int pwmPin = 2;  // 4808 PWM Pin : 2, 3, 12, 13, 14, 15, 16, 17

void setup() {
  pinMode(pwmPin, OUTPUT);

  Logic1.enable = true;                     // Enable logic block 2
  Logic1.input0 = logic::in::input_pullup;; // Set PC0 as input
  Logic1.input1 = logic::in::input_pullup;  // Set PC1 as input with pullup
  Logic1.output = logic::out::enable;       // Enable logic block 2 output pin (PC3)
  Logic1.filter = logic::filter::disable;   // No output filter enabled
  Logic1.truth = 0xF7;                      // Set NAND truth table

  // Initialize logic block 2
  Logic1.init();

  // Start the AVR logic hardware
  Logic::start();
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