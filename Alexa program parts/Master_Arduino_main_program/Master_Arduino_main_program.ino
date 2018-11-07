#include <SD.h>
#include<Wire.h>
const int chipSelect = 4;
int xPos, yPos, tempVal;
typedef void(*MonvementFunction)();
MovementFunction Move[4]={&goFor,&goBac,&goLef,&goRig};
typedef void(*SenseDistFunction)();
SenseDistFunction SenseDis[4]={&distanceFront,&DdstanceBack,&distanceLeft,&distanceRight};
/*-----------------------------------------------------------------------------------------------*/
void setup() {
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  char FileExist = SD.exists("datalog.txt")
  File dataFile = SD.open("datalog.txt");
  if(FileExist){
    //read and write to file while also navigating

    
  }
  else if(!FileExist){
    //do not navigate, go around and map, close after finished
    xPos=0;
    yPos=0;
    if(compareDis()=1){
      //front
      tempVal=distanceFront();
      SendOrder(8,1);
      while(true){
        if(distanceFront()<=10){
          break;
        }
      }
      SendOrder(9,0);
      
    }
    else if(compareDis()=2){
      //back
      
      SendOrder(8,0);
      while(true){
        if(distanceBack()<=10){
          break;
        }
      }
      SendOrder(9,0);

      
    }
    else if(compareDis()=3){
      //left
      SendOrder(7,1);
      while(true){
        if(distanceLeft()<=10){
          break;
        }
      }
      SendOrder(9,0);

      
    }
    else if(compareDis()=4){
      //right
      SendOrder(7,0);
      while(true){
        if(distanceRight()<=10){
          break;
        }
      }
      SendOrder(9,0);
    }
  }
}
/*-----------------------------------------------------------------------------------------------*/
//1=> front; 2=>back; 3=>left; 4=>right
void MapN(int Dir, int TurnDir){
int CurDis;
int 2ndSenseDir=1/6*TurnDir*TurnDir*TurnDir-2*TurnDir*TurnDir+35/6*TurnDir-1
CurDis=SenseDis[TurnDir]
Move[TurnDir];
while(
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
void UpdatePos(int val,char dir,int x,int y){
  int Dist, sign, ans, n;
  if(dir=front){
    Dist=distanceFront();
    sign=1;
  }
  else if(dir=back){
    Dist=distanceBack();
    sign=-1;
  }
  else if(dir=left){
    Dist=distanceLeft();
    sign=-1;
  }
  else if(dir=right){
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
      int distance[] = {distanceFront(),distanceBack,distanceLeft,distanceRight};
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
  SendOrder(8,1);
}
void goBac(){
  SendOrder(8,0);
}
void goLef(){
  SendOrder(7,1);
}
void goRig(){
  SendOrder(7,0);
}
/*-----------------------------------------------------------------------------------------------*/
bool TestDis (int distanceF,int distanceB){
  
}

