/*--------------------------------------------------       LIBRAIRIE   ----------------------------------------------------------------*/
#include "AltSoftSerial.h" //gere les conflict serie dfplayer /encodeur








/*--------------------------------------------------       Fonction Basique  ----------------------------------------------------------------*/
#include "Fonction_temporel.h" // cronometre Crono(temps); temps en 1000/sec

//   if(millis() - timer > XXXX){timer = millis();} fais une fois tout les XXXXms

//Memoire morte
#include<EEPROM.h>
/*
Secteur utilisé
___Skin
0-21
___Volum
22
___Luminosité
23



*/



/*--------------------------------------------------       Fonction Interface  ----------------------------------------------------------------*/
#define btn1pin  12 //poussoire du codeur ====>btnC
#define btn2pin  A0 //tactil ====>btnT()

#include "Fonction_Bouton.h" // Kbouton(Mode,btn(),option); mode 1 simple clik ; 2 maintien_option= temps de maintien

#define pinBlink A1
#define pinEncodeurB A2
#define dureeAntiRebond 150
//increment codeur suplementaire

unsigned int incrementC=0;
#include "Encodeur.h" //Selectcodeur(nombre voulu)





/*--------------------------------------------------       Fonction Capteur  ----------------------------------------------------------------*/
double Calibr=8.00;
#include "Gyroscope.h" // la boleene moov defini si il y a un mouvement ou pas calibration gere la sensibilité


//a faire Piezo  pinMode(A7,INPUT); dans setup

/*--------------------------------------------------       skin et couleur  ----------------------------------------------------------------*/
#include "Skin_et_Couleur.h"

#define LED_PIN     6
#define NOMBRE_LED  119
unsigned char LUMINOSITE=5;
#include "Bande_Led.h" 

/*--------------------------------------------------       lecteur mp3  ----------------------------------------------------------------*/

#include "Lecteur_mp3.h" 

void setup() {
    //Pin ALumage
    pinMode(4,OUTPUT);
    digitalWrite(4,HIGH);
    // Serial.begin(9600);
  
  // put your setup code here, to run once:
     


    //INITIALISATION BOUTON
      pinMode(btn1pin,INPUT);
      digitalWrite(btn1pin,HIGH);
      pinMode(btn2pin,INPUT);

    //INITIALISATION ENCODEUR
      //ecodeur rotatif sur pin analogine
      pinMode(A1,INPUT);
      pinMode(A2,INPUT);
      //Activer la resistance pullup interne des broche analogique pour metre les broche en tension directement depuis le microcontroleure
      digitalWrite(A1,HIGH);
      digitalWrite(A2,HIGH);
       // Activer l interuption pour le codeur
       attachPCINT(digitalPinToPCINT(pinBlink), lecturCodeur, FALLING);


     //INITIALISATION GYROSCOPE
      //Wire.begin();
      //mpu6050.begin();
     // mpu6050.calcGyroOffsets(true);
       
       //INITIALISATION LED
      strip.begin(); 
      strip.setBrightness(LUMINOSITE);
      nocolor();

      //effetled
      randomSeed(analogRead(7));
     
      strip.show();
    //INITIALISATION MP3
      
      softwareSerial.begin(9600);
      if(player.begin(softwareSerial)){
      Serial.println("OK");}
      else{Serial.println("Fail");}
      volume=EEPROM.get(22, volume);
      player.volume(volume);

    //INITIALISATION Skin
      EEPROM.get(0,skinnbr);
      if(skinnbr==1){
                      coul1sabre=EEPROM.get(1, skn1c1);
                      coul2sabre=EEPROM.get(3, skn1c2);
                      coulesabre=EEPROM.get(5, skn1ce);
                      
                      }
      if(skinnbr==2){
                      coul1sabre=EEPROM.get(9, skn2c1);
                      coul2sabre=EEPROM.get(11,skn2c2);
                      coulesabre=EEPROM.get(13,skn2ce);
                      
                      }
      if(skinnbr==3){
                      coul1sabre=EEPROM.get(17, skn3c1);
                      coul2sabre=EEPROM.get(19, skn3c2);
                      coulesabre=EEPROM.get(21, skn3ce);
                      
                      }
      
      
         
      
   
}

/*--------------------------------------------------       Etat du sabre  ----------------------------------------------------------------*/
enum {Etein,Alum,Menu,TEST}Etat=Etein;
 //variable contenant les case des ettapes d allumage
#include "Etat_Alum.h" 
#include "Etat_Menu.h" 

void loop() {
  
              
              switch(Etat){
                          case Etein:
                          Serial.print("Etein   ");
                          if(Kbouton(1,btnT(),0)==1){Etat=Alum;seq1=0;}
                          if(Kbouton(1,btnC(),1000)==1){Etat=Menu;seq=0;delay(1000);}
                          break;

                          case Alum:
                          Etat_Alum(btnT());
                          break;

                          case Menu:
                          Serial.print("Menu   ");
                          Etat_Menu();
                          break;

                          case TEST:
                          menuchange=1;
                          Serial.print(ok);
                          Serial.print("  strip ");   
                          Serial.print((int)strip.numPixels());   
                          Serial.println();

                          
                          Serial.print("Sa va finir par marcher ");
                          
                          delay(1000);
                          break;
                          }

 

Serial.println();
}
