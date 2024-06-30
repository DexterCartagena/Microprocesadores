int tecla;
char boton[]={'7','4','1','C','8','5','2','0','9','6','3','=','/','X','-','+'};
void setup() {
  DDRB=00000000;
  pinMode(2,INPUT);
  attachInterrupt(0,presion,RISING);
  Serial.begin(9600);

}

void loop() {
  

}
void presion(){
  tecla=PINB&(0b00001111);
  Serial.print("posicion tecla: ");
  Serial.print(tecla);
  Serial.print("  tecla presionada: ");
  Serial.println(boton[tecla]);
} 
