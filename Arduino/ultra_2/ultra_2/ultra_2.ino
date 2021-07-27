int trigPin1 = 13;
int echoPin1 = 12;

int trigPin2 = 8;
int echoPin2 = 7;

long duration, distance, UltraSensor1, UltraSensor2;
int c1 = 0 , c2 = 0 , currentstate1 = 0 , prevstate1 = 0 , currentstate2 = 0 , prevstate2 = 0; 

void setup()
{// START SETUP FUNCTION
Serial.begin (9600);                              // we will use the serial data transmission to display the distance value on the serial monitor 

// setup pins first sensor
pinMode(trigPin1, OUTPUT);                        // from where we will transmit the ultrasonic wave
pinMode(echoPin1, INPUT);                         //from where we will read the reflected wave                  // from where we will control the LED

//setup pins second sensor
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

}

void loop(){

  SonarSensor(trigPin1,echoPin1);
  UltraSensor1 = distance;
  SonarSensor(trigPin2,echoPin2);
  UltraSensor2 = distance;

  if(UltraSensor1 <= 10){
    currentstate1 = 1;
  }
  else{
    currentstate1 = 0;
  }

  delay(100);
  if(currentstate1 != prevstate1){
      if(currentstate1 == 1){
        c1 = c1 + 1;
        Serial.print("Ultra 1 : ");
        Serial.println(c1);
      }
  }

  if(UltraSensor2 <= 10){
    currentstate2 = 1;
  }
  else{
    currentstate2 = 0;
  }

  delay(1000);
  if(currentstate2 != prevstate2){
      if(currentstate2 == 1){
        c2 = c2 + 1;
        Serial.print("Ultra 2 : ");
        Serial.println(c2);
      }
  }
  
}


void SonarSensor(int trigPinSensor,int echoPinSensor)//it takes the trigPIN and the echoPIN 
{
  //START SonarSensor FUNCTION
  //generate the ultrasonic wave
//---------------------------------------------------------------------------------------------------------------------- 
digitalWrite(trigPinSensor, LOW);// put trigpin LOW 
delayMicroseconds(2);// wait 2 microseconds
digitalWrite(trigPinSensor, HIGH);// switch trigpin HIGH
delayMicroseconds(10); // wait 10 microseconds
digitalWrite(trigPinSensor, LOW);// turn it LOW again
//----------------------------------------------------------------------------------------------------------------------

//read the distance
//----------------------------------------------------------------------------------------------------------------------
duration = pulseIn(echoPinSensor, HIGH);//pulseIn funtion will return the time on how much the configured pin remain the level HIGH or LOW; in this case it will return how much time echoPinSensor stay HIGH
distance= (duration/2) / 29.1; // first we have to divide the duration by two  
}
