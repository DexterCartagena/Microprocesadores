#include <Wire.h>
#include "DFRobot_LCD.h"
  const int colorR = 255;
  const int colorG = 0;
  const int colorB = 0;
  DFRobot_LCD Pantalla(16,2); 
  
  //ESTE APARTADO ES DE EL TECLADO
  
  int tecla;
  char boton[]={'7','4','1','C','8','5','2','0','9','6','3','=','/','X','-','+'};
  int teint=0;
  int alarma=0;
void setup() 
{
    Pantalla.init();
    Pantalla.setRGB(colorR, colorG, colorB);
    
    
    //CONFIGURACION DE LOS PUERTOS HACIA EL TECLADO Y LAS INTERRUPCIONES
    
    DDRB=0b00010000;
    pinMode(2,INPUT);
    attachInterrupt(0,presion,RISING);
    Serial.begin(9600);
    
}

void loop() 
{ 
  //si hay una interrupcion que muestre los valores de tecla presionada en el LCD
  
  if(teint==1)
  {
  digitalWrite(12,HIGH);
  Pantalla.setCursor(0,1);
  Pantalla.print("potec:");
  Pantalla.print(tecla);
  Pantalla.print(" vatec:");
  Pantalla.print(boton[tecla]);
  delay(100);
  digitalWrite(12,LOW);
  teint=0;
  }
}
void presion()
{
  tecla=PINB&(0b00001111);
  teint=1;
  
}
