#include <Bounce2.h>

int button1 = 2;
int button2 = 3;
int led1 = 6;
int led2 = 7;
Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();

void setup(){
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  debouncer1.attach(button1);
  debouncer2.attach(button2);
  debouncer1.interval(5);
  debouncer2.interval(5);
  Serial.begin(115200);
}

void loop(){
  debouncer1.update();
  debouncer2.update();

  if(debouncer1.fell()){
 //   while(1){
    Serial.println("LEFT");
 //     if(debouncer1.rose()) break;
  //  }
    digitalWrite(led1, HIGH);

  }
  if(debouncer1.rose()){
    digitalWrite(led1, LOW);
  }
  if(debouncer2.fell()){
    Serial.println("RIGHT");
    digitalWrite(led2, HIGH);
  }
  if(debouncer2.rose()){
    digitalWrite(led2, LOW);
  }
}
