int s[4] = {0,0,0,0} , temp[4] = {0,0,0,0} , t = 0;
char sa[4] = {'a','b','c','d'} , st;
char sig;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0){
    Serial.print("Enter char : ");
    sig = Serial.read();
  }

  if(sig == 'a'){
    s[0]++;
  }
  else if(sig == 'b'){
    s[1]++;
  }
  else if(sig == 'c'){
    s[2]++;
  }
  else if(sig == 'd'){
    s[3]++;
  }

  if(s[0]%10 == 0 || s[1]%10 == 0 || s[2]%10 == 0 || s[3]%10 == 0){
    for(int i = 0 ; i < 3 ; i++){
      temp[i] = s[i];
    }

    for(int i = 0 ; i < 3 ; i++){
      for(int j = i+1 ; j < 3 ; j++){
        if(temp[i] > temp[j]){
          t = temp[i];
          st = sa[i];
          temp[i] = temp[j];
          sa[i] = sa[j];
          temp[j] = t;
          sa[j] = st;
        }
      }
    }

    delay(10);
    Serial.print("Green light - ");
    delay(10);
    Serial.println(sa[3]);

    delay(10);
    
  }

}
