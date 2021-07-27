#define rm1 7
#define rm2 6


void setup() {
  // put your setup code here, to run once:
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(rm1,HIGH);    //Move back
  digitalWrite(rm2,LOW);
  delay(3000);
  
  digitalWrite(rm1,LOW);    //Move front
  digitalWrite(rm2,HIGH);
  delay(5000);
  
}
