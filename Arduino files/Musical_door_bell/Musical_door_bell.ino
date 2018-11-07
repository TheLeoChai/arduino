//Leo Chai
//2018/1/29
//musical door bell
#include "pitches.h"
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);//speaker pin
  pinMode(7,INPUT);//button pin, connected to power
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(7)==HIGH){
  playMelody();
}
}

void playMelody(){
  int melody[] = {//melody array for door bell music
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4,0,
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4
  };
  int noteDurations[] = {//duration for melody
  4,4,4,4,4,4,4,4,4,4,4,4,4,16,16,8,
  4,4,4,4,4,4,4,4,4,4,4,4,4,8,8
  };
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {// to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    float noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);// to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);// stop the tone playing:
    noTone(8);
  } 
}

