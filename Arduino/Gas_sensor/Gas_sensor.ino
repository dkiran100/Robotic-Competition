int gas_sensor = A0;
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(gas_sensor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(gas_sensor);
  Serial.println(gas_sensor);
  
}
