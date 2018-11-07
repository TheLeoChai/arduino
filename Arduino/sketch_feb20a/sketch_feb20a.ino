#include <Servo.h>
Servo myServo;
void setup() {
  // put your setup code here, to run once:
myServo.attach(3);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
myServo.write(180);
Serial.println(180);
delay(1000);
myServo.write(90);
Serial.println(90);
delay(1000);
myServo.write(0);
Serial.println(0);
delay(1000);
}
