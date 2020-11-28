#include <Servo.h>
Servo s;

int buzz = 2;
int button = 7;
int inter = A0;
int xit = A1;
int state = LOW; 
int previous = LOW;
int countt = 0;
int inr,outr,value,mpin,mpout;

void setup() {
 s.attach(6);
 pinMode(buzz,OUTPUT);
 pinMode(inter, INPUT);
 pinMode(xit,INPUT);
 pinMode(button, INPUT);
 Serial.begin(9600);
}

void loop() {
  

  value = digitalRead(button);
  if (value == HIGH && previous == LOW) {
    if (state == HIGH){
      state = LOW;
    }
    else{
      state = HIGH;
    }}

if (state == HIGH){
  Serial.println("   ");
  Serial.println(countt);
  Serial.println("   ");
  inr = analogRead(inter); 
  outr = analogRead(xit);
  mpin = map(inr ,0 ,1023 ,0 , 100);
  mpout = map(outr ,0 ,1023 ,0 , 100);
  if(mpin < 5 && countt < 5){
   for(int i=0; i<=180; i++){
    s.write(i);
    delay(10);
   }
   for(int i=179; i>=0; i--){
    s.write(i);
    delay(10); 
   }
    countt = countt + 1;
  }
if(mpin < 5 && countt == 5){
  tone(buzz, 1000);
  delay(1000);
  noTone(buzz);
  }
 if(mpout < 5 && countt > 0){
   for(int i=0; i<=180; i++){
    s.write(i);
    delay(10);
   }
   for(int i=179; i>=0; i--){
    s.write(i);
    delay(10); 
   }
    countt = countt - 1;
 }
}

  previous = value;
}
