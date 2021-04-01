


 //df player librairie

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

//PINMP3TX =8;
//INMP3RX =9;
AltSoftSerial softwareSerial;
//SoftwareSerial softwareSerial(10,11);// RX,TX
//#define softwareSerial Serial1

DFRobotDFPlayerMini player;
DFRobotDFPlayerMini myDFPlayer;


//option

unsigned char volume=30;


void sonmenu(unsigned short sonnum){
                                         ;
                                    if(menuchange==1){player.play(sonnum);
                                                      Serial.print("  ");Serial.print("Le son ");Serial.print(sonnum);Serial.print(" joue ");
                                                      delay(500);
                                                      }
  
  }
