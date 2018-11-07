void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(digitalRead(A0));
tone(3,180);
delay(100);
}
