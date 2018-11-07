#include <Servo.h>

Servo Xcontrol;
Servo Ycontrol;

void setup(){
  Xcontrol.attach(9);
  Ycontrol.attach(10);
  Xcontrol.write(90);
  Ycontrol.write(90);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
}
void loop(){
  while(digitalRead(7)==HIGH){
    GoFor();
  }
  while(digitalRead(8)==HIGH){
    GoBac();
  }
  while(digitalRead(12)==HIGH){
   GoLef();
  }
  while(digitalRead(13)==HIGH){
   GoRig(); 
  }
  while(digitalRead(7)==LOW&&digitalRead(8)==LOW&&digitalRead(12)==LOW&&digitalRead(13)==LOW){
    Stop();
  }
}
void GoFor(){
  Ycontrol.write(180);
}
void GoBac(){
  Ycontrol.write(0);
}
void GoLef(){
  Xcontrol.write(180);
}
void GoRig(){
  Xcontrol.write(0);
}
void Stop(){
  Xcontrol.write(90);
  Ycontrol.write(90);
}

