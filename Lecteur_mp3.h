

 //df player librairie

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
static const uint8_t PINMP3TX =2;
static const uint8_t PINMP3RX =3 ;
AltSoftSerial softwareSerial;
DFRobotDFPlayerMini player;
DFRobotDFPlayerMini myDFPlayer;


//option

unsigned char volume=30;
unsigned char selecvolum;
