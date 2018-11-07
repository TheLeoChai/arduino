const int  buttonPin = A0;        
const int Pin3=11;
const int Pin2=10;
const int Pin1=9;
// Variables will change:
int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;     
int Val=0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(Pin1,OUTPUT);
  pinMode(Pin2,OUTPUT);
  pinMode(Pin3,OUTPUT);
  Serial.begin(9600);
  lastButtonState=LOW;
}


void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  if (buttonState != lastButtonState) {
    Serial.println("Button State Change");
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("Button pushed");
    } 
    else if(buttonState ==LOW){
      Serial.println("Lifted");
    }
    delay(500);
  }
  else{
    Serial.println("Not Changed");
  }
  lastButtonState = buttonState;

  Val=buttonPushCounter%4;

  Write();
}

void Write(){
  if(Val==0){
    //none
    digitalWrite(Pin1,LOW);
    digitalWrite(Pin2,LOW);
    digitalWrite(Pin3,LOW);
    Serial.println("case0");
  }
  else if(Val==1){
    //all
    digitalWrite(Pin1,HIGH);
    digitalWrite(Pin2,HIGH);
    digitalWrite(Pin3,HIGH);
    Serial.println("case1");
  }
  else if(Val==2){
    // 2
    digitalWrite(Pin1,LOW);
    digitalWrite(Pin2,HIGH);
    digitalWrite(Pin3,HIGH);
    Serial.println("case2");
  }
  else if(Val==3){
    // 1
    digitalWrite(Pin1,LOW);
    digitalWrite(Pin2,LOW);
    digitalWrite(Pin3,HIGH);
    Serial.println("case3");
  }
}

