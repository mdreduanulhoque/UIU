// Motor A (Left Motor) Pins
#define PWMA 5
#define AIN1 7
#define AIN2 8

// Motor B (Right Motor) Pins
#define PWMB 6
#define BIN1 9
#define BIN2 10

// IR Sensor Pins (Left to Right)
#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A4

const int BLACK = LOW; 
const int WHITE = HIGH;

// PID Configuration
float Kp = 1.8;   
float Ki = 0.0;   
float Kd = 2.5;   
int baseSpeed = 80;  
int maxSpeed = 100;   
float P, I, D, previousError = 0;

// Hardware Tuning
// Adjust this delay so the robot's wheels sit exactly on the node before turning
const int nodeOffsetDelay = 200; 
const int turnSpeed = 70;

// Grid and Orientation State
int currentX = 0;
int currentY = 0;
int heading = 0; // 0=North (+Y), 1=East (+X), 2=South (-Y), 3=West (-X)

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);

  delay(2000); // 3-second delay before starting

  // Set your target node here (e.g., targetX = 3, targetY = 3)
  goToNode(2, 2);
}

void loop() {
  // Stays empty; robot stops after reaching target in setup()
}

// --- ROUTING & GRID LOGIC ---

void goToNode(int targetX, int targetY) {
  // 1. Solve Y Axis FIRST
  if (targetY > currentY) {
    faceHeading(0); // Face North
    while (currentY < targetY) moveOneNode();
  } else if (targetY < currentY) {
    faceHeading(2); // Face South
    while (currentY > targetY) moveOneNode();
  }

  // 2. Solve X Axis SECOND
  if (targetX > currentX) {
    faceHeading(1); // Face East
    while (currentX < targetX) moveOneNode();
  } else if (targetX < currentX) {
    faceHeading(3); // Face West
    while (currentX > targetX) moveOneNode();
  }

  // Target reached
  driveMotors(0, 0);
  while(true); 
}

void faceHeading(int targetHeading) {
  if (heading == targetHeading) return;

  int diff = targetHeading - heading;
  if (diff < 0) diff += 4; // Ensure positive difference

  if (diff == 1) {
    turnRight90();
  } else if (diff == 2) {
    turnRight90();
    turnRight90();
  } else if (diff == 3) {
    turnLeft90();
  }
  heading = targetHeading;
}

void moveOneNode() {
  // Line follow until a node is hit
  while (true) {
    bool s1 = (digitalRead(IR1) == BLACK); 
    bool s2 = (digitalRead(IR2) == BLACK); 
    bool s3 = (digitalRead(IR3) == BLACK); 
    bool s4 = (digitalRead(IR4) == BLACK); 
    bool s5 = (digitalRead(IR5) == BLACK); 

    bool fullNode  = (s1 && s2 && s3 && s4 && s5); 
    bool leftNode  = (s1 && s2 && s3 && !s4 && !s5);
    bool rightNode = (!s1 && !s2 && s3 && s4 && s5);

    if (fullNode || leftNode || rightNode) {
      // Node detected. Push forward to align wheels over the intersection.
      driveMotors(baseSpeed, baseSpeed);
      delay(nodeOffsetDelay);
      driveMotors(0, 0);
      delay(200); // Brief pause to stabilize
      break;      // Exit PID loop
    }

    // Execute normal PID line following
    int error = calculateError(s1, s2, s3, s4, s5);
    P = error;
    I = I + error;
    D = error - previousError;
    previousError = error;

    int correction = (Kp * P) + (Ki * I) + (Kd * D);
    int leftMotorSpeed = constrain(baseSpeed + correction, -maxSpeed, maxSpeed);
    int rightMotorSpeed = constrain(baseSpeed - correction, -maxSpeed, maxSpeed);
    
    driveMotors(leftMotorSpeed, rightMotorSpeed);
  }

  // Update coordinates based on the direction traveled
  if (heading == 0) currentY++;
  else if (heading == 1) currentX++;
  else if (heading == 2) currentY--;
  else if (heading == 3) currentX--;
}

// --- MOVEMENT & SENSOR LOGIC ---

void turnLeft90() {
  driveMotors(-turnSpeed, turnSpeed); // Spin left
  delay(300); // Blind delay to force center sensor off the current line
  while (digitalRead(IR3) != BLACK) {
    // Keep spinning until the center sensor finds the perpendicular line
  }
  driveMotors(0, 0);
  delay(200);
}

void turnRight90() {
  driveMotors(turnSpeed, -turnSpeed); // Spin right
  delay(300); // Blind delay to force center sensor off the current line
  while (digitalRead(IR3) != BLACK) {
    // Keep spinning until the center sensor finds the perpendicular line
  }
  driveMotors(0, 0);
  delay(200);
}

int calculateError(bool s1, bool s2, bool s3, bool s4, bool s5) {
  if (!s1 && !s2 && !s3 && !s4 && !s5) return previousError; 

  if (s1 && !s2 && !s3 && !s4 && !s5) return -40;
  if (s1 && s2 && !s3 && !s4 && !s5) return -30;
  if (!s1 && s2 && !s3 && !s4 && !s5) return -20;
  if (!s1 && s2 && s3 && !s4 && !s5) return -10;

  if (!s1 && !s2 && s3 && !s4 && !s5) return 0;

  if (!s1 && !s2 && s3 && s4 && !s5) return 10;
  if (!s1 && !s2 && !s3 && s4 && !s5) return 20;
  if (!s1 && !s2 && !s3 && s4 && s5) return 30;
  if (!s1 && !s2 && !s3 && !s4 && s5) return 40; 

  return previousError; 
}

void driveMotors(int leftSpeed, int rightSpeed) {
  if (leftSpeed == 0 && rightSpeed == 0) {
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    return;
  }

  if (leftSpeed >= 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, leftSpeed);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, -leftSpeed); 
  }

  if (rightSpeed >= 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, rightSpeed);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, -rightSpeed); 
  }
}

