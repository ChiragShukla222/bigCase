#include <pins_arduino.h>
int pirSensors[]={2, 3, 18, 19, 20, 21};
const byte beeper = 13;
const byte greenledPins[]={22,26,30,34,38,42};
const byte yellowledPins[]={24,28,32,36,40,44};
int currentBox=0,nextBox=0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(beeper,OUTPUT);
  // make the pushbutton's pin an input:
  for(int i=0;i<6;i++){
    pinMode(greenledPins[i],OUTPUT);
    pinMode(yellowledPins[i],OUTPUT);
    pinMode(pirSensors[i],INPUT);
  }
  while(digitalRead(pirSensors[0]) || digitalRead(pirSensors[1]) || digitalRead(pirSensors[2]) || digitalRead(pirSensors[3]) || digitalRead(pirSensors[4]) || digitalRead(pirSensors[5]));
  attachInterrupt(digitalPinToInterrupt(pirSensors[0]),PIR0,RISING);//CHANGE
  attachInterrupt(digitalPinToInterrupt(pirSensors[1]),PIR1,RISING);//CHANGE
  attachInterrupt(digitalPinToInterrupt(pirSensors[2]),PIR2,RISING);//CHANGE
  attachInterrupt(digitalPinToInterrupt(pirSensors[3]),PIR3,RISING);//CHANGE
  attachInterrupt(digitalPinToInterrupt(pirSensors[4]),PIR4,RISING);//CHANGE
  attachInterrupt(digitalPinToInterrupt(pirSensors[5]),PIR5,RISING);//CHANGE
  digitalWrite(greenledPins[currentBox],HIGH);
  digitalWrite(yellowledPins[nextBox],HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  while(Serial.available() == 0);
  currentBox=Serial.parseInt();
  if(currentBox>5 || currentBox<0)currentBox=0;
  while(Serial.available() == 0);
  nextBox=Serial.parseInt();
  if(nextBox>5 || nextBox<0)nextBox=0;
  for(int i=0;i<6;i++){
    digitalWrite(greenledPins[i], LOW);
    digitalWrite(yellowledPins[i], LOW);
  }
  digitalWrite(greenledPins[currentBox],HIGH);
  digitalWrite(yellowledPins[nextBox],HIGH);
  digitalWrite(beeper, LOW);
  delay(1);
}


void PIR0() {
  if(currentBox==0){digitalWrite(beeper,LOW);Serial.println("interuppt0");}
  else {digitalWrite(beeper,HIGH);Serial.println("WrongInteruppt");}
}

void PIR1() {
  if(currentBox==1){digitalWrite(beeper,LOW);Serial.println("interuppt1");}
  else {digitalWrite(beeper,HIGH);Serial.println("WrongInteruppt");}
}

void PIR2() {
 if(currentBox==2){digitalWrite(beeper,LOW);Serial.println("interuppt2");}
 else {digitalWrite(beeper,HIGH);Serial.println("WrongInteruppt");}
}

void PIR3() {
  if(currentBox==3){digitalWrite(beeper,LOW);Serial.println("interuppt3");}
  else {digitalWrite(beeper,HIGH);Serial.println("WrongInteruppt");}
}

void PIR4() {
  if(currentBox==4){digitalWrite(beeper,LOW);Serial.println("interuppt4");}
  else {digitalWrite(beeper,HIGH);Serial.println("WrongInteruppt");}
}

void PIR5() {
 if(currentBox==5){digitalWrite(beeper,LOW);Serial.println("interuppt5");}
 else {digitalWrite(beeper,HIGH);Serial.println("WrongInteruppt");}
}


