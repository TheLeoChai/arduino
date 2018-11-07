
const int  LDRpin = 9;    
const int MotorPin = 10;       

int LDRPushCounter1,LDRPushCounter2 = 0;   
int LDRState1,LDRState2 = 0;     
int lastLDRState1,lastLDRState2 = 0; 
int Millis1,Millis2,Millis3,Millis4,difference1,difference2;

void setup() {
  pinMode(LDRpin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  LDRState = digitalRead(LDRpin);
  Millis1=millis()
  digitalWrite(MotorPin,HIGH);
while(true){
  if (LDRState1 != lastLDRState1) {
    if (LDRState1 == HIGH) {
      Millis2=millis();
      LDRPushCounter1++;
      difference1=Millis2-Millis1;
      Serial.print("takes ");
      Serial.print(difference1);
      Serial.print(" milliseconds to spin the wheel in full speed once \r\n");
      digitalWrite(MotorPin,LOW);
      break;
    } else {
;
    }
    delay(50);
  }
  lastLDRState1 = LDRState1;
}
  Millis3=millis();
  analogWrite(MotorPin,123);
  while(true){
  if (LDRState2 != lastLDRState2) {
    if (LDRState2 == HIGH) {
      Millis4=millis();
      LDRPushCounter2++;
      difference2=Millis4-Millis3;
      Serial.print("takes ");
      Serial.print(difference2);
      Serial.print(" milliseconds to spin the wheel in ha;f speed once \r\n");
      analogWrite(MotorPin,0);
      break;
    } else {
;
    }
    delay(50);
  }
  lastLDRState2 = LDRState2;
}
}
