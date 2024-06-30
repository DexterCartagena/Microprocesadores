int entradaPin=0;
int tiempo=100;

void setup() {
  
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
}

void loop() {
 entradaPin=digitalRead(10);
  if(entradaPin==1){
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    delay(tiempo);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
  }
    entradaPin=digitalRead(9);
    if(entradaPin==1){
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    delay(tiempo);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    delay(tiempo);
    digitalWrite(3,HIGH);
    digitalWrite(2,HIGH);
    delay(tiempo);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    delay(tiempo);
    }
     entradaPin=digitalRead(8);
    if(entradaPin==1){
    
    digitalWrite(1,HIGH);
    digitalWrite(0,HIGH);
    delay(tiempo);
    digitalWrite(1,LOW);
    digitalWrite(0,LOW);
    }
    else{
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(3,LOW);
      digitalWrite(2,LOW);
      digitalWrite(1,LOW);
      digitalWrite(0,LOW);
  }

}
