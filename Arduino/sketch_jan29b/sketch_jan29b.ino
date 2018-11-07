int Xval,Yval;
int xAxis= A0;
int yAxis= A1;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop() {
  FindVal();
  Serial.print(Xval);
  Serial.print(";");
  Serial.println(Yval);
  

}
void FindVal(){
  Xval=map(analogRead(xAxis),0,1023,-255,255);
  Yval=map(analogRead(yAxis),0,1023,-255,255);
}
