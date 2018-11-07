#include<Wire.h>
#include<SD.h>
const int straightpin=4;
const int backpin=5;
const int leftpin=6;
const int rightpin=7; //direction reading pins
const int LDRpin1=1;  //LDR sensor pins
const int direction1=12;
const int direction2=13;
const int brake1=9;
const int brake2=8;
const int motor1=3;   // motor 1 controll front and back; motor 2 controll left and right
const int motor2=11;  //motor moving pins setup
const int forWard=HIGH;
const int backWard=LOW; 
const int off=LOW;
const int on=HIGH;  //variables to make life easier
int x=0;
int y=0;  //cordinates for the map
void setup(){
  pinMode(straightpin,INPUT);
  pinMode(backpin,INPUT);
  pinMode(leftpin,INPUT);
  pinMode(rightpin,INPUT);
  pinMode(LDRpin1,INPUT);// sensor pin as output
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT); 
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);//controlling pins as input
  digitalWrite(brake1,on);
  digitalWrite(brake2,on);
}
void loop(){
if(digitalRead(straightpin==HIGH)) //funtion if recieve call of going forward
{
 //command to move forward
 
//retrieve counter of turn and save on sd: "(x,y) = 1, so that the map recognizes that this area is open
}
else if(digitalRead(backpin==HIGH)) //fuction if recieve call of going back
{
  //command to move back
  //retrieve counter of turn and save on SD: (x,y)=1, so that the map recognize that this area is open
}
else if(digitalRead(leftpin==HIGH)) //function if recieve call of going left
{
  //command to move left
  //retrieve counter of turn and save on SD: (x,y)=1, so that the map recognize that this area is open
}
else if(digitalRead(rightpin==HIGH)) //function if recieve call for going right
{
  //command to move right
  //retrieve counter of trun and save on SD: (x,y)=1, so that the ap recognize that this area is open2
}
 long countTurn(){//function for counting wheel truns and use for map
  long countTurn=0;
  ButtonState=digitalRead(LDRpin1);
  if (ButtonState!=LastButtonState){
    if(ButtonState==HIGH){
      countTurn++;
    }
    else if(ButtonState==LOW){
      ;
    }
  }
  return countTurn;
}
int RecieveNTurns(){
  while(1<Wire.available()){
    char x=Wire.read();
    return x;
  }
}
void MapOrFallowProcessor
void Go_Straight()
{
 digitalWrite(brake1,off);
 digitalWrite(direction1,forWard);
 digitalWrite(motor1, 255);
 
}

