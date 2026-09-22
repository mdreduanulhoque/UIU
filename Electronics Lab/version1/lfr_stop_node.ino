// Node detect and stop code
// Motor A (Left Motor) Pins
#define PWMA 5
#define AIN1 7
#define AIN2 8

// Motor B (Right Motor) Pins
#define PWMB 6
#define BIN1 9
#define BIN2 10

// IR Sensor Pins (Left to Right)
#define IR1 A0 // Far Left (OUT1)
#define IR2 A1 // Mid Left (OUT2)
#define IR3 A2 // Center   (OUT3)
#define IR4 A3 // Mid Right(OUT4)
#define IR5 A4 // Far Right(OUT5)

// Configure sensor logic 
const int BLACK = LOW; 

// PID and Speed Configuration
float Kp = 1.8;   
float Ki = 0.0;   
float Kd = 2.5;   

int baseSpeed = 80;  
int maxSpeed = 100;   

float P, I, D, previousError = 0;

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
}

void loop() {
  // Read sensors to check for nodes before applying PID
  bool s1 = (digitalRead(IR1) == BLACK); // Far Left
  bool s2 = (digitalRead(IR2) == BLACK); // Mid Left
  bool s3 = (digitalRead(IR3) == BLACK); // Center
  bool s4 = (digitalRead(IR4) == BLACK); // Mid Right
  bool s5 = (digitalRead(IR5) == BLACK); // Far Right

  // NODE DETECTION LOGIC
  bool fullNode  = (s1 && s2 && s3 && s4 && s5); 
  bool leftNode  = (s1 && s2 && s3 && !s4 && !s5);
  bool rightNode = (!s1 && !s2 && s3 && s4 && s5);

  if (fullNode || leftNode || rightNode) {
    driveMotors(0, 0); // Stop the motors
    while(true);       // Infinite loop to halt the robot indefinitely. 
                       // (Remove this while loop if you only want a temporary pause)
  }

  // If no node is detected, continue normal line following
  int error = calculateError();
  
  // Calculate PID
  P = error;
  I = I + error;
  D = error - previousError;
  previousError = error;

  int correction = (Kp * P) + (Ki * I) + (Kd * D);

  // Apply correction to motors
  int leftMotorSpeed = baseSpeed + correction;
  int rightMotorSpeed = baseSpeed - correction;

  // Constrain speeds to valid PWM range
  leftMotorSpeed = constrain(leftMotorSpeed, -maxSpeed, maxSpeed);
  rightMotorSpeed = constrain(rightMotorSpeed, -maxSpeed, maxSpeed);

  driveMotors(leftMotorSpeed, rightMotorSpeed);
}

int calculateError() {
  bool s1 = (digitalRead(IR1) == BLACK);
  bool s2 = (digitalRead(IR2) == BLACK);
  bool s3 = (digitalRead(IR3) == BLACK);
  bool s4 = (digitalRead(IR4) == BLACK);
  bool s5 = (digitalRead(IR5) == BLACK);

  // 1. All White Condition
  if (!s1 && !s2 && !s3 && !s4 && !s5) {
    return previousError; 
  }

  // 2. Thick line / crossing recovery (Nodes are handled in loop now, but this is a fallback)
  if (s2 && s3 && s4) return 0;             

  // 3. Fine-Tuned Proportional Line Following
  // Left Deviations
  if (s1 && !s2 && !s3 && !s4 && !s5) return -40; // Line is far left
  if (s1 && s2 && !s3 && !s4 && !s5) return -30;
  if (!s1 && s2 && !s3 && !s4 && !s5) return -20;
  if (!s1 && s2 && s3 && !s4 && !s5) return -10;

  // Perfect Center
  if (!s1 && !s2 && s3 && !s4 && !s5) return 0;

  // Right Deviations
  if (!s1 && !s2 && s3 && s4 && !s5) return 10;
  if (!s1 && !s2 && !s3 && s4 && !s5) return 20;
  if (!s1 && !s2 && !s3 && s4 && s5) return 30;
  if (!s1 && !s2 && !s3 && !s4 && s5) return 40; // Line is far right

  // 4. Fallback
  return previousError; 
}

void driveMotors(int leftSpeed, int rightSpeed) {
  if (leftSpeed == 0 && rightSpeed == 0) {
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    return;
  }

  // Left Motor
  if (leftSpeed >= 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, leftSpeed);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, -leftSpeed); 
  }

  // Right Motor
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

