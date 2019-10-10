#include <SPI.h>
#include <RF24.h>
#include "ultrasonico.h"
#include <EEPROM.h>
#define echo          3
#define triger        2

#define CE_PIN 9
#define CSN_PIN 10
#define PIR 4
byte direccion[5] = {1,1,1,1,1};
RF24 radio(CE_PIN,CSN_PIN);
float datos[3];
boolean stateAlarm = 0;
float distancia = EEPROM.read(0);
boolean estado;
int distanciaU = 0;
Ultrasonic ultrasonic;

void setup(){
  pinMode(echo,INPUT);
  pinMode(triger,OUTPUT);
  pinMode(PIR,INPUT);

  radio.begin();
  radio.openReadingPipe(1, direccion);
  radio.stopListening();
 
}
void loop(){
  receiveData();
  alarma();
}
void alarma(){
  if(stateAlarm == HIGH){
    distanciaU = ultrasonic.distance();
    Serial.println(distancia);
    if(distanciaU > distancia){
      if(PIR == HIGH){
        sendData();
        stateAlarm == 0;
      }
    }
  }
}
void sendData(){
  
}
/*void pir(){
  if(digitalRead(PIR) == HIGH){
    return 1;
  }
  else{
    return 0;
  }
}*/
void receiveData(){
  if (radio.available()){   
    radio.read(datos,sizeof(datos));
    if(datos[0] == 1){
      stateAlarm == 1;
    }
    else {
      stateAlarm == 0;
    }
    if(datos[1] == 1){
      autocalibrado();
      datos[1] = 0;
    }
    if(datos[1] == 2){
      distancia = datos[2];
      datos[1] == 0;
    }
  }
}
void autocalibrado(){
  
  distancia = ultrasonic.distance();
  EEPROM.write(0,distancia - 10);
  distanciaU = EEPROM.read(0);
  
}
