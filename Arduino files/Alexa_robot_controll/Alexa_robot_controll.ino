int n=10
#include <SD.h>  //include SD library
//SD uses some of the pins
void setup() {
File roomMap;
Serial.begin(9600);
if (!SD.begin(n))  // check if SD card is connected, n is what ever pin SD card is on
{  Serial.println("please connect the storage");}
else{
Serial.println("Opening the Map");


if (SD.exists("Map.txt"))   // if the file is available, write to it:
{
roomMap=SD.open("Map.txt",FILE_READ);//open and read the map and perform the function
if(roomMap){
  Serial.print("successfuly opened file"); 
  //perform function

  roomMap.close();} //close the file after finish
else
{
Serial.println("Fail opening file");
delay(30000);
return;
}
    }
  
  else {
 myFile=SD.open("Map.txt",FILE_WRITE) //create the file for the map and write on it
//mapping function
  }
}




void loop() {
  // put your main code here, to run repeatedly:

}
