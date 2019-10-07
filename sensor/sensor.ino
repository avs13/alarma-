#include <SPI.h>
#include <nrf24l01.h>
#include <RF24.h>
#include ultrasonico.h
#include <EEPROM.h>
#define echo          3
#define triger        2

#define CE_PIN 9
#define CSN_PIN 10

byte direccion[5] = {1,1,1,1,1}
RF24 radio(CE_PIN,CSN_PIN);

int datos[3];
boolean stateAlar == 0;
float distanci;
void setup(){
  
}
void loop(){
  
}
void alarma(){
  if(stateAlarm == HIGH){
    distanci = ultrasonic.distance();
    if(distancia > distanci){
      if(pir() == HIGH)
      sendData();
      stateAlar == 0;
    }
  }
}
void sendData(){
  
}
void pir(){
  
}
