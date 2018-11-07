#include<SPI.h>
#include<SD.h>

const int chipSelect=4;//CSpin

void setup (){
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  while(!Serial){
    Serial.println("please insert card");
  }
  if(!SD.begin(chipSelect)){
    Serial.println("SD card is not properly installed, program crashing...");
    while(1);
  }
}

