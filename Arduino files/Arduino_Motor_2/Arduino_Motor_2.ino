//motor alternating turning speed with button control
//2017-12-3
//Leo Chai
int motorPin=10;//pin which motor control wire connected to
int buttonPin=1;//pin where button is connected to 
int n=0;//set value of n to 0
void setup() {
  // put your setup code here, to run once:
pinMode(motorPin,OUTPUT);//output to control motor
pinMode(buttonPin,INPUT);//input to sense button pushed or not
}

void loop() {
if(buttonPin==HIGH){//start motor if button is pushed
  for( int i=0; i<=255;i++){
    analogWrite(motorPin, i);//motor spins faster and faster before limit
    if(buttonPin==LOW){//contunuously check if button is still pressed
      break;//stop and contiue if button is not pressed
    }
  }
  if(buttonPin==LOW){// keep sensing if button is pressed
    break;//stop and continue if button is not pressed
  }
  for(int i=255;i>=1;i--){//after reaching the limit, start turning slower and slower
    analogWrite(motorPin,i);//turn motor
    if(buttonPin==LOW){//continuously check if bbutton is still pressed
      break;//stop and continue if button is not pressed
    }
  }
    if(buttonPin==LOW){//check again for if button is released
    break;//stop and continue program if button is released
}
}
