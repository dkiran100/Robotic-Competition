int gas_sensor = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(gas_sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogRead(gas_sensor); //Read analog values of sensor  
  Serial.print("SENSOR RAW VALUE = ");
  Serial.println(sensorValue);

}
