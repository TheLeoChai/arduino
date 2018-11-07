int Switch = analogRead(5);
void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
 
  //initiate lever
  pinMode(5, INPUT);
}

void loop()
{
if (digitalRead(Switch >= 3))
//process when lever is on
  //Motor A forward @ full speed
  {
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
    digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 255);    //Spins the motor on Channel B at half speed
  }
else
//process when lever is off
{
  digitalWrite(9,HIGH); 
  // engage Brake for channel A
  digitalWrite(8,HIGH);
  // engage Brake for channel B
}
}
