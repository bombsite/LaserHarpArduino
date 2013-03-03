// set-up 3 input pins for data, clock and latch
// regulate amount of current with 8-parallel op-amp.
int data = 2;
int clock = 4;
int latch = 7;
#define laserEnable 8

int lightNumber;
int col;

void setup(){
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(laserEnable,OUTPUT);
  col=0;
  clearData();
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
  
  delayMicroseconds(600);
  digitalWrite(laserEnable, 1);
  delayMicroseconds(500);
  digitalWrite(laserEnable,0);

  digitalWrite(latch,1);
  digitalWrite(latch,0);
  if(col==0)
    delayMicroseconds(300);
}

void clearData(){
  shiftOut(data,clock, LSBFIRST,0);
}
