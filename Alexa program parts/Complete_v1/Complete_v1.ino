#include <SD.h>
#include <Wire.h>
const int chipSelect=4;
int XPOS=0;
int YPOS=0;
bool Warning[];
int Opposite[]={2,1,4,3};
int Dir,Prev,HoleCount,WallDir;
bool HOLES;
typedef void (*WallDirectionFunction)();
WallDirectionFunction WallDis[4]={distanceFront,distanceBack,distanceLeft,distanceRight};
#define For 1
#define Bac 2
#define Lef 3
#define Rig 4
/////////////////////////////////////////////////////////////////////////////////////////////////
void setup(){
  //setup SD card
  setupCard();
  //initialize and install SD card
  setupFile();
  while(true){
  DeterminCloseDirection()
  GoDir(Dir);
  if(distanceFront<=35||distanceBack<=35||distanceRight<=35||distanceLeft<=35){
    SendOrder(9,0);
    break;
  }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void loop(){
  HolesCountWarning
  ToGoDir();
  GoDir(Dir);
  //normal mapping
  if(Surrounded){//if face a blocked turn
    FindNewDir();//set to new direction
    while(Surrounded){
    goDir(Dir);//go until no longer face wall
    }
    if(FindHole){
      HOLES++;
    }
  }
    if(FindHole){
      HOLES++;
    }
}
void DeterminCloseDirection(){
if(distanceFront<=distanceBack&&distanceFront<=distanceLeft&&distanceFront<=distanceRight){
  Dir=1;
  
}
else if(distanceBack<=distanceFront&&distanceBack<=distanceRight&&distanceBack<=distanceLeft){
  Dir=2;
}
else if(distanceLeft<=distanceFront&&distanceLeft<=distanceBack&&distanceLeft<=distanceRight){
  Dir=3;
}
else if(distanceRight<=distanceFront&&distanceRight<=distanceBack&&distanceRight<=distanceLeft){
  Dir=4;
}
}
bool Surrounded(){
  int StopCount=0;
  if(distanceFront==35){
    StopCount++;
    Warning[1]=true;
  }
  if(distanceBack==35){
    StopCount++;
    Warning[2]=true;
  }
  if(distanceLeft==35){
    StopCount++;
    Warning[3]=true;
  }
  if(distanceRight==35){
    StopCount++;
    Warning[4]=true;
  }
  if(StopCount==1){
    return false;
  }
  else if(StopCount==0){//need fix goto hole senario
    return false;
  }
  else{
    return true;
  }
}
void ToGoDir(){
  if(distanceFront==35){
    Dir=3;
  }
  else if(distanceBack==35){
    Dir=4;
  }
  else if(distanceLeft==35){
    Dir=1;
  }
  else if(distanceRight==35){
    Dir=2;
  }
}
void FindNewDir(){
  if(Warning[1]==false&&Dir!=Opposite[1]){
    Dir=1;
  }
  else if(Warning[2]==false&&Dir!=Opposite[2]){
    Dir=2;
  }
  else if(Warning[3]==false&&Dir!=Opposite[3]){
    Dir=3;
  }
  else if(Warning[4]==false&&Dir!=Opposite[4]){
    Dir=4;
  }
  else{
    Dir=Opposite[Dir];
  }
}
void FindWall(){
  if(distanceFront=35&&distanceBack>35&&distanceLeft>35&&distanceRight>35){
    WallDir=1;
  }
  else if(distanceBack=35&&distanceFront>35&&distanceLeft>35&&distanceRight>35){
    WallDir=2;
  }
  else if(distanceLeft=35&&distanceBack>35&&distanceFront>35&&distanceRight>35){
    WallDir=3;
  }
  else if(distanceRight=35&&distanceBack>35&&distanceLeft>35&&distanceFront>35){
    WallDir=4;
  }
}
void HolesCountWarning(){
  if(WallDis[WallDir]>35){
    HoleCount++;
  }
  else if(WallDis[WallDir]=35){
    HoleCounter=0;
  }
}
bool FindHole(){
  int TempDisVal=WallDis[WallDir];
  if(HoleCount>=62){
    for(int p=0;p<31;p++){
      goDir(Opposite[Dir]);
    }
    while(WallDis[WallDir]>35){
      goDir(WallDir);
    }
    int DistanceTravel=WallDis[Dir]+WallDis[Opposite[Dir]]-31;
    if(WallDis[Dir]>35){
      return false;
    }
    else if(WallDis[Opposite[Dir]]>35){
      Dir=Opposite[Dir];
      return false;
    }
    else{
      while(WallDis[WallDir]<TempDisVal){
        goDir(Opposite[WallDir]);
      }
      for(int e=0;e<DistanceTravel;e++){
        goDir(Dir);
      }
      return true;
    }
  }
  else{
    false
  }
}

