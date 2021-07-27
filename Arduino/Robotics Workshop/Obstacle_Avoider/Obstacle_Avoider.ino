int motorL1=3;  
int motorL2=2;  
int motorR1=5;  
int motorR2=4;              // MOTOR DRIVER PINS TO DECIDE THE DIRECTION OF MOTORS

const int vcc = A3; 
const int trig = A2;
const int echo = A1; 
const int gnd = A0; 

int duration;
int distance;             // VARIALBES TO STORE DATA

void setup() 
{  
    Serial.begin(9600);
   
    pinMode(motorL1,OUTPUT);
    pinMode(motorL2,OUTPUT);
    pinMode(motorR1,OUTPUT);
    pinMode(motorR2,OUTPUT);

    

    pinMode(echo,INPUT);
    pinMode(trig, OUTPUT);
    
    pinMode (vcc,OUTPUT);
    pinMode (gnd,OUTPUT);

    digitalWrite(vcc,HIGH);     // 5 Volts to Vcc of Sensor     
    digitalWrite(gnd,LOW);      // grounding of gnd pin of sensor
        
    pinMode(echo,INPUT);
    pinMode(trig, OUTPUT);

    
     
}            
void loop() 
{                
       
        digitalWrite(trig, LOW);    //sets trigger pin low
        delayMicroseconds(2);       // gives delay of 2us before setting trigger pin high
        
        digitalWrite(trig, HIGH);   // sets trigger pin high
        delayMicroseconds(10);      // keep trigger pin high for 10us
        
        digitalWrite(trig, LOW);
        
        duration = pulseIn(echo, HIGH);       // this function says to count the time from one 
                                              // high of echo pin to successive high of same once
                                              // it gets the pulse signal
                                              
        distance = duration*0.034/2;
        
  // speed of sound = 340 m/s
  // implies 0.034 cm/us
  // distance = (speed * time) / 2
       
          if (distance < 15)  
           { Serial.println("Moving right");
              fwd();
              //right();                            // function for right turn
              delay(500);
           } 
           else 
           
           { Serial.println("Moving Forward");
              right(); 
              //fwd();                              // function for forward movement
           }       

}      

void fwd()                                      // defigning function for forward movement

{ 
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,HIGH);
  digitalWrite(motorL2,LOW);

}
void bck()                                       // defigning function for backward movement
{ 
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,HIGH);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,HIGH);

}
void left()                                     // defigning function for left turn
{
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,HIGH);

}

void right()                                    // defigning function for right turn
{
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,HIGH);
  digitalWrite(motorL1,HIGH);
  digitalWrite(motorL2,LOW);

}

void nomove()                                    // defigning function for no movement
{
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,LOW);
}
