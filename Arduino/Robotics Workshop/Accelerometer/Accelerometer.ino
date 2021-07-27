#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Wire.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
float x0,y0,z0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  
}
