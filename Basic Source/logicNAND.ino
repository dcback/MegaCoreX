// Test Condition : D7@PA7 -- D8@PC0

#include <Logic.h>
#define ledPin 7

bool state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  Logic1.enable = true;                     // Enable logic block 2
  Logic1.input0 = logic::in::input;         // Set PC0 as input
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
  digitalWrite(ledPin, state);

  Serial.print(digitalRead(8));
  Serial.print("\t");
  Serial.println(digitalRead(11));
  state = !state;
  delay(1000);
}
