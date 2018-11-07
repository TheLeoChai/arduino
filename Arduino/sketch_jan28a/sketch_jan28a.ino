#define FR 9
#define BR 10
//
#define xAxis A4
#define yAxis A5
//
#define FL 5
#define BL 6
#define HC_SR04_VCC 0
#define HC_SR04_TRIGGER A1
#define HC_SR04_ECHO A2
#define HC_SR04_GND 0

int count = 1;
bool otherWay = false; //change this to true/false if you want to spin the other way first
bool seeYou = false;

int Xval,Yval,Dis;

  int lf,rf,lb,rb;
  int switchPin=A3;
void setup(){
  pinMode(12, INPUT_PULLUP);
  pinMode(HC_SR04_VCC, OUTPUT);
  digitalWrite(HC_SR04_VCC, HIGH);
  pinMode(HC_SR04_GND, OUTPUT);
  digitalWrite(HC_SR04_GND, LOW);
  pinMode(HC_SR04_TRIGGER, OUTPUT);
  pinMode(HC_SR04_ECHO, INPUT);
  pinMode(xAxis,INPUT);
  pinMode(yAxis,INPUT);
  pinMode(switchPin,INPUT);

  delay(5000); 
  
  pinMode(FR,OUTPUT);
  pinMode(BR,OUTPUT);
  pinMode(FL,OUTPUT);
  pinMode(BL,OUTPUT);
  Serial.begin(9600);

}

void loop(){
  while(digitalRead(switchPin)==HIGH){
  controll();
  }
  while(digitalRead(switchPin)==LOW){
    QuickSpinner();
  }
}

void controll(){
  FindVal();
  go();
  dis();
  if(Dis<15){
    Serial.print("WARNING, SHORT DISTANCE");
    Serial.print(Dis);
    Serial.println("cm");
  }
  else{
    Serial.print("distance is");
    Serial.print(Dis);
    Serial.println("cm");
  }
  
}
void FindVal(){
  Xval=map(analogRead(xAxis),0,1023,-255,255);
  Yval=map(analogRead(yAxis),0,1023,-255,255);
  Serial.print(Xval);
  Serial.print(";");
  Serial.println(Yval);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void go(){
  if(Xval<2&&Xval>-2){
    Xval=0;
  }
  if(Yval<2&&Yval>-2){
    Yval=0;
  }
  if(Xval>2&&Yval>2){
    //dir=fr
    lf=Yval;
    rf=Yval-Xval-Xval;
    if(rf<0){
      rb=abs(rf);
      rf=0;
    }
  }
  else if(Xval<-2&&Yval>2){
    //dir=fl
    rf=Yval;
    lf=Yval-abs(Xval)-abs(Xval);
    if(lf<0){
      lb=abs(lf);
      lf=0;
    }
  }
  else if(Xval>2&&Yval<-2){
    //dir=br
    lb=abs(Yval);
    rb=abs(Yval)-abs(Xval)-abs(Xval);
    if(rb<0){
      rf=abs(rb);
      rb=0;
    }
  }
  else if(Xval<-2&&Yval<-2){
    //dir=bl
    rb=abs(Yval);
    lb=abs(Yval)-abs(Xval)-abs(Xval);
    if(lb<0){
      lf=abs(lb);
      lb=0;
    }
  }
  if(Xval>-2&&Xval<2){
    //f&b
    if(Yval>2){
      //f
      lf=abs(Yval);
      rf=abs(Yval);
    }
    else if(Yval<2){
      //b
      lb=abs(Yval);
      rb=abs(Yval);
    }
  }
  if(Yval>-2&&Yval<2){
    //l&r
    if(Xval>2){
      //r
      lf=abs(Xval);
      rb=abs(Xval);
    }
    else if(Xval<-2){
      //l
      rf=abs(Xval);
      lb=abs(Xval);
    }
  }
  if(Yval>-2&&Yval<2&&Xval>-2&&Xval<2){
    //stop
    lf=0;
    rf=0;
    lb=0;
    rb=0;
  }
  analogWrite(FL,lf);
  analogWrite(FR,rf);
  analogWrite(BL,lb);
  analogWrite(BR,rb);
  //////
  /*
  Serial.print("FL:");
  Serial.println(lf);
  Serial.print("FR:");
  Serial.println(rf);
  Serial.print("BL:");
  Serial.println(lb);
  Serial.print("BR:");
  Serial.println(rb);
  Serial.print("\r");
  delay(1000);
  */
  ////// for testing
}

//////////////////////////////////////////////////////////////////////////////
void dis(){//works
  long duration, inches, cm;
  pinMode(HC_SR04_TRIGGER, OUTPUT);
  digitalWrite(HC_SR04_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(HC_SR04_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(HC_SR04_TRIGGER, LOW);
  pinMode(HC_SR04_ECHO, INPUT);
  duration = pulseIn(HC_SR04_ECHO, HIGH);
  cm = microsecondsToCentimeters(duration);
  Dis=cm;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
//////////////////////////////////////////////////////////////////////////////////////

void QuickSpinner(){
  {
    digitalWrite(HC_SR04_TRIGGER, LOW);
    delayMicroseconds(4);
    digitalWrite(HC_SR04_TRIGGER, HIGH);
    delayMicroseconds(20);
    digitalWrite(HC_SR04_TRIGGER, LOW);
    delayMicroseconds(10);
    long pulse_us = pulseIn(HC_SR04_ECHO, HIGH);
    int dist_cm = pulse_us / 59;
if (dist_cm>40)
{
 //spin one direction or the other

if (otherWay)
{
  analogWrite(FL,123);
analogWrite(FR,123);
analogWrite(BL,0);
analogWrite(BR,123);
}
else
{
  analogWrite(FL,123);
analogWrite(FR,123);
analogWrite(BL,123);
analogWrite(BR,0);  
}


seeYou = false;
}
else
{
//change direction to spin next time
if (seeYou == false)
 {   
  otherWay = !otherWay; 
 }
 seeYou = true;
 //go forward
 analogWrite(FL,123);
analogWrite(FR,123);
analogWrite(BL,0);
analogWrite(BR,0);
}

    delay(100);
}
}
 
