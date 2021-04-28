


 //df player librairie

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

//#include "AltSoftSerial.h" //gere les conflict serie dfplayer /encodeur
//#include <SoftwareSerial.h>

//PINMP3TX =8;
//INMP3RX =9;
AltSoftSerial softwareSerial;
//#include <SoftwareSerial.h>
//SoftwareSerial softwareSerial(10,11);// TX,RX
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
