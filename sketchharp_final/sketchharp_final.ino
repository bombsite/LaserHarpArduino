/* Arduino Sketch for the laser harp.
** Author: Site Mao
** 
*/ 
// set-up 3 input pins for data, clock and latch
// regulate amount of current with 8-parallel op-amp.
int data = 2;
int clock = 4;
int latch = 7;
int photoin = 12;
int toneout = 9;


#define laserEnable 8

/*  TONES   */
#define NOTE_C2  1976
#define NOTE_D2  988
#define NOTE_E2  1047
#define NOTE_F2  1175
#define NOTE_G2  1319
#define NOTE_A3  1397
#define NOTE_B3  1568
#define NOTE_C3  1760
/*  TONES   */

int lightNumber;
int col,toneNumber,finalTone;

void setup(){
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(laserEnable,OUTPUT);
  col=0;
  clearData();
  finalTone = -1;
  
  
  pinMode(photoin, INPUT);
  pinMode(toneout, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  

  
 
   col++;
  
  if(col > 7){
    col=0;
    digitalWrite(data,1); 
  }else{
  digitalWrite(data,0);
  }
  digitalWrite(clock,1);
  digitalWrite(clock,0);
  
  delayMicroseconds(2000);
  digitalWrite(laserEnable, 1);
  delayMicroseconds(500);
  
    if ( digitalRead(photoin) == HIGH)
    {
    //digitalWrite(photoout,HIGH);
    Serial.print('#');
    //noTone(toneout);
    }
    
  else
  {
    //digitalWrite(photoout,LOW);
    Serial.print("_");
    finalTone = col;
    
  }
  
  
  digitalWrite(laserEnable,0);
  delayMicroseconds(800);
  digitalWrite(latch,1);
  digitalWrite(latch,0);
  if(col==0)
  {

    
    
    
    switch(finalTone){
    case 0:
      toneNumber = NOTE_C2;
      break;
    case 1:
      toneNumber = NOTE_D2;
      break;
    case 2: 
      toneNumber = NOTE_E2;
      break;
    case 3:
      toneNumber = NOTE_F2;
      break;
    case 4:
      toneNumber = NOTE_G2;
      break;
    case 5:
      toneNumber = NOTE_A3;
      break;
    case 6:
      toneNumber = NOTE_B3;
      break;
    case 7:
      toneNumber = NOTE_C3;
      break;
    default:
      break;
    }
    
    if (finalTone == -1)
      noTone(toneout);
    else
    {
      tone(toneout, toneNumber);
      Serial.print(toneNumber);
    }
        Serial.println();
    
    delayMicroseconds(2000);
    finalTone = -1;
    
  }
  
  
  
}

void clearData(){
  shiftOut(data,clock, LSBFIRST,0);
}
