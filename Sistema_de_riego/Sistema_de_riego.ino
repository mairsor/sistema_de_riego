#include <LiquidCrystal_I2C.h> //Librería que permite usar el controlador I2C
LiquidCrystal_I2C lcd(0x27,16,2); //Asignar dirección del LCD

int humedad = 0;
int estado = 0;

int bomba = 8; //Dar nombre al PIN digital

void setup() {
  
  Serial.begin(9600); //Para activar monitor serial

  //LCD
  lcd.init(); //Prender el LCD
  lcd.backlight(); //Prender la luz del LCD
  lcd.clear(); //Para borrar todo lo que estaba en la pantalla 
  //Fin del LCD

  pinMode(bomba, OUTPUT);

}

void loop() {
  
  humedad = analogRead(A0); //Está leyendo el pin A0, el cual registra de forma analógica los datos envidados por el sensor de humedad.

  delay(500); //Atrasa una acción en milisegundos. En este caso, 500 milisegundos, osea, medio segundo.
  
  //imprimirLCD(humedad, estado);
  Serial.println(humedad);

  if((humedad<=200)||(humedad>=1024)){
    imprimirLCD(humedad, 0);
    digitalWrite(bomba, HIGH);
  }
  
  else if ((humedad>200)&&(humedad<1024)){
    imprimirLCD(humedad, 1);
    digitalWrite(bomba, LOW);
  }

}

void imprimirLCD(int valor, int estado){
  lcd.setCursor(0,0);
  lcd.print("Humedad: ");
  lcd.print(valor); 
  lcd.setCursor(12,0);
  lcd.print("");
  lcd.setCursor (0,1);

  if (estado == 0) lcd.print("Regando: NO");
  else lcd.print("Regando: SI");

  
}


/*
 Board I2C / TWI pins
Uno       =   A4 (SDA), A5 (SCL)
Mega2560  =   20 (SDA), 21 (SCL)
Leonardo  =   2 (SDA), 3 (SCL)
Due       =   20 (SDA), 21 (SCL), SDA1, SCL1
esta configuracion de estos pines se encuentran dentro de la librería "wire" mas info: https://www.arduino.cc/en/Reference/Wire

*/