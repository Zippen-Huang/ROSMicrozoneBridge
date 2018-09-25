#include <Servo.h>
Servo servoread1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servoread1.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ppm1 = servoread1.readMicroseconds();
  Serial.println(ppm1);
  
}
