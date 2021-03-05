#include <Servo.h>


Servo servoLeft;  //initializing left motor
Servo servoRight; //initializing right motor




void setup() {

  servoLeft.attach(13);   // setting left motor to pin number 13
  servoRight.attach(12);  // setting right motor to pin number 12
 
}

void maneuver(int speedLeft, int speedRight)  
{
  
  servoLeft.writeMicroseconds(1500 + speedLeft);   
  servoRight.writeMicroseconds(1500 - speedRight); 
                                 
}

void loop() {

// pin A0 -- is the output pin of Leftside CNY70 Sensor
// pin A1-- is the output pin of rightside CNY70 sensor

  if (leftsensor(A0) >3.0 && rightsensor(A1) >3.0)      // if both sensors are giving out values more than 3 means, they are on the white region, and they have to move forward
  {
     forward();
  }


  if (leftsensor(A0) <3.0 && rightsensor(A1) >3.0)  // if leftsensor is on black region and right on white region , then robot must turn left
  {
     left();
  }

   if (leftsensor(A0) >3.0 && rightsensor(A1) <3.0) // if rightsensor is on black region and left on white region , then robot must turn right
  {
     right();
  }

}

void left()
{
  maneuver(-100, 100); 
}

void right()
{
  maneuver(100, -100); 
}

void forward()
{
  maneuver(100, 100); 
}
float leftsensor(int A0)
{
float voltage1 = analogRead(A0)*(5.0/1023.0);   // reading sensor value and converting it to voltage for convenience
  return voltage1;
}
float rightsensor(int A1)
{
   float voltage2 = analogRead(A1)*(5.0/1023.0); // reading sensor value and converting it to voltage for convenience
  return voltage2;
}
  
