#include <Comparator.h>

// Pin connected to the PWM output
const int pwmPin = 2;  // 4808 PWM Pin : 2, 3, 12, 13, 14, 15, 16, 17

void setup() {
  pinMode(pwmPin, OUTPUT);

  // Configure relevant comparator parameters
  Comparator.input_p = comparator::in_p::in0;        // Use positive input 0 (PD2)
  Comparator.input_n = comparator::in_n::dacref;     // Connect the negative pin to the DACREF voltage
  Comparator.reference = comparator::ref::vref_2v5;  // Set the DACREF voltage to 2.5V
 // Comparator.dacref = 127;                         // Gives us 1.24V -> (127 / 256) * 2.5V = 1.24V
  Comparator.hysteresis = comparator::hyst::large;   // Use a 50mV hysteresis
  Comparator.output = comparator::out::enable;       // Enable output on digital pin 7 (PA7)

  // Initialize comparator
  Comparator.init();

  // Start comparator
  Comparator.start();
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