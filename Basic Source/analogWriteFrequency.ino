#define pwmOut 2
unsigned long startTime;
unsigned long period;
float frequency;

void setup() {
  Serial.begin(115200);

  analogWriteFrequency(64);  // 1,  4, 8, 16, 32 and 64 kHz
  pinMode(pwmOut, OUTPUT);
}

void loop() {
  analogWrite(pwmOut, 128);  // 128/256 : 50% Duty

  startTime = micros();            // Get the current time in microseconds
  period = pulseIn(pwmOut, HIGH);  // Measure the time period of the signal

  // Calculate frequency in Hz
  frequency = 1000000.0 / period;

  // Display frequency on the serial monitor
  Serial.print("Frequency: ");
  Serial.print(frequency / 2);
  Serial.println(" Hz");

  delay(1000);  // Delay for stability
}
