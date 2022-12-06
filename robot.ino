#include "AFMotor.h"
#include <Servo.h>

#define echopin A1
#define trigpin A0

Servo myservo;

const int MOTOR_1 = 1;
const int MOTOR_2 = 2;
const int MOTOR_3 = 3;
const int MOTOR_4 = 4;

AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ);
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ);
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ);
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ);

long duration;

const int distanceBack = 30;

void setup()
{
  Serial.begin(9600);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  myservo.attach(10);

  myservo.write(90);

  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);

  Serial.println("Start");
}

void loop()
{
  if (calculateDistance() <= distanceBack)
  {
    Serial.println("Going back..");

    while (calculateDistance() <= distanceBack)
    {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    }
    
    myservo.write(0);

    delay(300);

    int distance0 = calculateDistance();

    myservo.write(180);

    delay(500);

    int distance1 = calculateDistance();

    myservo.write(90);

    if (distance0 > distance1)
    {
      int unsigned until = millis() + 2000;

      Serial.println("Turning right..");

      while (until > millis())
      {
        motor1.run(FORWARD);
        motor4.run(FORWARD);

        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
      }
    }

    else
    {
      int unsigned until = millis() + 2000;

      Serial.println("Turning left..");

      while (until > millis())
      {
        motor1.run(BACKWARD);
        motor4.run(BACKWARD);

        motor2.run(FORWARD);
        motor3.run(FORWARD);
      }
    }
  }

  else
  {
    Serial.println("Going forward..");
    
    myservo.write(90);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
}

long calculateDistance()
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  return duration * 0.034 / 2;
}