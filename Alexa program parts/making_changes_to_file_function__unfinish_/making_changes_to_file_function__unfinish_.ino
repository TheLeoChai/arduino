//find text in file and read last part of the string setup------------------------------------------------------
#include <SD.h>
File.dataFile;
const int chipSelect=4;
void setup(){
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  if(!SD.begin(chipSelect)){
    Serial.print("SD card is not properly initialized");
  }
  dataFile=SD.open("datalog.txt");
}
// goes to the start of that line--------------------------------------------------------------------------------

int gotoLineof (char x, char y){
  int n=0;
  String coordinate = "";
  coordinate +=x;
  coordinate +=",";
  coordinate +=y;

  //loop the fallowing process untill found a result
  while(true){
  dataFile.seek(n);
  String fileString = readStringUntil(\r\n);
  int changeVal=sizeof(fileString);
  if(find_text(coordinate,fileString){
    n-=changeVal;
    break
  }
  else {
  changeVal+=4;
  n+=changeVal;
  }
  }
  dataFile.seek (n);
  return n;
}
//goes after gotoLineof function to read to get the string for coordinates-----------------------------------------

String coordinateStr = readStringUntil(\r\n);
//then seperate the string into three (x cordinate, y coordinate and n for sureness of blockage existance----------

int xVal(String inputStr){
  String xval;
  
  int loc1 = inputStr.indexOf(',');
  loc1-=1;
  inputStr.remove(loc1);
  xval=inputStr;
  
  //seperate x, and let xval equal to the string seperated
  //do not forget to delete the comma if any

  int numX=xval.toInt();
  return xval
}

int yVal(String inputStr){
  String yval;
  int loc1 = inputStr.indexOf(',');
  int loc2 = inputStr.lastIndexOf(',');
  loc2-=1;
  String yval = inputStr.substring(loc1,loc2);
  //seperate y, and let yval equal to the string seperated
  //do not forget to delete the comma if any

  
  int numY=yval.toInt();
  return numY;
}

int nVal(String inputStr){
  String nval;
  int loc2 = inputStr.lastIndexOf(',');
  String nval = inputStr.substring(loc2);
  //seperate n, and let nval equal to the string seperated
  //do not forget to delete the comma if any

  
  int numN=nval.toInt();
  return numN;
}

//make changes to n vale, used for reprinting
//false if area is blocked and true if area is clear
int nValChange(int nval,bool change){
  if(change&&nval!=0){
    nval-=1;
    return nval
  }
  else if(change&&nval==0){
    return nval
  }
  else if(!change&&nval<6){
    nval+=1;
    return nval;
  }
  else if(!change&&nval==6){
    return nval;
  }
}
//probably needs to go after all the values are defined with ------------------------------------------------------
void writeToFile(char x,char y,char n,int location){
  String printInStr="";
  String coordinateStr="";
  printInStr+=x;
  PrintInStr+=",";
  PrintInStr+=y;
  coordinateStr=PrintInStr;
  PrintInStr+=",";
  PrintInStr+=n;
  PrintInStr+="\r\n"
  if(dataFile.find(coordinateStr){
    dataFile.print(PrintInStr)
  }
  else{
    dataFile.seek(loation);
    //replace the next line with this string***************************************************
  }
}

//required for go to line of function------------------------------------------------------------------------------
bool find_text(String needle, String haystack) {
  int foundpos = -1;
  for (int i = 0; i <= haystack.length() - needle.length(); i++) {
    if (haystack.substring(i,needle.length()+i) == needle) {
      foundpos = i;
    }
  }
  if (foundpos==-1){
    return false;
  }
  else{
    return true;
  }
}

