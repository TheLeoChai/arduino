//randomly spin 2 servos
//2017-12-11
//Leo Chai
#include <Servo.h>                                                        // Include the Servo library 
int servoPin1 = 9;  
int servoPin2 = 10;                                                       // Declare the Servo pin 
int powerpin = 3;
long randNumber1;
long randNumber2;                                                         // set up for generating random number
Servo Servo1;
Servo Servo2;                                                             // Create the servo objects
void setup() { 
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2);                                              //attach the servos to the used pin number 
   randomSeed(analogRead(0));                                             //shuffle the random numbers
   pinMode(powerpin,OUTPUT);                                              //set up power supply due to partner's preferance on digital pins over 5v
}
void loop(){ 
   digitalWrite(powerpin,HIGH);                                           //power upply to motor because my partner does not want to use the 5v
   randNumber1 = random(180);
   randNumber2 = random(180);                                             //set up randome number generator
   Servo1.write(randNumber1);                                             // Make servo1 go to randome degrees 
   delay(500);                                                            //delay time for servo to adjust position
   Servo2.write(randNumber2);                                             // Make servo2 go to randome degrees 
   delay(500);                                                            //delay time for servo to adjust position
}
