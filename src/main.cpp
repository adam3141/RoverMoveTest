#include <Arduino.h>

// Pins that control the motors
constexpr int PIN_DIR_L = 12;
constexpr int PIN_DIR_R = 11;
constexpr int PIN_PWM_L = 6;
constexpr int PIN_PWM_R = 5;
constexpr int MAX_PWM = 167; // This will ensure we don't exceed an average of 6V on the motors

void setup()
{
  // put your setup code here, to run once:
  digitalWrite(PIN_DIR_L, LOW);
  digitalWrite(PIN_DIR_R, LOW);
  digitalWrite(PIN_PWM_L, LOW);
  digitalWrite(PIN_PWM_R, LOW);
  pinMode(PIN_DIR_L, OUTPUT);
  pinMode(PIN_DIR_R, OUTPUT);
  pinMode(PIN_PWM_L, OUTPUT);
  pinMode(PIN_PWM_R, OUTPUT);

  // Let's wait 5s before we do anything
  delay(5000);
}

void moveForward()
{
  // Set direction for both motors
  digitalWrite(PIN_DIR_L, HIGH);
  digitalWrite(PIN_DIR_R, LOW);
  analogWrite(PIN_PWM_L, MAX_PWM);
  analogWrite(PIN_PWM_R, MAX_PWM);
}

void moveBackwards()
{
  // Set direction for both motors
  digitalWrite(PIN_DIR_L, LOW);
  digitalWrite(PIN_DIR_R, HIGH);
  analogWrite(PIN_PWM_L, MAX_PWM);
  analogWrite(PIN_PWM_R, MAX_PWM);
}

void turnCW()
{
  digitalWrite(PIN_DIR_L, HIGH);
  digitalWrite(PIN_DIR_R, HIGH);
  analogWrite(PIN_PWM_L, MAX_PWM);
  analogWrite(PIN_PWM_R, MAX_PWM); 
}

void turnCCW()
{
  digitalWrite(PIN_DIR_L, LOW);
  digitalWrite(PIN_DIR_R, LOW);
  analogWrite(PIN_PWM_L, MAX_PWM);
  analogWrite(PIN_PWM_R, MAX_PWM); 
}

void stop()
{
  // Use the digital write functions to turn them off as the analog write
  // does not fully turn them off with a PWM value of 0.
  digitalWrite(PIN_PWM_L, LOW);
  digitalWrite(PIN_PWM_R, LOW);
}

void loop()
{
  moveForward();
  delay(10000);
  stop();


  // // put your main code here, to run repeatedly:
  // for (int i=0; i<2; i++)
  // {
  //   moveForward();
  //   delay(4000);
  //   stop();
  //   turnCW();
  //   delay(900);
  //   stop();
  //   delay(500);
  //   moveForward();
  //   delay(2000);
  //   stop();
  //   turnCW();
  //   delay(900);
  //   stop();
  //   delay(500);
  // }

  // delay(3000);

  // for (int i=0; i<2; i++)
  // {
  //   moveForward();
  //   delay(4000);
  //   stop();
  //   turnCCW();
  //   delay(900);
  //   stop();
  //   delay(500);
  //   moveForward();
  //   delay(2000);
  //   stop();
  //   turnCCW();
  //   delay(900);
  //   stop();
  //   delay(500);
  // }

  while(1) {
    delay(3000);
  }
  
  // // Fwd - then stop
  // moveForward();
  // delay(2000);
  // stop();
  // delay(2000);

  // // Rev - then stop
  // moveBackwards();
  // delay(2000);
  // stop();
  // delay(2000);

  // // Turn CW + CCW
  // turnCW();
  // delay(1000);
  // turnCCW();
  // delay(1000);
  // stop();
  // delay(1000);

}