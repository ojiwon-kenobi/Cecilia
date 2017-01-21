#include <AnalogSmooth.h>
#include "pitches.h"

AnalogSmooth as= AnalogSmooth(100);
const int buzzer = 9;
long randNumber;
int min= 140; //be ready to change these
int max= 270; //cause they change day by day tbh
int randArray[17];

int mjrArpg[] = {NOTE_G2, NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_E5, NOTE_G5, 
NOTE_C6, NOTE_E6, NOTE_G6, NOTE_C7, NOTE_E7, NOTE_G7, NOTE_C8}; //major arpeggios

int mnrArpg[] = {NOTE_G2, NOTE_C3, NOTE_DS3, NOTE_G3, NOTE_C4, NOTE_DS4, NOTE_G4, NOTE_C5, NOTE_DS5, NOTE_G5, 
NOTE_C6, NOTE_DS6, NOTE_G6, NOTE_C7, NOTE_DS7, NOTE_G7, NOTE_C8}; //minor arpeggios

int blues[] = {NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_AS5, 
NOTE_C6, NOTE_DS6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_AS6, NOTE_C7}; //jazz

int whole[] = {NOTE_C3, NOTE_D3, NOTE_E3, NOTE_FS3, NOTE_GS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_FS4, 
NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_GS5}; //outer space

int chromatic[] = {NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, 
NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5}; //creepy ass

int pentatonic[]= {NOTE_C3, NOTE_D3, NOTE_E3, NOTE_G3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_C5,
 NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_D6}; //asian as hell
 
//int hyperlydian[]
//int diatonic[]
//int octatonic[]


void setup() {  
 Serial.begin(115200);}

void loop() {

  randNumber= random(0, 6);  
  float anlg0= as.analogReadSmooth(0);
  Serial.println(anlg0);
  
  if (anlg0 > max) {     
      if (randNumber== 0) {
          setEqual(randArray, mjrArpg);
          Serial.println("case 0");
      } else if (randNumber == 1) {
          setEqual(randArray, mnrArpg);
          Serial.println("case 1");
      } else if (randNumber == 2) {
          setEqual(randArray, blues);
          Serial.println("case 2");
      } else if (randNumber == 3) {
          setEqual(randArray, whole);
          Serial.println("case 3");
      } else if (randNumber == 4) {
          setEqual(randArray, chromatic);
          Serial.println("case 4");
      } else if (randNumber == 5) {
          setEqual(randArray, pentatonic);
          Serial.println("case 5");
      }
    Serial.print(randNumber);  
    Serial.print("done random: ");
    Serial.println(anlg0);
    anlg0= as.analogReadSmooth(0);
  }
  
  int indNoteRange= (max-min)/17;
  int numArray[17];

  for (int i=0; i< 17; i++) {           //print the numArray of max, min
    numArray[i]= min+ indNoteRange * i;
    //Serial.println(numArray[i]);
  }


  int j= 0;
  
   while (anlg0 > numArray[j]){       //transverse numArray min-max until 
          j++;
   }
    Serial.print("answer: "); Serial.println(j);

     
     tone(buzzer, randArray[j]);
     Serial.println(anlg0);
 
}








void setEqual(int x[17], int y[17]) {
  for (int i= 0; i< 17; i++) {
    x[i]= y[i];
  } 
}
















    


