#include <Wire.h>
int reset = 0;
int Hand = 1;
int Arm = 2;
int Reach = 3;
int Rotate = 4;
int MoveX = 7;
int MoveY = 8;
int Stop = 9;

int goLeft = 1;
int goRight = 0;
int goForw = 1;
int goBackw = 0;
int goUp = 1;
int goDown = 0;
int hold = 1;
int Release = 0;
int Rotate0 = 1;
int Rotate90 = 2;
int Rotate180 = 3;
int Rotate270 = 4;

void setup() {
  // put your setup code here, to run once:
Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
//always need to send two byteo of info
void SendOrder(char function, char order){
  Wire.beginTransmission(1);
  Wire.write(function);
  //perhaps a space or comma? in middle
  Wire.write(order);
  Wire.endTransmission();
}

