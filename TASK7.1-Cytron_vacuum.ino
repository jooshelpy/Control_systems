// Define the pins for motor control
#define MotorSpeedPin 9 // pin 9 as pwm
#define MotorDirPin 10  // pin 10 as dir

// Define variables for speed and filtered speed
double currentSpeed = 0, filteredSpeed = 0;

// Define the smoothing factor for the filter
double smoothingFactor = 0.9;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the motor control pins as outputs
  pinMode(MotorSpeedPin, OUTPUT);
  pinMode(MotorDirPin, OUTPUT);
}

void loop() {
  // Set the motor direction to clockwise
  digitalWrite(MotorDirPin, LOW);
  filteredSpeed = 0;

  // Increase speed up to the maximum value
  for (currentSpeed = 0; currentSpeed <= 255; currentSpeed++) {
    // Apply a simple exponential filter (smoothing filter)
    filteredSpeed = smoothingFactor * filteredSpeed + (1 - smoothingFactor) * currentSpeed;
    
    // Control the motor speed
    analogWrite(MotorSpeedPin, filteredSpeed);

    // Print speed values before and after filtering
    Serial.print("speed before filter: ");
    Serial.println(currentSpeed);
    Serial.print("Speed after filter: ");
    Serial.println(filteredSpeed);

    delay(100);
  }

  // Turn off the motor
  analogWrite(MotorSpeedPin, 0);
  filteredSpeed = 0;

  // Set the motor direction to counterclockwise
  digitalWrite(MotorDirPin, HIGH);

  // Increase speed up to the maximum value in the opposite direction
  for (currentSpeed = 0; currentSpeed <= 255; currentSpeed++) {
    // Apply the same exponential filter (smoothing filter)
    filteredSpeed = smoothingFactor * filteredSpeed + (1 - smoothingFactor) * currentSpeed;

    // Control the motor speed
    analogWrite(MotorSpeedPin, filteredSpeed);

    // Print speed values before and after filtering
    Serial.print("speed before filter: ");
    Serial.println(currentSpeed);
    Serial.print("Speed after filter: ");
    Serial.println(filteredSpeed);

    delay(100);
  }

  // Turn off the motor
  analogWrite(MotorSpeedPin, 0);
}
