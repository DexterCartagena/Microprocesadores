#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','x'},
  {'1','2','3','-'},
  {'C','0','=','+'},
};
byte rowPins[ROWS] = {11, 10, 9, 8}; 
byte colPins[COLS] = {7, 6, 5, 4}; 
char contra[4];
int pos = 0;

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal pantalla(rs, en, d4, d5, d6, d7);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  pinMode(13,OUTPUT);
  pantalla.begin(16,2);
  pantalla.setCursor(0,0);
  pantalla.print("clave alarma:     ");
  pantalla.setCursor(0,1);
}
  
void loop(){
  char key = keypad.getKey();
   if (key){
    contra[pos] = key;
    pantalla.print(key);
    pos = pos+1;

    if(pos == 4)
     {
       if(contra[0] == '7' && contra[1] == '4' && contra[2] == '1' && contra[3] == 'C')
       {
        pantalla.setCursor(0,1);
        pantalla.print("ALARMA ENCENDIDA");
        digitalWrite(13,HIGH);
        delay(5000);
        digitalWrite(13,LOW);
        pantalla.clear();
        pantalla.setCursor(0,0);
        pantalla.print("clave alarma:        ");
        pos = 0;
       }else
       {
        pantalla.setCursor(0,1);
        pantalla.print("ERROR DE ALARMA");
        delay(3000);
        pantalla.clear();
        pantalla.setCursor(0,0);
        pantalla.print("clave alarma: ");
       }
       pos = 0;
     }
   }
}
