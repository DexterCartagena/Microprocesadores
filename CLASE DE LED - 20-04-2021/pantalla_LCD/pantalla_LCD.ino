#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal pantalla(rs, en, d4, d5, d6, d7);
const int rs1 = 7, en1 = 6, d41 = 5, d51 = 4, d61 = 3, d71 = 2;
LiquidCrystal pantalla1(rs1, en1, d41, d51, d61, d71);

void setup() {
  pantalla.begin(16,2);
  pantalla1.begin(16,2);
  pantalla.setCursor(3,0);
  pantalla.print("HOLA DIANA ");
  delay(1000);
  pantalla.display();
  pantalla1.setCursor(2,0);
  pantalla1.print("HOLA DENY ");
  delay(1000);
  pantalla.setCursor(2,1);
  pantalla.print("COMO ESTAS? ");
  delay(1000);
  pantalla1.setCursor(0,1);
  pantalla1.print("ESTOY BIEN GRACIAS ");
  
  

}

void loop() {
  //pantalla.setCursor(0,1);
  //pantalla.print(" A TODOS USTEDES ");
  //delay(500);

}
