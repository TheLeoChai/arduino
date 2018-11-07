void setup()
{
   //no setup needed
}

void loop()
{ 
  Serial.begin(9600);
  int n = 0;
  //initialize number used to calculate delay to 0
  for(int x=0; x<=255; x++)
  //count from 0 to 255
    {
    Serial.print(x,BIN);
  //print number in binary on serial
    Serial.print('_');
  //put a space inbetween the numbers
    delay((abs(n))*sq(n));
     //delay the speed by sin(|times repeated|)*100
     n++;
  //add a count to the number used to calculate delay
    }
}

