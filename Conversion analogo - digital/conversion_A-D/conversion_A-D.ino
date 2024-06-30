int ADCIN;
void setup() {
  Serial.begin(9600); //velocidad al que va trabajar mi terminal virtual(pantalla)

}

void loop() {
  ADCIN=analogRead(A0);
  Serial.print("Lectura ADC0: ");
  Serial.println(ADCIN);
  delay(10);
  ADCIN=analogRead(A1);
  Serial.print("Lectura ADC1: ");
  Serial.println(ADCIN);
  delay(10);

}
