int led = 13;
char receive = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    receive = Serial.read();

    if(receive == '1')
    {
      digitalWrite(led,HIGH);
    }

    else if(receive == '0')
    {
      digitalWrite(led,LOW);
    }
  }
}
