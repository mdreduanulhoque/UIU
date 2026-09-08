// ==========================================
// PIN DEFINITIONS (Matching your wiring map)
// ==========================================

// Motor Driver Pins
#define PWMA 9   // Left Motor Speed
#define AIN1 8   // Left Motor Direction 1
#define AIN2 7   // Left Motor Direction 2
#define PWMB 10  // Right Motor Speed
#define BIN1 12  // Right Motor Direction 1
#define BIN2 11  // Right Motor Direction 2

// Sensor Array Pins
#define OUT1 A0  // Far Left
#define OUT2 A1  // Mid Left
#define OUT3 A2  // Center
#define OUT4 A3  // Mid Right
#define OUT5 A4  // Far Right

// ==========================================
// CONFIGURATION & PID VARIABLES
// ==========================================

// NOTE: Change this to LOW if your sensors output LOW when seeing black
#define BLACK HIGH 

// PID Constants (You will need to tune these on the physical track)
float Kp = 25.0;  // Proportional: Adjusts how hard it turns toward the line
float Ki = 0.0;   // Integral: Corrects accumulated errors over time (keep at 0 initially)
float Kd = 15.0;  // Derivative: Dampens the turning to prevent wobble/bang-bang

float error = 0;
float last_error = 0;
float integral = 0;

// Motor Speeds
int baseSpeed = 100; // Normal forward speed (0-255)
int maxSpeed = 200;  // Maximum allowed speed (0-255)
int turnSpeed = 120; // Speed used for 90-degree sharp turns

void setup() {
  // Configure Motor Pins
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // Configure Sensor Pins
  pinMode(OUT1, INPUT);
  pinMode(OUT2, INPUT);
  pinMode(OUT3, INPUT);
  pinMode(OUT4, INPUT);
  pinMode(OUT5, INPUT);

  // Optional: Serial for debugging sensor values
  Serial.begin(9600);
}

// Function to control both motors easily
void driveMotors(int leftSpeed, int rightSpeed) {
  // Constrain speeds to prevent PWM overflow
  leftSpeed = constrain(leftSpeed, -maxSpeed, maxSpeed);
  rightSpeed = constrain(rightSpeed, -maxSpeed, maxSpeed);

  // Left Motor Direction
  if (leftSpeed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else if (leftSpeed < 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    leftSpeed = -leftSpeed; // Convert to positive for PWM
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW); // Brake
  }
  analogWrite(PWMA, leftSpeed);

  // Right Motor Direction
  if (rightSpeed > 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else if (rightSpeed < 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    rightSpeed = -rightSpeed; // Convert to positive for PWM
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW); // Brake
  }
  analogWrite(PWMB, rightSpeed);
}

void loop() {
  // 1. Read all 5 sensors
  int s1 = digitalRead(OUT1);
  int s2 = digitalRead(OUT2);
  int s3 = digitalRead(OUT3);
  int s4 = digitalRead(OUT4);
  int s5 = digitalRead(OUT5);

  // 2. CHECK RULE 4: Cross-Section Node (All 5 sensors detect black)
  if (s1 == BLACK && s2 == BLACK && s3 == BLACK && s4 == BLACK && s5 == BLACK) {
    driveMotors(baseSpeed, baseSpeed); // Keep going straight
    return; // Restart loop, skip PID
  }

  // 3. CHECK RULE 2: Far Left detects black -> Turn Left
  if (s1 == BLACK) {
    // Sharp left: Left motor reverses, Right motor goes forward
    driveMotors(-turnSpeed, turnSpeed); 
    return;
  }

  // 4. CHECK RULE 3: Far Right detects black -> Turn Right
  if (s5 == BLACK) {
    // Sharp right: Left motor goes forward, Right motor reverses
    driveMotors(turnSpeed, -turnSpeed);
    return;
  }

  // 5. CHECK RULE 1: Inner sensors detecting line -> PID Smooth Control
  // Calculate positional error based on which inner sensors see the line
  if      (s2 == BLACK && s3 != BLACK && s4 != BLACK) error = -2; // Line is far left
  else if (s2 == BLACK && s3 == BLACK && s4 != BLACK) error = -1; // Line is slightly left
  else if (s2 != BLACK && s3 == BLACK && s4 != BLACK) error = 0;  // Line is dead center
  else if (s2 != BLACK && s3 == BLACK && s4 == BLACK) error = 1;  // Line is slightly right
  else if (s2 != BLACK && s3 != BLACK && s4 == BLACK) error = 2;  // Line is far right
  else if (s2 != BLACK && s3 != BLACK && s4 != BLACK) {
    // Memory state: If it totally loses the line, look at the last error 
    // to remember which way to turn to find it again.
    if (last_error > 0) error = 3; 
    else if (last_error < 0) error = -3;
  }

  // Calculate PID values
  float P = error;
  integral += error;
  float D = error - last_error;
  
  // The PID Equation
  float correction = (Kp * P) + (Ki * integral) + (Kd * D);

  // Apply correction to base speed
  int leftMotorSpeed = baseSpeed + correction;
  int rightMotorSpeed = baseSpeed - correction;

  // Send speeds to motors
  driveMotors(leftMotorSpeed, rightMotorSpeed);

  // Save current error for the next loop's derivative calculation
  last_error = error;
}