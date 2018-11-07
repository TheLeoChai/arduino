// Servo - Version: Latest 
#include <Servo.h>;
const int servopin = 9;
Servo myservo;
const int angleIncrement = 1;
const int incrementDelay = 10;
void setup() {
myservo.attach(servopin);
 

}

void loop() {

for (int angle = 0; angle < 180; angle += angleIncrement) { // single "degree" increments
 myservo.write (angle);
 delay (incrementDelay); // so we'll take 10 * 180 milliseconds = 1.8 seconds for the traverse.
}

}

