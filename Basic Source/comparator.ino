#include <Comparator.h>

const int inputPin = 7;  // Digital pin connected to the signal source
unsigned long startTime;
unsigned long period;
float frequency;


void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(115200);  // Initialize the serial communication

  // Configure relevant comparator parameters
  Comparator.input_p = comparator::in_p::in0;   // Use positive input 0 (PD2)
  Comparator.input_n = comparator::in_n::in0;   // Use negative input 0 (PD3)
  Comparator.output = comparator::out::enable;  // Enable output on digital pin 7 (PA7)

  // Initialize comparator
  Comparator.init();

  // Start comparator
  Comparator.start();
}

void loop() {
  startTime = micros();              // Get the current time in microseconds
  period = pulseIn(inputPin, HIGH);  // Measure the time period of the signal

  // Calculate frequency in Hz
  frequency = 1000000.0 / period;

  // Display frequency on the serial monitor
  Serial.print("Frequency: ");
  Serial.print(frequency);
  Serial.println(" Hz");

  delay(100);  // Delay for stability
}
