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
//pin set up
}

void loop() {
 int buttonState = digitalRead(buttonPin);        //sub in value (HIGH or LOW) for "buttonState"
  if (buttonState != lastButtonState)             //compare the two button states, continue if it change
  {
     if(buttonState==HIGH)                       //check if the button is on high
      {
       buttonPushCounter++;                       //add a count to the amount of pushes, used for next step
       if (buttonPushCounter%4==1)                   //turn on all led if it is the first time button is pressed
       {
         digitalWrite(output1, HIGH);
         digitalWrite(output2, HIGH);
         digitalWrite(output3, HIGH);
         lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
         goto label;
       }
       else if (buttonPushCounter%4==2)              //turn on two led if it is the second time button is pressed
       {
         digitalWrite(output1, LOW);
         digitalWrite(output2,HIGH);
         digitalWrite(output3,HIGH);
         lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
         goto label;
       }
       else if (buttonPushCounter%4==3)              //turn on one led if it is the third time button is pressed 
       {
         digitalWrite(output1,LOW);
         digitalWrite(output2,LOW);
         digitalWrite(output3,HIGH);
         lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
         goto label;
       }
       else if (buttonPushCounter%4==0)              //turn all led off if it is the fourth time buttons is pressed
       {
          digitalWrite(output1,LOW);
          digitalWrite(output2,LOW);
          digitalWrite(output3,LOW);
          lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
          goto label;
                             //clear all count back to 0 (original)
       }
    }
    label: delay(500);                                    //delay to avoid fast track
  }
   lastButtonState=buttonState;                    //set the lastButtonState to buttonState for the next loop
} 

