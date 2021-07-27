int rs = 8;
int ls = 9;
int trig = A2;
int echo = A1;

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(rs,INPUT);
  pinMode(ls,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

        digitalWrite(trig, LOW);              //sets trigger pin low
        delayMicroseconds(2);                 // gives delay of 2us before setting trigger pin high

        digitalWrite(trig, HIGH);             // sets trigger pin high
        delayMicroseconds(10);                // keep trigger pin high for 10us
        digitalWrite(trig, LOW);

        duration = pulseIn(echo, HIGH);
        distance = duration*0.034/2;
        
  if(digitalRead(rs) && digitalRead(ls)){
    Serial.println("Move forward");
  }
  else if(!(digitalRead(rs)) && (digitalRead(ls))){
    Serial.println("Move right");
  }
  else if((digitalRead(rs)) && !(digitalRead(ls))){
    Serial.println("Move left");
  }
  else if(distance < 5){
    Serial.println("Stop");
  }
}
