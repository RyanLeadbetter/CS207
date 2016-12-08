
#include <Servo.h> 
Servo Rightfoot;
Servo Rightleg;
Servo Leftfoot;
Servo Leftleg;

int tAngle = 30; //tilt angle
int sAngle = 30; //swing angle

int wSpeed = 30; //walkingSpeed

int rightf = 82;
int leftf = 82;
int rightl = 90;
int leftl = 90;

void setup() 
{ 
Rightfoot.attach(11);
Rightleg.attach(10);
Leftfoot.attach(3);
Leftleg.attach(5);
Centre;
} 
 
 
void loop() 
{ 
  delay(5000);
  TiltRightUp(tAngle, wSpeed);
  for(int i = 0; i < 10; i++)
  {
    Forward();
  }
  TiltRightDown(tAngle, wSpeed);
  delay(5000); 
} 

void Forward()
{
  delay(20);
  SwingRight(sAngle, wSpeed);
  TiltRightDown(tAngle, wSpeed);
  TiltLeftUp(tAngle, wSpeed);
  delay(20);
  SwingRcenter(sAngle, wSpeed);
  SwingLeft(sAngle, wSpeed);
  TiltLeftDown(tAngle, wSpeed);
  TiltRightUp(tAngle, wSpeed);
  delay(20);
  SwingLcenter(sAngle, wSpeed);
  
}

void Centre(){
  Rightfoot.write(rightf);
  Leftfoot.write(leftf);
  Rightleg.write(rightl);
  Leftleg.write(leftl);
}

void TiltLeftUp(int angle, int sp){
  //tilt left up
  for (int i=0; i<angle; i+=5){
    Leftfoot.write(leftf-i);
    Rightfoot.write(rightf-i);
    delay(sp);
  }
}

void SwingLeft(int angle, int sp){
  //swing left
  for (int i=0; i<=angle; i=i+5){
    Leftleg.write(leftl+i);
    Rightleg.write(rightl+i);
    delay(sp);
  }
}

void TiltLeftDown(int angle, int sp){
  //tilt left down
  for (int i=angle; i>0; i-=5){
    Leftfoot.write(leftf-i);
    Rightfoot.write(rightf-i);
    delay(sp);
  }
}

void TiltRightUp(int angle, int sp){  
  //tilt right up
  for (int i=0; i<=angle; i+=5){
    Leftfoot.write(leftf+i);
    Rightfoot.write(rightf+i);
    delay(sp);
  }
}

void SwingLcenter(int angle, int sp){
  //swing l->center
  for (byte i=angle; i>0; i=i-5){
    Leftleg.write(leftl+i);
    Rightleg.write(rightl+i);
    delay(sp);
  }
}

void SwingRight(int angle, int sp){
  //swing right
  for (int i=0; i<=angle; i+=5){
    Leftleg.write(leftl-i);
    Rightleg.write(rightl-i);
    delay(sp);
  }
}

void TiltRightDown(int angle, int sp){
  //tilt right down
  for (int i=angle; i>0; i-=5){
    Leftfoot.write(leftf+i);
    Rightfoot.write(rightf+i);
    delay(sp);
  }
}

void SwingRcenter(int angle, int sp){
  //swing r->center
  for (int i=angle; i>0; i-=5){
    Leftleg.write(leftl-i);
    Rightleg.write(rightl-i);
    delay(sp);
  }
}
