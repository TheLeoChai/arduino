const int pingPinF=8;
const int pingPinB=5;
const int pingPinL=2;
const int pingPinR=0;
const int SenseF=9;
const int SenseB=6;
const int SenseL=3;
const int SenseR=1;
float duration, cm;
void setup(){
  Serial.begin(9600);
  //test
  Serial.println(distanceFront());
  Serial.println(distanceBack());
  Serial.println(distanceLeft));
  Serial.println(distanceRight));
}
 //sense 3-400cm?
int distanceFront(){
  pinMode(pingPinF,OUTPUT);
  digitalWrite(pingPinF,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinF,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPinF,LOW);

  pinMode(SenseF,INPUT);
  duration=pulseIn(SenseF,HIGH);
  cm=duration/29/2;
  int f=round(cm);
  Serial.print("distance is ");
  Serial.println(f);
  return f;
  }
int distanceBack(){
  pinMode(pingPinB,OUTPUT);
  digitalWrite(pingPinB,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinB,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPinB,LOW);

  pinMode(SenseB,INPUT);
  duration=pulseIn(SenseB,HIGH);
  cm=duration/29/2;
  int b=round(cm);
  Serial.print("distance is ");
  Serial.println(b);
  return b;
  }
  int distanceLeft(){
  pinMode(pingPinL,OUTPUT);
  digitalWrite(pingPinL,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinL,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPinL,LOW);

  pinMode(SenseL,INPUT);
  duration=pulseIn(SenseL,HIGH);
  cm=duration/29/2;
  int l=round(cm);
  Serial.print("distance is ");
  Serial.println(l);
  return l;
  }
  int distanceRight(){
  pinMode(pingPinR,OUTPUT);
  digitalWrite(pingPinR,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinR,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPinR,LOW);

  pinMode(pingPinR,INPUT);
  duration=pulseIn(SenseR,HIGH);
  cm=duration/29/2;
  int r=round(cm);
  Serial.print("distance is ");
  Serial.println(r);
  return r;
  }
