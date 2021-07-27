int rs = 8;
int ls = 9;
//int trig = A2;
//int echo = A1;
int lm1 = 10;
int lm2 = 11;
int rm1 = 12;
int rm2 = 13;

//long duration;
//long distance;

void setup() {
  // put your setup code here, to run once:
  //pinMode(trig,OUTPUT);
  //pinMode(echo,INPUT);
  pinMode(rs,INPUT);
  pinMode(ls,INPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
      /*
        digitalWrite(trig, LOW);              //sets trigger pin low
        delayMicroseconds(2);                 // gives delay of 2us before setting trigger pin high

        digitalWrite(trig, HIGH);             // sets trigger pin high
        delayMicroseconds(10);                // keep trigger pin high for 10us
        digitalWrite(trig, LOW);

        duration = pulseIn(echo, HIGH);
        distance = duration*0.034/2;
        */
  if(digitalRead(rs) && digitalRead(ls)){
    Serial.println("Move forward");
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
  }
  else if(!(digitalRead(rs)) && (digitalRead(ls))){
    Serial.println("Move right");
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, HIGH);
  }
  else if((digitalRead(rs)) && !(digitalRead(ls))){
    Serial.println("Move left");
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
  }
  else if(!(digitalRead(rs)) && !(digitalRead(ls))){
    Serial.println("Stop");
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, HIGH);
  }
}
