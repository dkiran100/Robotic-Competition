// const int vcc = A3; 
const int trig = A2;
const int echo = A1; 
// const int gnd = A0;

long duration;                              //variables to store data
int distance;

void setup() {
 
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
//pinMode(vcc, OUTPUT);
//pinMode(gnd, OUTPUT);

//digitalWrite(vcc, HIGH);              // 5 Volts to Vcc of Sensor
//digitalWrite(gnd,LOW);                // grounding of gnd pin of sensor

Serial.begin(9600);
}

void loop() {
        
  
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

  Serial.print("Distance: ");
  Serial.println(distance);                   // print distance in serial monitor
  
}
