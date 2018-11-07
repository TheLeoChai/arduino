void setup() {
pinMode(9,OUTPUT);                                                     //initialize pin for controling the motor
pinMode(13,OUTPUT);                                                    //initialize builtin LED on arduino
}

void loop() {
digitalWrite(9,HIGH);                                                  //turn on the motor
digitalWrite(13,HIGH);                                                 //turn on the LED
delay(1000);                                                           //delay one second
digitalWrite(9,LOW);                                                   //turn off the motor
digitalWrite(13,LOW);                                                  //turn off the led
delay(1000);                                                           //delay one second
                                                                       //flashing led is to make sure that the program is successfully uploading to arduino and that arduino is not burnt out；light up when motor is running
                                                                    

}
