int gas = A0;
int temp = A1;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      // PC to Arduino Serial Monitor   
  pinMode(gas, INPUT);
  pinMode(temp,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int gas_val = analogRead(gas);
  Serial.print("Gas Sensor Value : ");
  Serial.println(gas);
  delay(1000);
  int t = analogRead(temp);
  Serial.print("Temperature Sensor Value : ");
  t = (t*500)/1023;
  Serial.println(t);
  if(t > 30){
    Serial.println("Fire");
    digitalWrite(led,HIGH);
  }
  delay(1000);
  

}
