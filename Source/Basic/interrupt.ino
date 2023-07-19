const int interruptPin = 2;  // The pin number to which the interrupt is connected

volatile int count = 0;  // A volatile variable to store the count

void setup() {
  pinMode(interruptPin, INPUT_PULLUP);  // Configure the interrupt pin as input with internal pull-up resistor
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptHandler, LOW);
  // Attach the interrupt handler function to the interrupt pin, which triggers on the Low state
  Serial.begin(115200);  // Initialize the serial communication
}

void loop() {
  // Main program loop
  // You can perform other tasks here
}

void interruptHandler() {
  // This function will be called when the interrupt occurs
  count++;                // Increment the count variable
  Serial.println(count);  // Print the count value
}