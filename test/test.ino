const int inputPin = 2;
const int data = 5;
const int clock = 6;
const int latch = 7;


int myCount;
int inputState = LOW;

int oldTime;
int newTime;

void setup(){
  Serial.begin(9600);
myCount = 0;

pinMode(inputPin, INPUT);
pinMode(data,OUTPUT);
pinMode(clock,OUTPUT);
pinMode(latch,OUTPUT);

digitalWrite(data,LOW);
for(int i=0; i<8; i++){
  digitalWrite(clock,HIGH);
  delay(5);
  digitalWrite(clock,LOW);
}
digitalWrite(latch,HIGH);
delay(5);
digitalWrite(latch,LOW);

oldTime=millis();
}

void loop(){
  newTime = millis();
  if(digitalRead(inputPin) == HIGH ){
    
    if(inputState == LOW && (newTime - oldTime >150)){
    inputState = HIGH;    
    myCount++;
    int mask = 1;
    for(int j=0;j<16;j++){
    
      if(mask & myCount){
          digitalWrite(data, HIGH);
       }
       else
         digitalWrite(data,LOW);
         
      
      digitalWrite(clock,HIGH);
      
      digitalWrite(clock,LOW);

      mask = mask << 1;
      
    }    
    oldTime = newTime;
    }
    
    digitalWrite(latch,HIGH);
    digitalWrite(latch,LOW);
    
   
  }else
    inputState = LOW;
    
  
}

