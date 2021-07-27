int i1 = 12;
int i2 = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(i1,OUTPUT);
  pinMode(i2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(i1,LOW);
  digitalWrite(i2,HIGH);
}
