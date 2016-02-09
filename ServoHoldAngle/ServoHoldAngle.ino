/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
// up elevon angle = servo angle * 2

int pos = 90;    // neutral servo position

int angle = -20;  // desired elevon angle

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  if(angle>0)
  {
    angle = angle/2;
  }
pos = pos - angle;

}
 
void loop() 
{ 
  myservo.write(pos);              // tell servo to go to position in variable 'pos' 
  delay(15);                       // waits 15ms for the servo to reach the position  
}

