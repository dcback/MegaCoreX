/*
  Vin(+) = 3.251V const 
  Vin(-) = Variable
  Vout = HIGH@191, LOW@192 

  4.3 * ( 191 / 256 ) = 3.208@HIGH out
  4.3 * ( 192 / 256 ) = 3.225@LOW out
*/

#include <Comparator.h>
unsigned int dacrefValue = 191;

void setup() {
  Serial.begin(115200);  // Initialize the serial communication

  // Configure relevant comparator parameters
  Comparator.input_p = comparator::in_p::in0;         // Use positive input 0 (PD2)
  Comparator.input_n = comparator::in_n::dacref;      // Connect the negative pin to the DACREF voltage
  Comparator.reference = comparator::ref::vref_4v3;   // Set the DACREF voltage to 4.3V
  Comparator.dacref = dacrefValue;                    // Gives us 1.24V -> (dacrefValue / 256) * 4.3V = ?
  Comparator.hysteresis = comparator::hyst::disable;  // No Use hysteresis
  Comparator.output = comparator::out::enable;        // Enable output on digital pin 7 (PA7)

  // Initialize comparator
  Comparator.init();

  // Start comparator
  Comparator.start();
}

void loop() {
  Serial.printf("dacValue = %d, Output = %d\n", dacrefValue, digitalRead(PIN_PA7));
  delay(1000);
}
