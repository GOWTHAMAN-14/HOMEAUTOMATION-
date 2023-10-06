int in1 = 10;
int in2 = 9;
String voice;
void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  digitalWrite(in1,HIGH);//Since load is connected to NC trminal of
  digitalWrite(in2,HIGH);//load
  Serial.begin(9600);
}
void loop(){
  while (Serial.available()){
    delay(10);
    char c = Serial.read();
    if (c=='#'){
      break;
    }
    voice+=c;
  }
  if (voice.length()>0){
    if (voice=="*light on"){
      digitalWrite(in1,LOW);
    }
    else if (voice=="*fan on"){
      digitalWrite(in2,LOW);
    
    else if (voice=="*light off"){
      digitalWrite(in1,HIGH);
    }
    else if (voice=="*fan off"){
      digitalWrite(in2,HIGH);
    }
    voice ="";
    
  }
}
