#include <Servo.h>

Servo Xservo;
Servo Yservo;

int Xpin = A0;
int Ypin = A1;
int Spin = 2;
int Xspin = 9;
int Yspin = 10;
int buzzPin = 7;
int WVx;
int WVy;
int Xval;
int Yval;
int Sval;
int dt = 200;

void setup() {
  Serial.begin(9600);
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(Spin, INPUT);
  pinMode(Xspin, OUTPUT);
  pinMode(Yspin, OUTPUT);
  pinMode(buzzPin, OUTPUT);

  Xservo.attach(Xspin);
  Yservo.attach(Yspin);

  digitalWrite(Spin, HIGH);
}

void loop() {
  Xval = analogRead(Xpin);
  WVx = (180. / 1023.) * Xval;
  Yval = analogRead(Ypin);
  WVy = (180. / 1023.) * Yval;
  Sval = digitalRead(Spin);
  Xservo.write(WVx);
  Yservo.write(WVy);
}
