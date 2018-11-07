const int LDRpin1=5;
const int LDRpin2=6 ;

int ButtonState;
int LastButtonState;

void setup(){
  pinMode(LDRpin1,INPUT);
  pinMode(LDRpin2,INPUT);
  Serial.begin(9600);
  }

//function can be called: LDRcountV(current count), need to be in a loop to be able to perform
int LDRcountV (int y){
    ButtonState=digitalRead(LDRpin1);
    if (ButtonState != LastButtonState){
      if(ButtonState = HIGH){
        y++;
      }
      else 
      ;
    }
    Serial.print("vertical count now becomes ");
    Serial.println(y);
    Serial.print("now have spinned vertically ");
    Serial.println(y/6);
    return y;
}

//function can be called: lDRcountH(current count), need to be in a loop to be able to perform
int LDRcountH (int x){
    ButtonState=digitalRead(LDRpin2);
    if (ButtonState != LastButtonState){
      if(ButtonState = HIGH){
        x++;
      }
      else 
      ;
    }
    Serial.print("horizontal count now becomes ");
    Serial.println(x);
    Serial.print("now have spinned horizontally ");
    Serial.println(x/6);
    return x;
}
