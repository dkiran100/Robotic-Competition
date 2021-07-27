char op = '0';
int led = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0){
    op = Serial.read();
  }
  
  if(op == '1'){
    digitalWrite(led,HIGH);
  }
  else if(op == '0'){
    digitalWrite(led,LOW);
  }

  Serial.println("End");

}
