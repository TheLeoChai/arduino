#include <SD.h>
#include<Wire.h>
const int chipSelect = 4;
int xPos, yPos, tempVal;
typedef void(*MonvementFunction)();
MovementFunction Move[4]={&goFor,&goBac,&goLef,&goRig};
typedef void(*SenseDistFunction)();
SenseDistFunction SenseDis[4]={&distanceFront,&DdstanceBack,&distanceLeft,&distanceRight};
/*-----------------------------------------------------------------------------------------------*/
//1=> front; 2=>back; 3=>left; 4=>right
void MapN(int Dir, int TurnDir){
int CurDis;
int 2ndSenseDir=1/6*TurnDir*TurnDir*TurnDir-2*TurnDir*TurnDir+35/6*TurnDir-1
CurDis=SenseDis[TurnDir]
Go1cm(TurnDir,2ndSenseDir);

}
/*-----------------------------------------------------------------------------------------------*/

void MapF(int x, int y){
  int X1,Y1,num, val, loc;
  f=distanceFront();
  b=distanceBack();
  l=distanceLeft();
  r=distanceRight();
  for(i=0;i<f;i++){
    i=num;
    Y1=y+num;
    int loc=gotoLineof(x,Y1);
    dataFile.seek(loc);
    String coordinateStr = readStringUntil(\r\n);
    val=nValChange(nVal(coordinateStr),true);
    writeToFile(x,Y1,vak,loc);
  }
  Y1=0;
  num=0;
  val=0;
  loc=0;
  for(i=0;i<b;i++){
    i=num;
    Y1=y-num;
    int loc=gotoLineof(x,Y1);
    dataFile.seek(loc);
    String coordinateStr = readStringUntil(\r\n);
    val=nValChange(nVal(coordinateStr),true);
    writeToFile(x,Y1,vak,loc);
  }
  Y1=0;
  num=0;
  val=0;
  loc=0;
  for(i=0;i<l;i++){
    i=num;
    X1=x+num;
    int loc=gotoLineof(X1,y);
    dataFile.seek(loc);
    String coordinateStr = readStringUntil(\r\n);
    val=nValChange(nVal(coordinateStr),true);
    writeToFile(X1,y,vak,loc);
  }
  X1=0;
  num=0;
  val=0;
  loc=0;
  for(i=0;i<r;i++){
    i=num;
    X1=x-num;
    int loc=gotoLineof(X1,y);
    dataFile.seek(loc);
    String coordinateStr = readStringUntil(\r\n);
    val=nValChange(nVal(coordinateStr),true);
    writeToFile(X1,y,vak,loc);
  }
  X1=0;
  num=0;
  val=0;
  loc=0;
}

/*-----------------------------------------------------------------------------------------------*/
//input the distance senced from befor, direction headed (1,2,3,4) and current x,y value
void UpdatePos(int val,int dir,int x,int y){
  int Dist, sign, ans, n;
  if(dir=1){
    Dist=distanceFront();
    sign=1;
  }
  else if(dir=2){
    Dist=distanceBack();
    sign=-1;
  }
  else if(dir=3){
    Dist=distanceLeft();
    sign=-1;
  }
  else if(dir=4){
    Dist=distanceRight();
    sign=1
  }
  n=val-Dist;
  ans=n*sign;
  if(dir=front||dir=back){
    ans+=x;
    xPos=ans;
  }
  else if(dir=left||dir=right){
    ans+=y;
    yPos=ans;
  }
  
}
/*-----------------------------------------------------------------------------------------------*/
int compareDis (){
      int distance[] = {distanceFront(),distanceBack(),distanceLeft(),distanceRight()};
      if(distance[1]>distance[2]&&distance[1]>distance[3]&&distance[1]>distance[4]){
      return 1;
    }
    else if(distance[2]>distance[1]&&distance[2]>distance[3]&&distance[2]>distance[4]){
      return 2;
    }
    else if(distance[3]>distance[2]&&distance[3]>distance[1]&&distance[3]>distance[4]){
      return 3;
    }
    else if(distance[4]>distance[1]&&distance[4]>distance[2]&&distance[4]>distance[3]){
      return 4;
    }
}
/*-----------------------------------------------------------------------------------------------*/
void goFor(){
  int goForDis=SenseDir[1];
  SendOrder(8,1);
  UpdatePos(goForDis,1,xPos,yPos);
}
void goBac(){
  int goBacDis=SenseDir[2];
  SendOrder(8,0);
  UpdatePos(goBacDis,2,xPos,yPos);
}
void goLef(){
  int goLefDis=SenseDir[3];
  SendOrder(7,1);
  UpdatePos(goLefDis,3,xPos,yPos);
}
void goRig(){
  int goRigDis=SenseDir[4];
  SendOrder(7,0);
  UpdatePos(goRigDis,4,xPos,yPos);
}
void goSto(){
  SendOrder(9,0);
}
/*-----------------------------------------------------------------------------------------------*/
//1=forward; 2=backward; 3=left; 4=right
void Go1cm(int moveDir,int OppDir){
  int a,b;
  a=SenseDir[moveDir];
  b=SenseDir[OppDir];
  Move[moveDir];
  while(true){
    c=SenseDir[moveDir];
    d=SenseDir[OppDir];
    
    if(a-c==1||d-b==1){
      goSto();
      break;
    }
    UpdatePos(a,moveDir,xPos,yPos);
  }
}

