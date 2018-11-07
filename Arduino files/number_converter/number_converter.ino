  void setup() {
int n=1;                                                                                        //set up the number
Serial.print("BIN: ");
Serial.print(n,BIN);                                                                            //print number in binary and label it
Serial.print(" ");                                                                              //add space inbetween
Serial.print("HEX: ");
Serial.print(n,HEX);                                                                            //print number in hexadecimal and label it
Serial.print(" ");                                                                              //add space inbetween
Serial.print("DEC: ");
Serial.print(n);                                                                                //prind number in decimal and label it
}

void loop() {
//no loop needed


}
