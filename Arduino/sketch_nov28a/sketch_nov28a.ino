int  ledpin=13;
//initilize ledpin to equal pin 13(pin with led)
void setup() {
  // put your setup code here, to run once:
 pinMode(ledpin,OUTPUT);
 //setup the led pin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledpin,HIGH);
  delay(50);
  //tunr on the led for 50ms
  digitalWrite(ledpin,LOW);
  delay(75);
  //turn off led for 75ms to simulate hear beat
  digitalWrite(ledpin,HIGH);
  delay(50);
  //turn on the led for 50 ms again
  digitalWrite(ledpin,LOW);
  delay(750);
  //turn off led for 750ms to simulate pause before next pulse
}
