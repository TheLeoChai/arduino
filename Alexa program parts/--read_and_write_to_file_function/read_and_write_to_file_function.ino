#include <SD.h>
File dataFile;
const int chipSelect=4;//CSpin
void setup(){
  Serial.begin(9600);
  
}
//require the fallowing line before
//dataFile=SD.open("datalog.txt",FILE_READ);
//returns wheather if the place is open or not
//1 stand for open and 0 stand for closed
int areaFind(int x,int y){
if (dataFile.find("("x","y")")){
  return 1;
}
else{
  return 0;
}
  }
  
//require the fallowing line
//dataFile=SD.open("datalog.txt",FILE_WRITE);
//1 stand for open and 0 stand for closed
void areaWrite (char x,char y,){
char PrintStr[]={"(",x,",",y,")");
dataFile.print(PrintStr[1]);
dataFile.print(PrintStr[2]);
dataFile.print(PrintStr[3]);
dataFile.print(PrintStr[4]);
dataFile.println(PrintStr[5]);
}


