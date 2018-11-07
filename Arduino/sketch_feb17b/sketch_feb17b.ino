
void gf(){
  //forward
  Serial.println("gf");
}
void gb(){
  //backward
  Serial.println("gb");
}
void gl(){
  //left
  Serial.println("gl");
}
void gr(){
  ///righ
  Serial.println("gr");
}
typedef int (*movement)();
movement functions[]={gf,gb,gl,gr};
void setup(){
  Serial.begin(9600);
}
void loop(){
  for(int i=0; i<3; i++){
    functions[1]();
  }
}

