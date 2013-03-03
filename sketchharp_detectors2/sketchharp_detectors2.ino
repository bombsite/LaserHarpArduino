// set-up 3 input pins for data, clock and latch
// regulate amount of current with 8-parallel op-amp.
int data = 2;
int clock = 4;
int latch = 7;
int photoin = 12;
int toneout = 13;


#define laserEnable 8

/*  TONES   */
#define NOTE_C2  65
#define NOTE_D2  73
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_G2  98
#define NOTE_A2  110
#define NOTE_B2  123
#define NOTE_C3  131


/*  TONES   */

int lightNumber;
int col;

void setup(){
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(laserEnable,OUTPUT);
  col=0;
  clearData();
  
  
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
    digitalWrite(photoout,HIGH);
    Serial.print('#');
    }
    
  else
  {
    digitalWrite(photoout,LOW);
    Serial.print("_");
  }
  
  
  digitalWrite(laserEnable,0);
  delayMicroseconds(800);
  digitalWrite(latch,1);
  digitalWrite(latch,0);
  if(col==0)
  {
    Serial.println();
    delayMicroseconds(2000);
  }
}

void clearData(){
  shiftOut(data,clock, LSBFIRST,0);
}
