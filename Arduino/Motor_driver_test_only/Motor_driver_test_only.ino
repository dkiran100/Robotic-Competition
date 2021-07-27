int lm1 = 10;
int lm2 = 11;
int rm1 = 12;
int rm2 = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
}
