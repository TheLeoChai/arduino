//this file does not include functions for the robot arm
//controll forward and backward
const int Base1S=5;
const int Base1D=4;
//controll left and right
const int Base2S=6;
const int Base2D=7;
//controll Arm direction
const int Base3S=3;
const int Base3D=2;
int currentAngle=0;
const int R=;//set R to the amount of time needed for arm rotate one degree
//for direction pin, on goes forward or left and off goes back wards or right
void setup (){
  pinMode(Base1S,OUTPUT);
  pinMode(Base1D,OUTPUT);
  pinMode(Base2S,OUTPUT);
  pinMode(Base2D,OUTPUT);
  pinMode(Base3S,OUTPUT);
  pinMode(Base4D,OUTPUT);
  Serial.begin(9600);
}

//start to go forward command, no stop included in this function, there for need to manually stop in command
//call by: goForward
void goForward (){
  digitalWrite(Base1D,HIGH);
  analogWrite(Base2S,0);
  analogWrite(Base1S,123);
  Serial.println("going forward");
}

//start to go backward command, no stop included in this function, there for need to manually stop in command
//call by: goBackward
void goBackward (){
  digitalWrite(Base1D,LOW);
  analogWrite(Base2S,0);
  analogWrite(Base1S,123);
  Serial.println("going backward");
}

//start to go left command, no stop included in this function, there for need to manually stop in command
//call by: goLeft
void goLeft (){
  digitalWrite(Base2D,HIGH);
  analogWrite(Base1S,0);
  analogWrite(Base2S,123);
  Serial.println("going left");
}

//start to go right command, no stop included in this function, there for need to manually stop in command
//call by: goRight
void goRight(){
  digitalWrite(Base2D,LOW);
  analogWrite(Base1S,0);
  analogWrite(Base2S,123);
  Serial.println("going right");
}

//function used to stop the robot from moving and held still
//called by: stopRobot
void stopRobot (){
  analogWrite(Base1S,0);
  analogWrite(Base2S,0);
  Serial.println("Stopped")
}

//special function, not sure if needed. used if want to manually push robot and move around
//called by: enableManualChange
//no longer needed
/*
void enableManualChange (){
  digitalWrite(motor1,off);
  digitalWrite(motor2,off);
  digitalWrite(brake1,off);
  digitalWrite(brake2,off);
  Serial.println ("now available for manual adjustment");
}
*/
//need to do this function with the line after to reset angle
int TurnToPos(int angle){
  int turnDegree
  if(angle<CurrentAngle){
    turnDegree=CurrentAngle-angle;
    digitalWrite(Base3D,LOW);
    analogWrite(Base3S,123);
    int delayTime=turnDegree*R;
    delay(delayTime);
    analogWrite(Base3S,0);
  }
  else if(angle>CurrentAngle){
    turnDegree=Angle-CurrentAngle;
    digitalWrite(Base3D,HIGH);
    analogWrite(Base3S,123);
    int delayTime=TurnDegree*R;
    delay(delayTime);
    analogWrite(Base3S,9);
    digitalWrite(Base3D,LOW);
  }
    return angle;
}
CurrentAngle=TurntoPos
