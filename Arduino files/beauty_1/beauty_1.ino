int direction1=12;
int direction2=13;
int brake1=9;
int brake2=8;
int motor1=3;
int motor2=11;
void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
}

void loop() {
//HIGH=forward;LOW=backward
//LOW=close brake; HIGH=turn on brake
digitalWrite(brake1,HIGH);
digitalWrite(brake2,HIGH);
digitalWrite(direction1,HIGH);
digitalWrite(direction2,HIGH);
digitalWrite(motor1,255);
digitalWrite(motor2,255);
delay(5000);
digitalWrite(direction1,LOW);
digitalWrite(direction2,LOW);
digitalWrite(motor1,255);
digitalWrite(motor2,255);
delay(5000);
}
