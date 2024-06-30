#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','x'},
  {'1','2','3','-'},
  {'C','0','=','+'},
};
byte rowPins[ROWS] = {11, 10, 9, 8}; 
byte colPins[COLS] = {7, 6, 5, 4}; 

Keypad teclado = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = teclado.getKey();
  
  if (key)
  {
    Serial.println(key);
  }
}
