
#include <Wire.h>
#include <Adafruit_GFX.h>   
#include <Adafruit_SSD1306.h> 
#include <EEPROM.h>

#define ANCHO 128
#define ALTO 64    
#define OLED_RESET 4
#define CE_PIN 9
#define CSN_PIN 10

byte direccion[5] ={'c','a','n','a','l'};

RF24 radio(CE_PIN, CSN_PIN);

Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);
int menuPos = 1;
float datos[3];
void setup() {
  Wire.begin(); 
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  radio.begin();
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  inicio();
  menu(menupos);
  radio.openWritingPipe(direccion);
}
void loop() {
button();
}
void menu(int posicion) {
  switch(posicion){
    case 0:
    menuPos = 1;
    break;
    case 1:
    oled.clearDisplay();      
    oled.setTextColor(WHITE);   
    oled.setTextSize(1);      
    oled.setCursor(0, 0);     
    oled.print("HOLA"); 
    oled.display();     
    break;

    case 2:
    oled.clearDisplay();      
    oled.setTextColor(WHITE);   
    oled.setTextSize(1);      
    oled.setCursor(0, 0);     
    oled.print("Oscar"); 
    oled.display();     
    break;

    case 3:
    oled.clearDisplay();      
    oled.setTextColor(WHITE);   
    oled.setTextSize(1);      
    oled.setCursor(0, 0);     
    oled.print("Avs13"); 
    oled.display();     
    break;
   
    case 4:
    oled.clearDisplay();      
    oled.setTextColor(WHITE);    
    oled.setTextSize(1);      
    oled.setCursor(0, 0);     
    oled.print("No se"); 
    oled.display();     
    break;
    case 5:
    menuPos = 4;
    break;
  }
}

void inicio(){
    oled.clearDisplay();      
    oled.setTextColor(WHITE);    
    oled.setTextSize(2);      
    oled.setCursor(0, 0);     
    oled.print("Bienvenido"); 
    oled.display();     
    break;
    delay(3000);
}
void button(){
  if(digitalRead(2) == HIGH){
    menuPos = menuPos - 1;
    menu(menuPos);  
    delay(100);
    while(!digitalRead(2));
  }
  if(digitalRead(3) == HIGH){
    menuPos = menuPos + 1;
    menu(menuPos); 
    delay(100);
    while(!digitalRead(3));
  }
  if(digitalRead(4) == HIGH){
    delay(100);
    while(!digitalRead(4));
  }
}
void envio(){
   bool ok = radio.write(datos, sizeof(datos));
   if(ok)
  {
     Serial.print("Datos enviados: "); 
     Serial.print(datos[0]); 
     Serial.print(" , "); 
     Serial.print(datos[1]); 
     Serial.print(" , "); 
     Serial.println(datos[2]); 
  }
  else
  {
     Serial.println("no se ha podido enviar");
  } 3ssa
  delay(100);
}
