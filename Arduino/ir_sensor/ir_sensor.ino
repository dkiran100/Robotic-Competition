int ir = 8;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ir,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(ir) == HIGH){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }

  val = digitalRead(ir);
  Serial.println(val);
  delay(2000);
  
}
