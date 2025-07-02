#include "ServoSmooth.h"

ServoSmooth servo;

uint32_t myTimer;
int SensorPin = A0;  // analog pin used to connect the potentiometer
int val;             // variable to read the value from the analog

void setup() {

  servo.attach(2);  // Digital pin for servo signals
  servo.setSpeed(410);   // speed limit
  servo.setAccel(0.95);  // acceleration
  pinMode(13, OUTPUT); // standard command, let it be
}
void loop() {
  // set desired servo position using setTargetDeg(angle) or setTarget(impuls length)
  // when tick() is invoked, move servo with set speed and acceleration
  boolean state = servo.tick();  // servo movement according to internal timer!
  if (millis() - myTimer >= 20) {
    myTimer = millis();
    val = analogRead(SensorPin);  // reads the value of the potentiometer (value between 0 and 1023)
    if (val >= 900) {
      servo.setTargetDeg(0);
    } else {
      servo.setTargetDeg(90);
    }
  }
}