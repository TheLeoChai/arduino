int led1 = 1;                                                                                   //initialize led1 for the 1 th led pin
int led2 = 2;                                                                                   //initialize led2 for the 2 th led pin
int led3 = 3;                                                                                   //initialize led3 for the 3 th led pin
int led4 = 4;                                                                                   //initialize led4 for the 4 th led pin
int led5 = 5;                                                                                   //initialize led5 for the 5 th led pin
int led6 = 6;                                                                                   //initialize led6 for the 6 th led pin
int led7 = 7;                                                                                   //initialize led7 for the 7 th led pin
int led8 = 8;                                                                                   //initialize led8 for the 8 th led pin
void setup() {
 pinMode(1,OUTPUT);                                                                             //set pin 1 as output for led1
 pinMode(2,OUTPUT);                                                                             //set pin 2 as output for led2
 pinMode(3,OUTPUT);                                                                             //set pin 3 as output for led3
 pinMode(4,OUTPUT);                                                                             //set pin 4 as output for led4
 pinMode(5,OUTPUT);                                                                             //set pin 5 as output for led5
 pinMode(6,OUTPUT);                                                                             //set pin 6 as output for led6
 pinMode(7,OUTPUT);                                                                             //set pin 7 as output for led7
 pinMode(8,OUTPUT);                                                                             //set pin 8 as output for led8
}

void loop() {
digitalWrite(led1,HIGH);
delay (100);
digitalWrite(led1,LOW);                                                                         //blink 1st led for 0.1 sec
digitalWrite(led2,HIGH);
delay (100);
digitalWrite(led2,LOW);                                                                         //blink 2nd led for 0.1 sec
digitalWrite(led3,HIGH);
delay (100);
digitalWrite(led3,LOW);                                                                         //blink 3rd led for 0.1 sec
digitalWrite(led4,HIGH);
delay (100);
digitalWrite(led4,LOW);                                                                         //blink 4th led for 0.1 sec
digitalWrite(led5,HIGH);
delay (100);
digitalWrite(led5,LOW);                                                                         //blink 5th led for 0.1 sec
digitalWrite(led6,HIGH);
delay (100);
digitalWrite(led6,LOW);                                                                         //blink 6th led for 0.1 sec
digitalWrite(led7,HIGH);
delay (100);
digitalWrite(led7,LOW);                                                                         //blink 7th led for 0.1 sec
digitalWrite(led8,HIGH);
delay (100);
digitalWrite(led8,LOW);                                                                         //blink 8th led for 0.1 sec
digitalWrite(led7,HIGH);
delay (100);
digitalWrite(led7,LOW);                                                                         //blink 7th led for 0.1 sec
digitalWrite(led6,HIGH);
delay (100);
digitalWrite(led6,LOW);                                                                         //blink 6th led for 0.1 sec
digitalWrite(led5,HIGH);
delay (100);
digitalWrite(led5,LOW);                                                                         //blink 5th led for 0.1 sec
digitalWrite(led4,HIGH);
delay (100);
digitalWrite(led4,LOW);                                                                         //blink 4th led for 0.1 sec
digitalWrite(led3,HIGH);
delay (100);
digitalWrite(led3,LOW);                                                                         //blink 3rd led for 0.1 sec
digitalWrite(led2,HIGH);
delay (100);
digitalWrite(led2,LOW);                                                                         //blink 2nd led for 0.1 sec
}
