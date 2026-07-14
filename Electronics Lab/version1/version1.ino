// ===============================
// 5 Sensor Line Follower Robot
// Black Line Detection
// ===============================

// Motor Driver Pins
#define ENA 6
#define ENB 5

#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10

// IR Sensors
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3
#define S5 A5

// Motor Speed (0-255)
int speedA = 180;
int speedB = 180;

void setup()
{
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);

  Serial.print(s1);
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.println(s5);

  // Center on line
  if(s3 == LOW)
  {
    forward();
  }

  // Slight Left
  else if(s2 == LOW)
  {
    left();
  }

  // Hard Left
  else if(s1 == LOW)
  {
    sharpLeft();
  }

  // Slight Right
  else if(s4 == LOW)
  {
    right();
  }

  // Hard Right
  else if(s5 == LOW)
  {
    sharpRight();
  }

  // No line
  else
  {
    stopMotor();
  }
}

//========================

void forward()
{
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//========================

void left()
{
  analogWrite(ENA, 120);
  analogWrite(ENB, 180);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//========================

void right()
{
  analogWrite(ENA, 180);
  analogWrite(ENB, 120);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//========================

void sharpLeft()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 180);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//========================

void sharpRight()
{
  analogWrite(ENA, 180);
  analogWrite(ENB, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//========================

void stopMotor()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}