


//encodeur
#define pinBlink A1
#define pinEncodeurB A2


//bouton
#define btn1pin  12 //poussoire du codeur ====>btnC
#define btn2pin  A0 //tactil ====>btnT()

//Led
#define LED_PIN     6

//dfplayer
#include "AltSoftSerial.h" //gere les conflict serie dfplayer /encodeur

//PINMP3TX =8;
//INMP3RX =9;
AltSoftSerial softwareSerial;
//SoftwareSerial softwareSerial(10,11);// TX,RX
//#define softwareSerial Serial1
