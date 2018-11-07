void setup()
{
   //no setup needed
}

void loop()
{ 
  Serial.begin(9600);
  int n = 0;                                                                                            //initialize number used to calculate delay to 0
  for(int x=0; x<=255; x++)                                                                             //count from 0 to 255
    {
    Serial.print("Bin:");
    Serial.print(x,BIN);                                                                                //print number in binary on serial
    Serial.print(';');
    Serial.print("Hex:");
    Serial.print(n,HEX);                                                                                //print number in Hexadecimal on serial
    Serial.print('_');                                                                                  //put a space inbetween the numbers
    delay((abs(n))*sq(n));                                                                              //delay the speed by sin(|times repeated|)*100
     n++;                                                                                               //add a count to the number used to calculate delay and hexadecimal number
    }
}

