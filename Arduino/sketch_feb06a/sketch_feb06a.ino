int PC=0;
//0=all release, 1=hold all, 2=hold 2, 3=hold 1
bool LasBS,CurBS;

int BP=3;
int Pin[3]={9,10,11};
void setup() {
  // put your setup code here, to run once:
pinMode(BP,INPUT);
pinMode(Pin[1],OUTPUT);
pinMode(Pin[2],OUTPUT);
pinMode(Pin[3],OUTPUT);
LasBS=LOW;
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  CurBS=digitalRead(BP);
  if(CurBS!=LasBS){
    if(digitalRead(BP)==HIGH){
      changeCount();
      Serial.println("Sense change");
    }
  }
  Write();
  LasBS=CurBS;
  delay(100);
  
}

void changeCount(){
  if(PC==0){
    PC=1;
  }
  else if(PC==1){
    PC=2;
  }
  else if(PC==2){
    PC=3;
  }
  else if(PC==3){
    PC=0;
  }
}

void Write(){
  if(PC==0){
    //release all
    digitalWrite(Pin[1],LOW);
    digitalWrite(Pin[2],LOW);
    digitalWrite(Pin[3],LOW);
    Serial.println("000");
  }
  else if(PC==1){
    //hold all
    digitalWrite(Pin[1],HIGH);
    digitalWrite(Pin[2],HIGH);
    digitalWrite(Pin[3],HIGH);
    Serial.println("111");
  }
  else if(PC==2){
    //hold 2
    digitalWrite(Pin[1],LOW);
    digitalWrite(Pin[2],HIGH);
    digitalWrite(Pin[3],HIGH);
    Serial.println("011");
  }
  else if(PC==3){
    //hold 1
    digitalWrite(Pin[1],LOW);
    digitalWrite(Pin[2],LOW);
    digitalWrite(Pin[3],HIGH);
    Serial.println("001");
  }
  
}

