int qtrPins[] = {3,4,5,6,7,8};
int qtrValues[] = {0,0,0,0,0,0};

const byte trigger_pin;
const byte echo_pin;
int uzaklık;
int sure;

//ultrasonic pins
void defineultPins(){

  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
}

//qtr pins
void defineqtrPins(){
  int i;
  for(i=0; i<6; i++){
    pinMode(qtrPins[i],INPUT_PULLUP);
  }
}

void ultrasonicCheck(){

  digitalWrite(trigger_pin,LOW);
  delay(5);
  digitalWrite(trigger_pin,HIGH);
  delay(10);
  digitalWrite(trigger_pin,LOW);

  //echo check value

  sure = pulseIn(echo_pin,HIGH);
  uzaklık = sure*0.034/2;

  if(uzaklık > 150)
    return 150;

   return uzaklık;
  
}

void qtrValueCheck(){
  int i;

  for(i=0; i<6; i++){
    qtrValues[i] = digitalRead(qtrPins[i]);
  }

  for(i=0; i<6; i++){
      Serial.print(qtrValues[i]);
  }
  delay(500);
  Serial.println(" ");
}
