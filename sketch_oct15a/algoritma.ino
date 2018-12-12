const byte sagi=13;
const byte sagg=12;
const byte soli=10;
const byte solg=11;

void definemotorPin() {
  pinMode(sagi,OUTPUT);
  pinMode(sagg,OUTPUT);
 pinMode(soli,OUTPUT);
 pinMode(solg,OUTPUT);
}

void followLine(){
  qtrValueCheck();
  int engelUzaklık = ultrasonicCheck();

//başlangıç noktasındaki kalın çizgi
  if(qtrValues[2] == 1 && qtrValues[3]==1 && qtrValues[1]==1){
    setMotors(200,200);
  }

//kısa çizgi üzerinde takip
//engel görünce duracak, yönelimini ayarlayacak, sonrasında rotaya girecek

    //dc motor için güç ayarı. sagi: sağ ileri, sagg: sağ geri 
    /*digitalWrite(sagi, HIGH);
    digitalWrite(sagg, LOW);
    digitalWrite(soli, HIGH);
    digitalWrite(solg, LOW);*/
    
  else if(qtrValues[2] == 1 && qtrValues[3]==1 ){
    
    if( engelUzaklık<=15){
    setMotors(0,0);
    delay(10);
    setMotors(50,200);
    delay(1000);
    setMotors(200,200);
    delay(2000);
    setMotors(200,50);
    delay(1000);
    }
  }


  

  
    
}

void loop() {
  followLine();

}
