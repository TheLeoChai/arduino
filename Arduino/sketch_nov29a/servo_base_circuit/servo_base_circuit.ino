// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin1 = 9; 
int servoPin2 = 10;
int powerpin = 3;
// set up for generating random number
long randNumber1;
long randNumber2;
// Create the servo objects
Servo Servo1;
Servo Servo2; 
void setup() { 
   //attach the servos to the used pin number 
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2);
   //shuffle the random numbers
   randomSeed(analogRead(0));
   pinMode(powerpin,OUTPUT);
}
void loop(){ 
   // Make servo1 go to randome degrees 
   digitalWrite(powerpin,HIGH);
   randNumber1 = random(180);
   randNumber2 = random(180);
   Servo1.write(randNumber1); 
   delay(1000); 
   // Make servo2 go to randome degrees 
   Servo2.write(randNumber2); 
   delay(1000); 
}
