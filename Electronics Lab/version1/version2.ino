// --- Motor Control Pins ---
#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5

// --- IR Sensor Pins ---
#define LEFT_SENSOR 12
#define RIGHT_SENSOR 11

// --- Motor Speed ---
// Range is 0 (stop) to 255 (full speed)
const int speedA = 50; // Speed for IN1 and IN2
const int speedB = 60; // Speed for IN3 and IN4 

void setup() {
  // 1. Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // 2. Set IR sensor pins as inputs
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  // 3. Apply speed to both motors
  analogWrite(ENA, speedA); // Pin 10 controls IN1 and IN2
  analogWrite(ENB, speedB); // Pin 5 controls IN3 and IN4
}

void loop() {
  // Read sensor values 
  // (Usually: 1/HIGH = Black Line, 0/LOW = White Surface)
  int leftVal = digitalRead(LEFT_SENSOR);
  int rightVal = digitalRead(RIGHT_SENSOR);

  // --- Logic for Line Following ---

  if (leftVal == LOW && rightVal == LOW) {
    // Both on white -> Move Forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  else if (leftVal == HIGH && rightVal == LOW) {
    // Left sensor on black -> Turn Left
    digitalWrite(IN1, HIGH);  // Right motor forward
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);   // Left motor stop
    digitalWrite(IN4, LOW); 
  } 
  else if (leftVal == LOW && rightVal == HIGH) {
    // Right sensor on black -> Turn Right
    digitalWrite(IN1, LOW);   // Right motor stop
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);  // Left motor forward
    digitalWrite(IN4, LOW);
  } 
  else if (leftVal == HIGH && rightVal == HIGH) {
    // Both on black -> Stop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}