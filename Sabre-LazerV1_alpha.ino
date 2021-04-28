/*--------------------------------------------------       LIBRAIRIE   ----------------------------------------------------------------*/
#include "AltSoftSerial.h" //gere les conflict serie dfplayer /encodeur








/*--------------------------------------------------       Fonction Basique  ----------------------------------------------------------------*/
#include "Fonction_temporel.h" // cronometre Crono(temps); temps en 1000/sec

#include "Fonction_batterie.h" //gestion des led batterie

#define BATLVL_PIN A6

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
#define btn2pin  A1 //tactil ====>btnT()

#include "Fonction_Bouton.h" // Kbouton(Mode,btn(),option); mode 1 simple clik ; 2 maintien_option= temps de maintien

#define pinBlink 22
#define pinEncodeurB 23
#define dureeAntiRebond 200
//increment codeur suplementaire

unsigned int incrementC = 0;
#include "Encodeur.h" //Selectcodeur(nombre voulu)








/*--------------------------------------------------       Fonction Capteur  ----------------------------------------------------------------*/
double Calibr = 8.00;
#include "Gyroscope.h" // la boleene moov defini si il y a un mouvement ou pas calibration gere la sensibilité


//a faire Piezo  pinMode(A7,INPUT); dans setup

/*--------------------------------------------------       skin et couleur  ----------------------------------------------------------------*/
#include "Skin_et_Couleur.h"

#define LED_PIN     18
#define LEDBATT_PIN 21
#define NOMBRE_LED  121
unsigned char LUMINOSITE = 10;
unsigned char LUMINOSITEBAT = 5;
#include "Bande_Led.h"

/*--------------------------------------------------       lecteur mp3  ----------------------------------------------------------------*/

#include "Lecteur_mp3.h"

void setup() {
  //Pin ALumage
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  delay(1000);

//pin niveau de batterie

  
  Serial.begin(115200);
 // Serial.begin(9600);

  // put your setup code here, to run once:



  //INITIALISATION BOUTON
  pinMode(btn1pin, INPUT);
  digitalWrite(btn1pin, HIGH);
  pinMode(btn2pin, INPUT);

  //INITIALISATION ENCODEUR
  //ecodeur rotatif sur pin analogine
  pinMode(23, INPUT);
  pinMode(22, INPUT);
  //Activer la resistance pullup interne des broche analogique pour metre les broche en tension directement depuis le microcontroleure
  digitalWrite(23, HIGH);
  digitalWrite(22, HIGH);
  // Activer l interuption pour le codeur
  attachPCINT(digitalPinToPCINT(pinBlink), lecturCodeur, FALLING);


  //INITIALISATION GYROSCOPE
  Wire.begin();//Arduino-nano sdaA5 sclA4
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  //INITIALISATION LED
  strip.begin();
  strip.setBrightness(LUMINOSITE);
  
  stripbatt.begin();
  stripbatt.setBrightness(LUMINOSITEBAT);
  nocolor();
  //eteindre tout ledbatt
  for(int i=0;i<=LED_MANCH;i++){noledmenu(i);}

  //effetled
  randomSeed(analogRead(7));

  strip.show();
  //INITIALISATION MP3

  softwareSerial.begin(9600);
  if (player.begin(softwareSerial)) {
    Serial.println("OK");
  }
  else {
    Serial.println("Fail");
  }
  volume = EEPROM.get(22, volume);
  player.volume(volume);

  //INITIALISATION Skin
  EEPROM.get(0, skinnbr);
  if (skinnbr == 1) {
    coul1sabre = EEPROM.get(1, skn1c1);
    coul2sabre = EEPROM.get(3, skn1c2);
    coulesabre = EEPROM.get(5, skn1ce);

  }
  if (skinnbr == 2) {
    coul1sabre = EEPROM.get(9, skn2c1);
    coul2sabre = EEPROM.get(11, skn2c2);
    coulesabre = EEPROM.get(13, skn2ce);

  }
  if (skinnbr == 3) {
    coul1sabre = EEPROM.get(17, skn3c1);
    coul2sabre = EEPROM.get(19, skn3c2);
    coulesabre = EEPROM.get(21, skn3ce);

  }
  





}

/*--------------------------------------------------       Etat du sabre  ----------------------------------------------------------------*/
enum {Etein, Alum, Menu, TEST} Etats = TEST;
char Etat = Etein;
//variable contenant les case des ettapes d allumage
#include "Etat_Alum.h"
#include "Etat_Menu.h"

//variable de test

int tst=8;

void loop() {


  switch (Etat) {
    case Etein:
      Serial.print("Etein   ");
      jaugebatterie(batlvl(),coul1sabre,coul2sabre);
      
      if(Crono1(20000)==0){digitalWrite(0, LOW);}
      
      if (Kbouton(1, btnT(), 0) == 1)  {
        
        Etat = Alum;
        Serial.print("Press   ");
        
      }
      if (Kbouton(2, btnC(), 2000) == 1)  {
        Etat = Menu;
        Serial.print("Press  Menu ");
        
      }
      break;

    case Alum:
      Etat_Alum(btnT());
      jaugebatterie(batlvl(),coul1sabre,coul2sabre);
      break;

    case Menu:
      Serial.print("Menu   ");
      Etat_Menu();
      break;

    case TEST:
      menuchange = 1;
      Serial.print("ok   ");
      
                                  
              
                                  Serial.print("TEST   ");
                                  Serial.print(tst);
                                  Serial.print("   Led++   ");
                                  Serial.print(analogRead(A6)-619);
                                  Serial.print(" <== Test");
                                  Serial.print(tst);
                                  Serial.print(" <== Test");
                                  if(Crono(1000)==0){Serial.print(" <== Test");}
                                  jaugebatterie(batlvl(),coul1sabre,coul2sabre);
                                  //tst++;
                                  if (tst>4){tst=0;}
                               if(millis() - timer3 > 1000){  tst++;   
                               Serial.print("   2sec");
                               timer3=millis();} 
                       //delay(1000);            
  }



  Serial.println();
}
