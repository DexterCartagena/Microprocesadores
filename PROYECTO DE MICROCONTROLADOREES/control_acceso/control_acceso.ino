#include<Keypad.h>
#include<Key.h>    
#include<LiquidCrystal.h>

int a=0, b=0, c=0, d=0;
int var=0;

int C1=1, C2=2, C3=3, C4=4;

char f='*';
int veces=0,incorrecto=0;
int aviso=3;
const byte filas = 4; 
const byte columnas = 4; 
char tecla[filas][columnas] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
};
byte pinFilas[filas] = {7, 6, 5, 4}; 
byte pinColumnas[columnas] = {3, 2, A4, A5};

Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColumnas, filas, columnas );
LiquidCrystal lcd(13,12,11,10,9,8); //RS,E,D4,D5,D6,D7
void setup(){
  lcd.begin(16,2); 
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
}
 
void loop(){
  char key = keypad.getKey();
  if (key){
   lcd.setCursor(5+var,1);
   
   lcd.print(key),lcd.setCursor(5+var,1),lcd.print(f); //imprimimos el caracter en el lcd
   
   key=key-48; //COVERSIÓN DE CHAR A ENTEROS -48 SEGUN EL CÓDIGO ASCII.
   var++; //var se incrementa para los case1,case2,case3,case4.
   switch(var){
    case 1:
    a=key; 
    break;
    case 2:
    b=key;
    break;
    case 3:
    c=key; 
    break;
    case 4:
    d=key;
   delay(100);
  if(a==C1 && b==C2 && c==C3 && d==C4){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("CLAVE");
    lcd.setCursor(3,1);
    lcd.print("CORRECTA");
    digitalWrite(A0,HIGH);
    delay(700);
    lcd.clear();
    digitalWrite(A0,LOW);
    }
  else{
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("CLAVE");
    lcd.setCursor(2,1);
    lcd.print("ERRONEA");
    digitalWrite(A1,HIGH);
    delay(400);
    lcd.clear();
    digitalWrite(A1,LOW);
    }
//------Seguridad para la contraseña y sus restricciones-------------------//

  if(a==C1 && b==C2 && c==C3 && d==C4){
      veces=0;//si es correcto el clave ,variable veces no se incremeta.
      aviso=3;//variable aviso se mantiene en 3
    }
  else{
      veces ++; //incrementamos los intentos incorrectos de clave para el bloqueo.
      aviso --; //decremento de variable aviso ,de 3 hasta 0 según las veces de fallas al ingresar el clave.
      lcd.setCursor(2,0);
      lcd.print("LE QUEDAN: ");
      lcd.setCursor(13,0);
      lcd.print(aviso);
      lcd.setCursor(2,1);
      lcd.print("INTENTOS");
       if(aviso==0){
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("ACCESO");
          lcd.setCursor(4,1);
          lcd.print("DENEGADO");
        }
      delay(500);lcd.clear();
      }

  while(veces>=3){
      lcd.setCursor(1,0),lcd.print("BLOQUEO DE");
      lcd.setCursor(4,1),lcd.print("INGRESO");
      digitalWrite(A1,HIGH);
      delay(100);
      lcd.clear();
      digitalWrite(A1,LOW);delay(50);
  }//while es Bucle infinito de seguridad para bloquear los re intentos del clave

   var=0;
   lcd.clear();
  break;//se  termina el
  }

 }
 if(!key){lcd.setCursor(0,0),lcd.print("DIGITE CLAVE");}//portada de inicio en el LCD
  delay(2);
}
