#include <Wire.h>
#include <Servo.h>
int n=1;//adress
int turndelay = ;//time for arm to turn 90 degrees in half speed
int CurrentDegree=0;
Servo myServo;

void setup(){
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
  myServo.attach(9);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  Wire.begin(n);
  Wire.onReceive(Recieve);
  Serial.begin(9600);
}

void GotoDegree(int degree){
myServo.write(degree);
}
//must have "CurretDegree=GotoDegree" after
//need to be fixed according to encoder
void goForward(){
 digitalWrite(7,HIGH);
 digitalWrite(6,LOW);
}

void goBackward(){
 digitalWrite(7,LOW);
 digitalWrite(6,HIGH);
}

void goLeft(){
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
}

void goRight(){
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
}

void Stop(){
digitalWrite(A0,LOW);
digitalWrite(A1,LOW);
digitalWrite(A2,LOW);
digitalWrite(A3,LOW);
digitalWrite(A4,LOW);
digitalWrite(0,LOW);
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
digitalWrite(3,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
}

void Recieve(int howMany){
    char f=Wire.read();
    char o=Wire.read();
    if(f=='0'){
      //function to reset robot
      
    }
    if(f=='1'){
      if(o=='1'){
        //function to hold the hand
      }
      else if(o=='0'){
        //function to release hand
      }
    }
    else if(f=='2'){
      if(o=='1'){
        //function to lift arm up
      }
      else if(o=='0'){
        //function to pull arm down
      }
    }
    else if(f=='3'){
      if(o=='1'){
        //function to reach forward
      }
      else if(o=='0'){
        ///function to pull back
      }
    }
    else if(f=='6'){
      if(o=='1'){
        //function to rotate arm to 0
        GotoDegree(0);
        CurrentDegree=0;
      }
      else if(o=='2'){
        //function to rotate arm to 90
        GotoDegree(90);
        CurrentDegree=90;
      }
      else if(o=='3'){
        //function to rotate arm to 180
        GotoDegree(180);
        CurrentDegree=180;
      }
      else if(o=='4'){
        //function to rotate arm to 270
        GotoDegree(270);
        CurrentDegree=270;
      }
    }
    else if(f=='7'){
      if(o=='1'){
        //function to go forward 
        goForward();
      }
      else if(o=='0'){
        //function to go backward
        goBackward();
      }
    }
    else if(f=='8'){
      if (o=='1'){
        //function to go left
        goLeft();
      }
      else if(o=='0'){
        //function to go right
        goRight();
      }
    }
    else if(f=='9'){
      //stop all motors
      Stop();
    }
  }

