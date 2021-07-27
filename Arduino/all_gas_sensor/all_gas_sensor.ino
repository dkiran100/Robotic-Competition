int smoke = A0;
int alc = A1;
int CO = A2;
int sm , al , co;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(smoke,OUTPUT);
  pinMode(alc,OUTPUT);
  pinMode(CO,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  sm = analogRead(smoke);
  Serial.print("Smoke = ");
  Serial.println(co);
  alc = analogRead(alc);
  Serial.print("Alcohol = ");
  Serial.println(co);
  co = analogRead(CO);
  Serial.print("Carbon Monoxide = ");
  Serial.println(co);
  delay(2000);
  Serial.println();
  
}
