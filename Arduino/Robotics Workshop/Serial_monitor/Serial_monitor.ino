int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(led,HIGH);
  Serial.println("LED is ON");
  delay(1000);
  digitalWrite(led,LOW);
  Serial.println("LED is OFF");
  delay(1000);
}
