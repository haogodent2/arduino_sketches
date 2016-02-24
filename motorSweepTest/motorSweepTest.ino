/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myMotor;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 90;    // variable to store the servo position 
int maxRev = 110;
int minRev = 70;
void setup() 
{ 
  myMotor.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  while(millis()<5000){
    myMotor.write(pos);
    delay(100);
  }

for (pos = minRev; pos<maxRev; pos+=2)
  {  
    myMotor.write(pos);
    delay(50);
  }
delay(1000);

for (pos = maxRev; pos>minRev; pos-=2)
  {  
    myMotor.write(pos);
    delay(50);
  }
delay(1000);
} 

