#include "controlLibrary.h"

move::move(){
int direction1=12 ;
int direction2=13 ;
int brake1=9 ;
int brake2=8 ;
int motor1=3 ;  // motor 1 controll front and back  motor 2 controll left and right
int motor2=11 ; //motor moving pins setup
#define forWard HIGH 
#define backWard LOW 
#define left HIGH 
#define right LOW  
#define off LOW 
#define on HIGH 
}
void setupMovement (){
  pinMode(direction1,OUTPUT);
  pinMode(direction2,OUTPUT);
  pinMode(brake1,OUTPUT);
  pinMode(brake2,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  Serial.begin(9600);
}

//start to go forward command, no stop included in this function, there for need to manually stop in command
//call by: goForward
void Forward (){
  digitalWrite(direction1, forWard);
  digitalWrite(motor1,on);
  digitalWrite(brake1,off);
  digitalWrite(brake2,on);
  digitalWrite(motor2,off);
  Serial.println("going forward");
}

//start to go backward command, no stop included in this function, there for need to manually stop in command
//call by: goBackward
void Backward (){
  digitalWrite(direction1,backWard);
  digitalWrite(motor1,on);
  digitalWrite(brake1,off);
  digitalWrite(brake2,on);
  digitalWrite(motor2,off);
  Serial.println("going backward");
}

//start to go left command, no stop included in this function, there for need to manually stop in command
//call by: goLeft
void Left (){
  digitalWrite(direction2,left);
  digitalWrite(motor2,on);
  digitalWrite(brake2,off);
  digitalWrite(brake1,on);
  digitalWrite(motor1,off);
  Serial.println("going left");
}

//start to go right command, no stop included in this function, there for need to manually stop in command
//call by: goRight
void Right(){
  digitalWrite(direction2,right);
  digitalWrite(motor2,on);
  digitalWrite(brake2,off);
  digitalWrite(brake1,on);
  digitalWrite(motor1,off);
  Serial.println("going right");
}

//function used to stop the robot from moving and held still
//called by: stopRobot
void Stop (){
  digitalWrite(motor1,off);
  digitalWrite(motor2,off);
  digitalWrite(brake1,on);
  digitalWrite(brake2,on);
  Serial.println("Stop")
}

//special function, not sure if needed. used if want to manually push robot and move around
//called by: enableManualChange
void enableManualChange (){
  digitalWrite(motor1,off);
  digitalWrite(motor2,off);
  digitalWrite(brake1,off);
  digitalWrite(brake2,off);
  Serial.println ("now available for manual adjustment");
}

