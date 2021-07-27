int motor1 = 3;
int motor2 = 5;

int motor3 = 6;
int motor4 = 9;

char receive = 0;
void forward()
{
  digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
}

void reverse()
{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
}

void right()
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
}

void left()
{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
}

void stopping()
{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

    if(Serial.available() > 0)
    {
      receive = Serial.read();

    if(receive == 'w')
    {
    //This bot will move front
    forward();
    }
    
    if(receive == 's')
    {
    reverse();
    }
    
    if(receive == 'd')
    {
    
    right();
    }

    if(receive == 'a')
    {
    
    left();
    }
    else if(receive == 'f')
    {
      stopping();
    }

    }
  
}
