// 미니카 

//DC모터
#include <SoftwareSerial.h>
#define tx2;
#define rx3;
SoftwareSerial BT(2,3);
int MA1 = 10;    //speed
int MA2 = 11; //wheel
int MB1 = 5;
int MB2 = 6;
int led=4;
const int trig_pin=8;
const int echo_pin=9;
void n();


int val = 127;


void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(echo_pin,INPUT);
  
  digitalWrite (MA2 , LOW);
  analogWrite (MA1,0);
  digitalWrite (MB2 , LOW);
  analogWrite (MB1,0);
 
    
}

void loop() {
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);

  if(BT.available())
  {
    Serial.write(BT.read());
  }
  if(Serial.available())
  {
    BT.write(Serial.read());
  }

    char c = BT.read();
    if(c== 'U')
    {
      digitalWrite(MA2, LOW);
      analogWrite(MA1, val);
      digitalWrite(MB2, LOW);
      analogWrite(MB1, val);
      n();
      
    }
   else if (c == 'D')
   {
     digitalWrite(MA2, HIGH);
      analogWrite(MA1, val);
      digitalWrite(MB2, HIGH);
      analogWrite(MB1, val);
      n();
   }
   else if (c == 'L')
   {
     digitalWrite(MA2, HIGH);
      analogWrite(MA1, 64);
      digitalWrite(MB2, HIGH);
      analogWrite(MB1, val);
      n();
   }
   else if (c == 'R')
   {
     digitalWrite(MA2, HIGH);
      analogWrite(MA1, val);
      digitalWrite(MB2, HIGH);
      analogWrite(MB1, 64);
      n();
   }
   else if (c == 'T')
   {
     digitalWrite(MA2, HIGH);
      analogWrite(MA1, val);
      digitalWrite(MB2, LOW);
      analogWrite(MB1, val);
      n();
   }
   else if (c == 'B')
   {
     digitalWrite(MA2, HIGH);
      analogWrite(MA1, val);
      digitalWrite(MB2, HIGH);
      analogWrite(MB1, val);
      n();
   }
   else if (c=='S')
   {
    digitalWrite(MA2, LOW);
    analogWrite(MA1, 0);
    digitalWrite(MB2, LOW);
    analogWrite(MB1, 0);
   }
  }

  void n()
  {
    long duration=pulseIn(echo_pin ,HIGH);
  long distance=(duration/2)/29.1;
    if(distance<=10){
  Serial.println("warning");
  for(int i=0 ;i<=1;i++){
    if (i==0) {
    digitalWrite(led,i);
    delay(500);
    }
    else if(i==1){
    digitalWrite(led,i);
    delay(500);
    }
    analogWrite(MA2,0);
    digitalWrite(MA1,LOW);
    analogWrite(MB2,0);
    digitalWrite(MB1,LOW);
    
  }
  
  }
  else if (distance>10){
    digitalWrite(led,0);
    analogWrite(MA2,val);
    digitalWrite(MA1,HIGH);
    analogWrite(MB2,val);
    digitalWrite(MB1,HIGH);
  }
  }
