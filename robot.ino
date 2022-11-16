#include "AFMotor.h"
#include <Servo.h>

#define echopin 2
#define trigpin 13

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

const int distanceBack = 20;

void setup()
{
  Serial.begin(9600);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  myservo.attach(10);

  myservo.write(90);

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  Serial.println("Start");
}

void loop()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  if (calculateDistance() <= distanceBack)
  {
    while (calculateDistance() <= distanceBack * 2)
    {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    }
    
    myservo.write(0);

    delay(300);

    int distance0 = calculateDistance();

    myservo.write(170);

    delay(500);

    int distance1 = calculateDistance();

    myservo.write(90);

    if (distance0 > distance1)
    {
      int until = millis() + 2500;

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
      int until = millis() + 2500;

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