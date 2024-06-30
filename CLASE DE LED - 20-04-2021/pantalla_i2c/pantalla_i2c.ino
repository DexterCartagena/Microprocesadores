#include <Wire.h>
#include "DFRobot_LCD.h"

  const int colorR = 255;
  const int colorG = 0;
  const int colorB = 0;

  DFRobot_LCD pantalla(16,2); 
void setup() {
  pantalla.init();
  pantalla.setRGB(colorR, colorG, colorB);
  pantalla.print("BIENVENIDOS");

}

void loop() {
 
}
