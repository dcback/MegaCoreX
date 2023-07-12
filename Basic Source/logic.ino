#include <Logic.h>
#define ledPin 7
#define statePin A2
bool state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(statePin, OUTPUT);

  // Initialize logic block 2
  // Logic block 2 has three inputs, PD0, PD1 and PD2.
  // It has one output, but this is disabled because we're using an interrupt instead.
  Logic2.enable = true;                     // Enable logic block 2
  Logic2.input0 = logic::in::input_pullup;  // Set PD0/A0 as input with pullup
  Logic2.input1 = logic::in::input_pullup;  // Set PD1/A1 as input with pullup
  Logic2.output = logic::out::enable;       // Enable logic block 2 output pin (PD3)
  Logic2.filter = logic::filter::disable;   // No output filter enabled
  Logic2.truth = 0x08;                      // Set AND truth table : 08@AND, 7F@NAND, FE@OR, 01@NOR

  // Initialize logic block 2
  Logic2.init();

  // Start the AVR logic hardware
  Logic::start();
}

void loop() {
  digitalWrite(A2, state);
  digitalRead(A1);

  digitalWrite(ledPin, digitalRead(A3));
  Serial.println("PD0 AND PD1 = PD3");
  Serial.print(" ");
  Serial.print(digitalRead(A0));
  Serial.print("       ");
  Serial.print(digitalRead(A1));
  Serial.print("     ");
  Serial.println(digitalRead(A3));
  delay(1000);
  state = !state;
}
