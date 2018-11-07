
//program for motor arduino

int Upin=5;
int Dpin=4;
int Lpin=1;
int Rpin=1;

void setup(){
  pinMode(Upin,INPUT);
  pinMode(Dpin,INPUT);
  pinMode(Lpin,INPUT);
  pinMode(Rpin,INPUT);
}
 void loop(){
  while(digitalRead(Upin)==HIGH){
    //function to go forward
  }
  while(digitalRead(Dpin)==HIGH){
    //function to go back
  }
  while(digitalRead(Lpin)==HIGH){
    //function to go left
  }
  while(digitalRead(Rpin)==HIGH){
    //function to go right
  }
 }

