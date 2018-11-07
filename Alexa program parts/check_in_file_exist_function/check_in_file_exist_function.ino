#include <SD.h>

const int chipSelect=4;//CSpin
File dataFile;


void setup(){
  Serial.begin(9600);
}

//insert file name in bracket when called
//returns value of 0 or 1
//0 means file not found, and 1 means file exist
bool FileExist (String fileName){
if(SD.exists(fileName)){
  return true;
}
else if (!SD.exists(fileName)){
  return false;
}
}

