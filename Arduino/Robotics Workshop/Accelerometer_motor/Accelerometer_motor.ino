#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Wire.h>

int motor1 = 3;
int motor2 = 5;

int motor3 = 6;
int motor4 = 9;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
float x0,y0,z0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  
  sensors_event_t event;
  accel.getEvent(&event);

  x0 = event.acceleration.x;
  y0 = event.acceleration.y;
  z0 = event.acceleration.z;

  Serial.println(x0);
  Serial.println(y0);
  Serial.println(z0);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t event; // get direction from sensor
  accel.getEvent(&event);

  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  

  Serial.print("X: ");Serial.print(x);Serial.print(" ");
  Serial.print("Y: ");Serial.print(y);Serial.print(" ");
  Serial.print("Z: ");Serial.print(z);Serial.print(" ");Serial.println("m/s^2");
  delay(500);

  if(x > x0+3)
  {
    left();
  }
  else if(x < x0-3)
  {
    right();
  }
  else if(y > y0+3)
  {
    forward();
  }
  else if(y < y0+3)
  {
    reverse();
  }

  
}


void forward()
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
}

void reverse()
{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
}

void right()
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
}

void left()
{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
}

void stopping()
{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
}
