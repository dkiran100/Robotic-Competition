//const int trig = A2;
//const int echo = A1; 
#define arm1 7
#define arm2 6
#define up_down1 5
#define up_down2 4
long duration;                              //variables to store data
int distance;

void setup() {
 
//pinMode(trig, OUTPUT);
//pinMode(echo, INPUT);
pinMode(arm1,OUTPUT);
pinMode(arm2,OUTPUT);
pinMode(up_down1,OUTPUT);
pinMode(up_down2,OUTPUT);

Serial.begin(9600);
}

void loop() {

        digitalWrite(arm1,HIGH);
        digitalWrite(arm2,LOW);
        delay(3000);

        digitalWrite(arm1,LOW);
        digitalWrite(arm2,HIGH);
        delay(5000);

        digitalWrite(up_down1,LOW);
        digitalWrite(up_down2,HIGH);
        delay(3000);

        digitalWrite(up_down1,HIGH);
        digitalWrite(up_down2,LOW);
        
        
        /*
        digitalWrite(trig, LOW);              //sets trigger pin low
        delayMicroseconds(2);                 // gives delay of 2us before setting trigger pin high

        digitalWrite(trig, HIGH);             // sets trigger pin high
        delayMicroseconds(10);                // keep trigger pin high for 10us
        digitalWrite(trig, LOW);

        duration = pulseIn(echo, HIGH);       // this function says to count the time from one 
                                              // high of echo pin to successive high of same once
                                              // it gets the pulse signal
                                              
        distance = duration*0.034/2;
        
  // speed of sound = 340 m/s
  // implies 0.034 cm/us
  // distance = (speed * time) / 2

  
  
  //Serial.print("Distance: ");
  //Serial.println(distance);       
  // print distance in serial monitor
  */

  
}
