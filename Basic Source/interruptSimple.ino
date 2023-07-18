#define interruptPin 2  // The pin number to which the interrupt is connected
unsigned int loopCount = 0;
unsigned int intrCount = 0;

void setup() {
  Serial.begin(115200);  // Initialize the serial communication

  pinMode(interruptPin, INPUT_PULLUP);    // Configure the interrupt pin as input with internal pull-up resistor
  attachInterrupt(interruptPin, interruptHandler, LOW);  // RISING, FALLING, CHANGE, HIGH, LOW
  // Attach the interrupt handler function to the interrupt pin, which triggers on the Low state
}

void loop() {
  Serial.printf("Loop Count : %d\n", loopCount);  // Print the count value
  loopCount++;
  delay(1000);
}

void interruptHandler() {
  // This function will be called when the interrupt occurs
  intrCount++;                                         // Increment the count variable
  Serial.printf("interrupt Count : %d\n", intrCount);  // Print the count value
}