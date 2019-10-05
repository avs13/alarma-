

#include <Wire.h>
#include <Adafruit_GFX.h>   
#include <Adafruit_SSD1306.h> 
#define ANCHO 128
#define ALTO 64    
#define OLED_RESET 4  
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);
int menuPos = 1;

void setup() {
  Wire.begin(); 
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}
void loop() {
if(digitalRead(2) == HIGH) {
  menuPos = menuPos - 1;
  while(1){
    if(digitalRead(2) != HIGH){
      break;
    }
  }
}
if(digitalRead(3) == HIGH) {
  menuPos = menuPos + 1;
  while(1){
    if(digitalRead(3) != HIGH){
      break;
    }
  }
}
menu(menuPos);  

}
void menu(int posicion) {
  switch(posicion){
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
  }
}//alarma cambio de rama prueba
