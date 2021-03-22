/*--------------------------------------------------       LIBRAIRIE   ----------------------------------------------------------------*/
#include "AltSoftSerial.h" //gere les conflict serie dfplayer /encodeur








/*--------------------------------------------------       Fonction Basique  ----------------------------------------------------------------*/
#include "Fonction_temporel.h" // cronometre Crono(temps); temps en 1000/sec

//   if(millis() - timer > XXXX){timer = millis();} fais une fois tout les XXXXms



/*--------------------------------------------------       Fonction Interface  ----------------------------------------------------------------*/
#define btn1pin  12 //poussoire du codeur ====>btnC
#define btn2pin  A0 //tactil ====>btnT()

#include "Fonction_Bouton.h" // Kbouton(Mode,btn(),option); mode 1 simple clik ; 2 maintien_option= temps de maintien

#define pinBlink A1
#define pinEncodeurB A2
#define dureeAntiRebond 100
#include "Encodeur.h" //Selectcodeur(nombre voulu)

/*--------------------------------------------------       Fonction Capteur  ----------------------------------------------------------------*/
double Calibr=8.00;
#include "Gyroscope.h" // la boleene moov defini si il y a un mouvement ou pas calibration gere la sensibilité


//a faire Piezo  pinMode(A7,INPUT); dans setup

/*--------------------------------------------------       skin et couleur  ----------------------------------------------------------------*/
#include "Skin_et_Couleur.h"

#define LED_PIN     5
#define NOMBRE_LED  237
unsigned char LUMINOSITE=5;
#include "Bande_Led.h" 

/*--------------------------------------------------       lecteur mp3  ----------------------------------------------------------------*/

#include "Lecteur_mp3.h" 

void setup() {
  // put your setup code here, to run once:
     Serial.begin(250000);


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
       Wire.begin();
       mpu6050.begin();
       mpu6050.calcGyroOffsets(true);
       
       //INITIALISATION LED
      strip.begin(); 
      strip.setBrightness(LUMINOSITE);
      for(int i;i<NOMBRE_LED;i++){strip.setPixelColor(i, strip.Color(0,   0,   0) );}
     
      strip.show();
    //INITIALISATION MP3
      
      softwareSerial.begin(9600);
      if(player.begin(softwareSerial)){
      Serial.println("OK");}
      else{Serial.println("Fail");}

      player.volume(volume);

      
      

      
   
}

/*--------------------------------------------------       Etat du sabre  ----------------------------------------------------------------*/
enum {Etein,Alum,Menu,TEST}Etat=Etein;
#include "Etat_Alum.h" 

void loop() {
  
              
              switch(Etat){
                          case Etein:
                          Serial.print("Etein   ");
                          if(Kbouton(1,btnT(),0)==1){Etat=Alum;}
                          break;

                          case Alum:
                          Etat_Alum(btnT());
                          break;

                          case Menu:
                          break;

                          case TEST:
                          Serial.print(ok);
                          break;
                          }

 
    Serial.print("  strip ");   
    Serial.print((int)strip.numPixels());   
Serial.println();

}
