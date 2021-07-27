#include <Wire.h>                    //Adding Wire library 
#include <Adafruit_Sensor.h>         //Adding Adafruit Sensor library
#include <Adafruit_ADXL345_U.h>      //Adding ADXL adafruit library


int right1 = 5;                      //pins of motor driver 
int right2 = 6;
int left1 = 9;
int left2 = 10;
 
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345); //creating an object adhering to the adafruit ADXL library
float x0,y0,z0;                      //initial values of x,y and z
void setup(void) 
{
 Serial.begin(9600);

 accel.begin();                    //initializing sensor
 
 sensors_event_t event;            //Creating the event of sensing the acceleration in the three directions
 accel.getEvent(&event);           //calling the values of the event

 x0=event.acceleration.x;         //Assigning initial values
 y0=event.acceleration.y;
 z0=event.acceleration.z;

 Serial.println(x0);
 Serial.println(y0);
 Serial.println(z0);
 
 Serial.println("");
}
 
void loop(void) 
{
 /* Get a new sensor event */ 
 sensors_event_t event; 
 accel.getEvent(&event);

 float x=event.acceleration.x;                  //Getting x, y, and z accelerations
 float y=event.acceleration.y;
 float z=event.acceleration.z;
 /* Display the results (acceleration is measured in m/s^2) */
 Serial.print("X: "); Serial.print(x); Serial.print(" ");
 Serial.print("Y: "); Serial.print(y); Serial.print(" ");
 Serial.print("Z: "); Serial.print(z); Serial.print(" ");Serial.println("m/s^2 ");
 delay(500);

 //Setting the conditions for forward, reverse, left and right movements
 if (x>x0+3)
 {
 Serial.println("Left");
 dleft();
 }
 else if (x<x0-3)
 {
 Serial.println("Right");
 dright();
 }
 else if (y>y0+3)
 {
 Serial.println("Reverse");
 dreverse();
 }
 else if (y<y0-3)
 {
 Serial.println("Forward");
 dforward();
 }
 else if(x<x0+3 && x>x0-3 && y<y0+3 && y>y0-3)
 {
 Serial.println("Brake");
 dstat();
 }
}

//Creating the movement functions:
void dleft()
{
  digitalWrite(right1,0);
  digitalWrite(right2, 150);
  digitalWrite(left1, 150);
  digitalWrite(left2, 0);
}
void dright()
{
  digitalWrite(left1,0);
  digitalWrite(left2, 150);
  digitalWrite(right1, 150);
  digitalWrite(right2, 0);
}
void dreverse()
{
  digitalWrite(left1,150);
  digitalWrite(left2, 0);
  digitalWrite(right1, 150);
  digitalWrite(right2, 0);
}
void dforward()
{
  digitalWrite(left1,0);
  digitalWrite(left2, 150);
  digitalWrite(right1, 0);
  digitalWrite(right2, 150);
}
void dstat()
{
  digitalWrite(left1,0);
  digitalWrite(left2,0);
  digitalWrite(right1,0);
  digitalWrite(right2,0);
}
