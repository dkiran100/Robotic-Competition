#define rm1 12
#define rm2 13
#define lm1 11
#define lm2 10

#define ls 8
#define rs 9

void setup() {
  // put your setup code here, to run once:
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(ls, INPUT);
  pinMode(rs, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!(digitalRead(ls)) && !(digitalRead(rs)))
  {
  digitalWrite(rm1,LOW);    //Move forward
  digitalWrite(rm2,HIGH);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  }
  
  if((digitalRead(ls)) && (digitalRead(rs)))
  {
  digitalWrite(rm1,LOW);    //stop
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  }

  if(!(digitalRead(rs)) && (digitalRead(ls)))
  {
  digitalWrite(rm1,LOW);    //Move left
  digitalWrite(rm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  }

  if((digitalRead(rs)) && !(digitalRead(ls)))
  {
  digitalWrite(rm1,HIGH);    //Move right
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  }
  /*
  digitalWrite(rm1,HIGH);    //Move back
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  */
}
