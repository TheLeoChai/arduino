//button controlled motor
//2017-12-3
//Leo Chai
int motorPin=10;  //initialize pin names for motor and button
int buttonPin=1;

void setup() {
  // put your setup code here, to run once:
pinMode(motorPin,OUTPUT);  //set motor pin as output to control motor
pinMode(buttonPin,INPUT);  //set putton pin as input to sense button press
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(buttonPin）==HIGH){
  digitalWrite(motorPin,HIGH); //turn motor on if button is pushed
}
else if(digitalRead(buttonPin）==LOW){
  digitalWrite(motorPin,HIGH);  //turn motor off is button is not pressed
}
else{
  ;  //not nothing since there are no other cases
}
}
