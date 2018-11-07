const int buttonPin = 2;                              
const int output1 = 9;
const int output2 = 10;
const int output3 = 11;
//initialize pins
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

//initialize numbers
void setup() {
pinMode(buttonPin,INPUT);
pinMode(output1,OUTPUT);
pinMode(output2,OUTPUT);
pinMode(output3,OUTPUT);
pinMode(13,OUTPUT);
//pin set up
}

void loop() {
 int buttonState = digitalRead(buttonPin);        //sub in value (HIGH or LOW) for "buttonState"
   if (buttonState != lastButtonState)             //compare the two button states, continue if it change
  {
 if(buttonState==HIGH)                       //check if the button is on high
      {
       buttonPushCounter++;                       //add a count to the amount of pushes, used for next step
   if(buttonPushCounter%4==1)
   {
    digitalWrite(output1,HIGH);
    digitalWrite(output2,HIGH);
    digitalWrite(output3,HIGH);
    lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
   }
   else if(buttonPushCounter%4==2)
   {
    digitalWrite(output1,LOW);
    digitalWrite(output2,HIGH);
    digitalWrite(output3,HIGH);
    lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
   }
   else if(buttonPushCounter%4==3)
    {
      digitalWrite(output1,LOW);
      digitalWrite(output2,LOW);
      digitalWrite(output3,HIGH);
      lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
    }
   else if(buttonPushCounter%4==0)
    {
      digitalWrite(output1,LOW);
      digitalWrite(output2,LOW);
      digitalWrite(output3,LOW);
      lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
    }
  delay(500);
  lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
  }
  else if(buttonState==LOW)
  lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
  }
  else
  lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
}
