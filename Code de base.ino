#include "AltSoftSerial.h"

#include <MPU6050_tockn.h>
#include <Wire.h>
#include "PinChangeInterrupt.h"
//Module mG
MPU6050 mpu6050(Wire);
unsigned long timer = 0;
unsigned long timer2 = 0;
//Module mp3

//Led adressable
#include <Adafruit_NeoPixel.h>
#define LED_PIN     5
#define LED_COUNT  237
#define BRIGHTNESS 5
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB);

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
static const uint8_t PINMP3TX =2;
static const uint8_t PINMP3RX =3 ;
AltSoftSerial softwareSerial;
DFRobotDFPlayerMini player;
DFRobotDFPlayerMini myDFPlayer;


 //Fonction de Temporalité 3 Cycle de fonctionnement (Lecture etat,Led Principal,Bande Led) par milis(1)) Vire Tempsactuel
      
      
      /* Fonction LectureTemps general*/
 
      unsigned char Tempsactuel;
      unsigned int Boucletemps;
      unsigned long Temps;
   
    unsigned long CTemps;
      void Montre(){
  
              Temps=millis();
        
        if (Temps>=CTemps){Tempsactuel++;}
        CTemps=Temps/1000;
                    }


   /* FonctionCrono return I/O*/
 
      unsigned long Debutcrono;
      unsigned long Arfcrono;
      unsigned char Scrono;
      unsigned char Mcrono;
      boolean Oncrono;
      boolean unfoi=1;
      
   
      int CronoS(int temps){
                           
                                            if(Debutcrono != CTemps){Scrono++;}
                                            
                                            Debutcrono=CTemps;
                                            if (Scrono>temps){;Oncrono=0;return 0;}
                                            return 1;}
                            
                  

        int CronoM(int temps){
                            
                            if (Oncrono==1){
                                            
                                            if (Arfcrono != millis()){ Mcrono++;}
                                            Arfcrono = millis();
                                            if (Mcrono>temps){Oncrono=0; return 0;}
                                            else{return 1;}
                                            }
                            else {Mcrono=0;return 0;}
                  
                            }
                             /*       int CronoM(int temps){
                            if (Oncrono==1){
                                            if (unfoi == 1){Debutcorono = millis(); unfoi=0}

                                            Mcrono++;
                                            
                                            if (millis()-Debutcrono>=temps){;Oncrono=0;return 0;}
                                            return 1;}
                            else {Scrono=0;}
                  
                            }*/
           
  
                            

 //Bouton 3 option (1-Clique,2-Maintien(Optionmode temps en seconde),3-on/off)
       
       /* la fonction de lecture du bouton a trois option et ces diferent parametre (Option,n°Bouton,Parametre du mode)
        et retourne I/0

        ?else return 0???????*/
       const int btn1pin = 12 ;
       const int btn2pin = A0 ;
      volatile boolean btnM = 0;
      volatile boolean btnmenu=!digitalRead(btn1pin);
       volatile boolean btnO = 0;
       boolean InternOK;
      //Fonction lecture bouton sur A0

     volatile boolean btnA(){
      if(analogRead(btn2pin)>500){return 1;}
      else{return 0;}
      
      }
      //Fonction bouton
       
       int Kbouton(int Option,int Bouton,int Optionmode){

                                        switch(Option){

 //clic
  case 1 :
  //lecture des bouton
  btnM=!digitalRead(btn1pin);
  btnO=btnA();
      if (Bouton == 1) {
         return 1;}
         else{return 0;}      
           
            
            break;

  //Maintien
  case 2 :
    //lecture des bouton
  btnM=!digitalRead(btn1pin);
  btnO=btnA();
 if (Bouton==1){
    Serial.print("Le bouton est presser");
    if (CronoS(Optionmode)== 1){Serial.print("  mais inactif");Serial.println ();return 0;}
    else{Serial.print("  Actif");return 1;}
    Serial.println ();
    }
 else{Oncrono=1;Scrono=0;return 0;}
                                                                break;



                                                         // On/off
                                                           case 3 :
                                                                      //lecture des bouton
  btnM=!digitalRead(btn1pin);
                                                                    if (Bouton == 1) {InternOK = !InternOK;Serial.print("Le bouton est presser");} 
                                                                    if (InternOK == 1) {Serial.print(" Actif");return 1;}
                                                                    else{Serial.print(" Inactif");return 0;}
                                                                    Serial.println ();

                                                                    break;
                                                        
                                                        }
                                                  }
 //Codeur rotatif Veleur renvoyer 0 - Min et Max sont defini en tant que parametre. les pine son codeurG codeurD
#define pinBlink A1
int pinEncodeurB= A2;

volatile byte compte = 0;
int rotVal;
int bouton;

const unsigned long dureeAntiRebond = 100;



//utiliser le codeur comme selecteur (nombre de sewlection)
  
 unsigned int Valcodeur;
  unsigned int Nbactuel ;
  unsigned char internX ;
  
int Selectcodeur(int nbselect){

  
  if (internX < (compte) ){Nbactuel++;}
  if (internX > (compte) ){Nbactuel--;}
  internX = compte;

  if (Nbactuel< 0){Nbactuel = nbselect;}
  if (Nbactuel> nbselect){Nbactuel = 
  0;}
  

  Valcodeur = Nbactuel;
  return Valcodeur;
}

 unsigned int Valcodeur2;
  unsigned int Nbactuel2 ;
  unsigned char internY ;
  
int Selectcodeurplus(int nbselect,unsigned char inkremen){

  
  if (internY < (compte) ){Nbactuel2++; Nbactuel2 = Nbactuel2+inkremen;}
  if (internY > (compte) ){Nbactuel2--; Nbactuel2 = Nbactuel2-inkremen;}
  internY = compte;


 
  if (Nbactuel2<< 0){Nbactuel = nbselect;}
  if (Nbactuel2>> nbselect){Nbactuel = 
  0;}
  return Nbactuel2;
}
 //detection Mouvement
double anglx;
double angly;
double anglz;



double anglxC;
double anglyC;
double anglzC;

boolean rtrn;
boolean moov=0;
boolean moovN=0;

double Calibr=8.00;


boolean gyrod=0;

const unsigned long dureeAntiRebond2 = 300;

 void Gyro(){  
   if(millis() - timer > 500){
                       mpu6050.update();

              
                   if(anglx<(mpu6050.getAngleX()-Calibr)||anglx>(mpu6050.getAngleX()+Calibr)){moov=1 ;}
                    else{moov=0;}
                    if(anglz<(mpu6050.getAngleZ()-Calibr)||anglz>(mpu6050.getAngleZ()+Calibr)){moov=1 ;}
                    else{moov=0;}

                   anglx=mpu6050.getAngleX();
                   angly=mpu6050.getAngleY();
                   anglz=mpu6050.getAngleZ();

    timer = millis();}

             
                    /*
                  Serial.print(moov);
                  Serial.print("        X");
                  Serial.print(anglx);
                  Serial.print("        Z");
                  Serial.print(anglz);
                  Serial.println();


*/
                  
  
  
  

                  }

            
       


 //Fonction pilotage chromatique des couleur
  unsigned char CLPR;
    unsigned char CLPV;
      unsigned char CLPB;
      int Cal1;
      int Cal2;
    float Calibre = 7.65;
    int Colorcod;
  void Setcouleur( unsigned int Codecouleure, unsigned char Sat){
    if(Codecouleure <= 255){
                CLPR = 255 - Codecouleure;
                CLPV = Codecouleure;
                CLPB = Sat;
                }
                
    if(Codecouleure > 255 && Codecouleure <= 500){
                Cal1 = Codecouleure - 255;
                CLPV = 255 - Cal1;
                CLPB = Cal1;
                CLPR = Sat; 
                }
    if(Codecouleure > 500){
                Cal2 = Codecouleure - 500;
                CLPB = 255 - Cal2;
                CLPR = Cal2;
                CLPV = Sat; 
                }

  }



 //Fonction led



                       
  //Etat menu
  enum {Etein,Alum,Menu,TEST}Etat;
  boolean bcnact;
unsigned char nbrcodeur;

unsigned char volume=30;
unsigned char selecvolum;











  
void setup() {
  Boucletemps = 15;
  Oncrono=1;
//G
Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
//mp3
  
softwareSerial.begin(9600);
if(player.begin(softwareSerial)){
  Serial.println("OK");}
  else{Serial.println("Fail");}

 player.volume(volume);
 
 //INITIALISATION ENCODEUR
  //ecodeur rotatif sur pin analogine
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  //Activer la resistance pullup interne des broche analogique pour metre les broche en tension directement depuis le microcontroleure
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  // Activer l interuption pour le codeur
  attachPCINT(digitalPinToPCINT(pinBlink), lecturCodeur, FALLING);
  
 //INITIALISATION BOUTON
  pinMode(btn1pin,INPUT);
  digitalWrite(btn1pin,HIGH);
  pinMode(btn2pin,INPUT);

//LED
   strip.begin(); 
   strip.setBrightness(BRIGHTNESS);
    for(int i;i<LED_COUNT;i++){
    strip.setPixelColor(i, strip.Color(0,   255,   0) );
    }
   strip.show();
   
   

  //piezo
  pinMode(A7,INPUT);

  //delay
  delay(1000);
 

  //Initialisation port serie
  Serial.begin(9600);
  bcnact=1;
  Etat=Etein;
  nbrcodeur=1;
  }








int test;
int testcalc;
int menu;
char demarage=0;
char statik=0;
char extink=0;
boolean action = 1;
boolean action2 = 1;
unsigned long timestart;
unsigned long timestart2;
enum{ATTENTE,ENCOUR} et=ATTENTE;
enum{ATTENTE2,ENCOUR2} et2=ATTENTE2;
enum{inactif,calm,mov,chok}stat=inactif;
enum{rett,skins=1,audio,sensi}menu0=0;
enum{skinA=1,skinB,skinC}skinNB;
char calme;


/*fonction skin
en code selectcouleur 0-765


*/



boolean codeurchange;
boolean codeurmenu;
int Couleur1;
int Couleur2;
int CouleurEFF;
enum{C1,C2,CE,retour}couleur=C1;
unsigned char couleurC;
void Selectskin(){

                switch(couleur){
              //Selectcodeur3
              //if (codeurchange==0){if (Valcodeur==1){couleur=C1;}} ect...
                   case C1:
                    //alumer lamme couleur 1
                    switch(couleurC){
                            case 0:
                            //jouer le son
                            //passer case 1
                            break;
                            case 1:
                            Serial.print("c1 inn");
                            Serial.println();
                            //atente bouton
                            //if(bouton==1){codeurchange=1;passer case 2}
                            break;
                            case 2:
                            //Valcodeur=Couleur1;
                            //C1c++;
                            break;
                            case 3:
                            codeurchange=1;
                            //Selectcodeur(765);
                            //Couleur1=Valcodeur;
                            //if(bouton==1){/*son OK plus tempo*/codeurchange=0;couleurC=1}
                            break;
                          }
                 break;
                 case C2:break;
                 case CE:break;
                 case retour:break;
          
        }
  
  
  }



boolean tempo(int temps){

                     switch(et){
                      
                      case ATTENTE:
                      if (action == 1){timestart=millis(); et=ENCOUR;}
                      break;
                         
                      case ENCOUR:
                      if((millis()-timestart) >= temps){et=ATTENTE;  action =0;}
                      return 1;
                      break;
                      } if (action == 0){return 0;}

 }
 boolean tempo2(int temps){

                     switch(et2){
                      
                      case ATTENTE2:
                      if (action2 == 1){timestart2=millis(); et2=ENCOUR2;}
                      break;
                         
                      case ENCOUR2:
                      if((millis()-timestart2) >= temps){et2=ATTENTE2;  action2 =0;}
                      return 1;
                      break;
                      } if (action2 == 0){return 0;}

                      }
unsigned long tempsact;
unsigned long drnchng;

  boolean menubtn(){
                 tempsact=millis();
             if( digitalRead(12)==0){
                                     if ( (tempsact-drnchng) > 100){return 1;}
                                     }
              else{drnchng=tempsact;return 0;}
                 
    }

    
  char demled;
  char effect1;
  char Moov;

  int xx=10;
  int xxOFF=111;
  int xy=44;
  int xz=44;
  int www=5;

boolean son;
boolean sonmenu;
boolean sonskin;
  boolean sonskinA;
  boolean sonskinB;
  boolean sonskinC;
boolean sonson;
boolean sonsensi;
boolean sonret;
boolean sonret1;
int nbrbouton=1;
boolean sonactive;
 boolean sonreglage;
boolean sonret3;
int activemenuskin=0;
int menuskin;
int reglcool1=0;
int selecolor;
unsigned char okcouleur=0;
                                                                       int menucolor;
                                                                       int activereglageskin=0;
                                                                       boolean sonscool1=0;
                                                                       boolean sonscool2=0;
                                                                       boolean sonscool3=0;
                                                                       boolean sonscool4=0;
volatile int testm1=0;
int testm2=0;
int testm3=0;

int activeskin=0;

boolean unfcolor=0;


int color1sabr=222;
int color2sabr=222;
int coloresabr=333;


int color1skn1=333;
int color2skn1=355;
int coloreskn1=377;

int color1skn2=144;
int color2skn2=222;
int coloreskn2=252;

int color1skn3=144;
int color2skn3=222;
int coloreskn3=252;




  static unsigned long dateDernierChangement2 = 0;
 
  unsigned long date2 = millis();
  int ledemm=3;
int pos=0;
boolean opensabr(uint32_t color, int wait) {


  for (int i=0;i<ledemm;i++){
    
    strip.setPixelColor(i+pos, color);
    strip.setPixelColor((LED_COUNT - (i+pos)), color);
    Serial.print(i);
    }
  pos=pos+ledemm ;
  delay(wait);
  if(pos>LED_COUNT){pos=0;}
  
 strip.show();  
  }

void loop() {
  //lecture du temps
  Montre();
switch(Etat){
  
  case Etein: 
                              
                              
                              Selectcodeur(3);
                              
                                                Serial.println ();

        //Mise a zero
        demarage=0;
        demled=0;
        stat=inactif;
        sonret=1;
        if(millis() - timer > 1000){
        player.pause();
        timer = millis();
         }
         //Aller au menu
         if (Kbouton(2,btnM,2)==1){Etat=Menu;}
  //Serial.print("Etein");Serial.println ();
    
     if (bcnact==1){  if (Kbouton(1,btnO,0)==1){      Serial.print("WAZAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
       Serial.println ();
       Etat=Alum;
       demarage=1;
       demled=0;
       effect1=0;
       Moov=0;
       }}
        bcnact=1;
                                                Serial.print("Etein");
                                                
                                                
                                                
                                         Serial.println ();

         nbrcodeur=1;
         activeskin=0;
       
       break;
       
  case Alum: 


                                    if(bcnact==1){                       if (Kbouton(2,btnO,2)==1){      Serial.print("WAZAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
                                                Serial.println ();
                                                 Etat=Alum;
                                                 stat=inactif;
                                                 demarage=0;
                                                 xy=44;
                                                 extink=1;
                                                 bcnact=0;
                                                 }}

                                                 
            switch (demarage){
                              case 0: break;
                              case 1: delay(1000);
                                      player.play(1);

                                      demarage=2; break;
                              case 2: Serial.print("OK");
                                      Serial.println ();
                                      action=1;
                                      opensabr(strip.Color(0,  255,   0)     ,10);
                                      Setcouleur(color1sabr,0);
                                      if(tempo(875)==1){ 
                                         /*LED*/
                                        
                                        }
                                       if(action==0){demarage++;}
                                       break;
                                       
                               case 3: Serial.print("atente");
                                       Serial.println ();
                                       action=1;
                                       /*Nocolor*/
                                       if(tempo(625)==1){ 
                                         
                                        CLPR=0;
                                        CLPV=0;
                                        CLPB=0;}
                                       if(action==0){demarage++;delay(10);}                              
                                        
                                        break;
                                case 4: 
                                       Serial.print("lame");
                                       Serial.println ();
                                      
                                       opensabr(color1sabr,10);
                                       
                                        if (demarage==4){
                                            switch(demled){
                                                          case 0: action=1;if(tempo(xx)==1){/**/}
                                                                  if(action==0){demled++;}break;

                                                          case 1: action2=1;if(tempo2(8400)==1)   {Serial.print("OK");}   
                                                                  if(action2==0){Serial.print("FIN");demarage=0;stat=calm;calme=0;break;}
                                                          
                                                                 
                                                                                                 
                                                          
                                                          
                                                          }
                                                          } 
                                 }                        
                                        
                  
                                        
                  
                                 switch(stat){
                                               case calm: switch (calme){
                                                                          case 0:delay(111); player.loop(2); calme++; break;
                                                                          case 1:action=1;if(tempo(xx)==1){  /*LED*/}if(action==0){calme++;}break;
                                                                          case 2:action=1; if(tempo(xx)==1){ /*LED*/}if(action==0){calme++;}break;
                                                                          case 3:action=1;if(tempo(xx)==1){  
                                                                                                         Setcouleur(color1sabr,0);
                                                                                                            }
                                                                                if(action==0){calme++;}break;
                                                                          case 4: bcnact=1;
                                                                                         Serial.print("statik");
                                                                                       Serial.println ();
                                                                                  Gyro();
                                                                                  action2=1; if(tempo2(50)==1){  if(moov==1){stat=mov;Moov=0;} }if(action2==0){calme=1;}
                                                                                  calme=1;
                                                                                  
                                                                          break;    
                                                                                   }
                                                                          
                                                                          
                                               break;
                                          
                                               case mov: switch (Moov){
                                                                          case 0: delay(111);player.loop(3); Moov++; break;
                                                                          case 1:action=1;if(tempo(xx)==1){ /*LED*/}if(action==0){Moov++;}break;
                                                                          case 2:action=1; if(tempo(xx)==1){ /*LED*/}if(action==0){Moov++;}break;
                                                                          case 3:action=1;if(tempo(xx)==1){  
                                                                                                  Setcouleur(color1sabr,50);
                                                                                                            }
                                                                                if(action==0){Moov++;}break;
                                                                          case 4: bcnact=1;
                                                                                 Serial.print("Moov");
                                                                                Gyro();
                                                                                   
                                                                                action2=1; if(tempo2(2000)==1){  if(moov==0){stat=calm;calme=0;delay(2000);}  }if(action2==0){Moov=1;}
                                                                                Moov=1;
                                                                                   
                                                                           break;        
                                                                                   }
                                                break;                           
                                                                          }
                                                                                        
                                          
                                          
                                          
                                          
                                          
                                  
                                  

                                       
                  switch(extink){
                                 case 0: break;
                                 case 1: delay(5);player.play(5);extink++; break;
                                
                                       /*LED*/
                                                            
                                                         
                                 case 13: Serial.print("Extink");
                                          Serial.print(btnA());
                                          Serial.println();
                                                        if(btnA()==0){  Etat=Etein; extink=0;btnO=0;delay(2000);}
                                         
                                         delay(1);
                                         break;}   
                 //detection bouton


                 break;
                              
  
  
case Menu: Serial.print("Menu ");
      

          
           if(nbrcodeur==1){
                            menu0 = Selectcodeur(3);
                            Serial.print(menu0);
                            
           }
          
            switch(menu0){

                          case rett:Serial.print("  RettMenu");
                                  if(sonret1==0){player.play(6);}
                                         sonret1=1;
                                         sonskin=0;
                                         sonsensi=0;
                                         sonson=0;
                                         if(nbrbouton==1){if(menubtn()==1){Serial.print("  BTNOOOOOON");Etat=Etein;delay(1500);}}
                          break;
                          case skins:
                                       Serial.print("  Skin");
                                    if(sonskin==0){player.play(17);}
                                       sonskin=1;
                                       sonsensi=0;
                                       sonson=0;
                                       sonret1=0;
                               
                                         
                                         if(nbrbouton==1){ if(digitalRead(12)==0){Serial.print("  BTNOOOOOON");testm2=1;}}
                                         if (nbrbouton==1&&testm2==1){if(digitalRead(12)==1){activeskin=1;nbrbouton=2;nbrcodeur=2;skinNB=skinA;testm2=0;}}
                                         delayMicroseconds(100);
                                   if(activeskin==1){
                                                if(nbrcodeur==2){ Selectcodeur(3);skinNB = Valcodeur; }
                                                if(nbrcodeur==3){  Selectcodeur(2);menuskin = Valcodeur; Serial.print(menuskin);}
                                                if(nbrcodeur==4){ Selectcodeur(3);menucolor =  Valcodeur; Serial.print(menucolor);}
                                                
                                                if(nbrcodeur==5){ selecolor =  Selectcodeurplus(755,14);if(Nbactuel2<0){Nbactuel2=755;}if(Nbactuel2>755){Nbactuel2=0;} Serial.print(selecolor);}
                                               
                                               
                                      switch(skinNB){
                                         
                                                      case 0:if(sonmenu==0){player.play(16);}
                                                              sonmenu=1;
                                                              sonskinA=0;
                                                              sonskinB=0;
                                                              sonskinC=0;
                                                              
                                                             if(nbrbouton==2){  Serial.print("  Retour");if(menubtn()==1){Serial.print(" Retouraumenu");nbrbouton=1;nbrcodeur=1;menu0=rett;Etat=Menu;delay(1000);}}else{Serial.print("  Rien");}
                                                      break;
                                                      case skinA:Serial.print("  Skin1   ");
                                                              if (sonskinA==0){player.play(7);}
                                                              sonskinA=1;
                                                              sonskinB=0;
                                                              sonskinC=0;
                                                              sonmenu=0;
                                                              
                                                              if(nbrbouton==2){Setcouleur(color1skn1,0);}

                                                              
                                                              if(nbrbouton==2){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                              if (nbrbouton==2&&testm2==1){if(digitalRead(12)==1){activemenuskin=1;nbrbouton=3;nbrcodeur=3;menuskin=0;testm2=0;delayMicroseconds(100);}}
                                                             
                                                             if(activemenuskin==1){
                                                              switch(menuskin){
                                                                case 0:if(sonactive==0){player.play(19);}Serial.print("  Reglage   ");
                                                                       sonactive=1;
                                                                       sonret3=0;
                                                                       sonreglage=0;

                                                                       
                                                                   if(activereglageskin==1){switch(menucolor){
                                                                        case 0:
                                                                          Serial.print("  couleur1   ");
                                                                          if (sonscool1==0){player.play(10);}
                                                                              sonscool1=1;
                                                                              sonscool2=0;
                                                                              sonscool3=0;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(color1skn1,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=color1skn1;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        color1skn1=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 1:
                                                                          Serial.print("  couleur2   ");
                                                                            if (sonscool2==0){player.play(11);}
                                                                              sonscool1=0;
                                                                              sonscool2=1;
                                                                              sonscool3=0;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(color2skn1,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=color2skn1;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        color2skn1=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 2:
                                                                          Serial.print("  couleureffet   ");
                                                                        if  (sonscool3==0){player.play(12);}
                                                                              sonscool1=0;
                                                                              sonscool2=0;
                                                                              sonscool3=1;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(coloreskn1,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=coloreskn1;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        coloreskn1=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 3:
                                                                          Serial.print("  retour   ");
                                                                         if (sonscool4==0){player.play(16);}
                                                                              sonscool1=0;
                                                                              sonscool2=0;
                                                                              sonscool3=0;
                                                                              sonscool4=1;
                                                                             if(nbrbouton==4){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                                             if (nbrbouton==4&&testm2==1){if(digitalRead(12)==1){activereglageskin=0;nbrbouton=3;nbrcodeur=3;Valcodeur=1;sonactive=0;testm2=0;delayMicroseconds(100);}}
                                                                        break;
                                                                                    }}
                                                                       if(nbrbouton==3){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                                       if (nbrbouton==3&&testm2==1){if(digitalRead(12)==1){activereglageskin=1;testm2=0;nbrbouton=4;nbrcodeur=4;delayMicroseconds(100);}}
                                                                       break;
                                                                case 1:if(sonreglage==0){player.play(18);}Serial.print(" Activer   ");
                                                                       sonreglage=1;
                                                                       sonret3=0;
                                                                       sonactive=0;
                                                                       if(nbrbouton==3){if(menubtn()==1){
                                                                                                         
                                                                                                         Serial.print("  O=======K"); color1sabr=color1skn1; color2sabr=color2skn1; coloresabr=coloreskn1;
                                                                                                         nbrcodeur=1;nbrbouton=1;activemenuskin=0;
                                                                                                         Nbactuel=0;
                                                                                                         sonret1=0;player.play(20);delay(2100);menu0=rett;sonskinA=0;}}       
                                                                break;
                                                                case 2:if(sonret3==0){player.play(16);}Serial.print("  Retour   ");
                                                                       sonret3=1;
                                                                       sonreglage=0;
                                                                       sonactive=0;
                                                                       /*Nocolor*/
                                                                       if(nbrbouton==3){ if(menubtn()==1){Serial.print("  menuskinRetour");nbrcodeur=2;nbrbouton=2;activemenuskin=0;menuskin=0;delay(1000);/*Nocolor*/menuskin=1;Nbactuel=1;}}
                                                                       break;
                                                                                }
                                                                                      }
                             
                                                      break;




                                                      
                                                       case skinB:Serial.print("  Skin2   ");
                                                              if (sonskinB==0){player.play(8);}
                                                              sonskinB=1;
                                                              sonskinA=0;
                                                              sonskinC=0;
                                                              sonmenu=0;
                                                              if(nbrbouton==2){Setcouleur(color1skn2,0);}
                                                              if(nbrbouton==2){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                              if (nbrbouton==2&&testm2==1){if(digitalRead(12)==1){activemenuskin=1;nbrbouton=3;nbrcodeur=3;menuskin=0;testm2=0;delayMicroseconds(100);}}
                                                             
                                                             if(activemenuskin==1){
                                                              switch(menuskin){
                                                                case 0:if(sonactive==0){player.play(19);}Serial.print("  Reglage   ");
                                                                       sonactive=1;
                                                                       sonret3=0;
                                                                       sonreglage=0;

                                                                       
                                                 if(activereglageskin==1){switch(menucolor){
                                                                        case 0:
                                                                          Serial.print("  couleur1   ");
                                                                          if (sonscool1==0){player.play(10);}
                                                                              sonscool1=1;
                                                                              sonscool2=0;
                                                                              sonscool3=0;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(color1skn2,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=color1skn2;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        color1skn2=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 1:
                                                                          Serial.print("  couleur2   ");
                                                                            if (sonscool2==0){player.play(11);}
                                                                              sonscool1=0;
                                                                              sonscool2=1;
                                                                              sonscool3=0;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(color2skn2,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=color2skn2;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        color2skn2=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 2:
                                                                          Serial.print("  couleureffet   ");
                                                                        if  (sonscool3==0){player.play(12);}
                                                                              sonscool1=0;
                                                                              sonscool2=0;
                                                                              sonscool3=1;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(coloreskn2,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=coloreskn2;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        coloreskn2=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 3:
                                                                          Serial.print("  retour   ");
                                                                         if (sonscool4==0){player.play(16);}
                                                                              sonscool1=0;
                                                                              sonscool2=0;
                                                                              sonscool3=0;
                                                                              sonscool4=1;
                                                                              /*Nocolor*/
                                                                             if(nbrbouton==4){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                                             if (nbrbouton==4&&testm2==1){if(digitalRead(12)==1){activereglageskin=0;nbrbouton=3;nbrcodeur=3;Valcodeur=1;sonactive=0;testm2=0;delayMicroseconds(100);}}
                                                                        break;
                                                                                    }}
                                                                       if(nbrbouton==3){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                                       if (nbrbouton==3&&testm2==1){if(digitalRead(12)==1){activereglageskin=1;testm2=0;nbrbouton=4;nbrcodeur=4;delayMicroseconds(100);}}
                                                                       break;
                                                                case 1:if(sonreglage==0){player.play(18);}Serial.print(" Activer   ");
                                                                       sonreglage=1;
                                                                       sonret3=0;
                                                                       sonactive=0;
                                                                       if(nbrbouton==3){if(menubtn()==1){
                                                                                                         
                                                                                                         Serial.print("  O=======K"); color1sabr=color1skn2; color2sabr=color2skn2; coloresabr=coloreskn2;
                                                                                                         nbrcodeur=1;nbrbouton=1;activemenuskin=0;
                                                                                                         Nbactuel=0;
                                                                                                         sonret1=0;player.play(20);delay(2100);menu0=rett;sonskinA=0;}}       
                                                                break;
                                                                       break;
                                                                case 2:if(sonret3==0){player.play(16);}Serial.print("  Retour   ");
                                                                       sonret3=1;
                                                                       sonreglage=0;
                                                                       sonactive=0;
                                                                       if(nbrbouton==3){ if(digitalRead(12)==0){Serial.print("  menuskinON");nbrcodeur=2;nbrbouton=2;activemenuskin=0;menuskin=0;delay(1000);/*Nocolor*/menuskin=1;Nbactuel=1;}}
                                                                       break;
                                                                                }
                                                                                      }
                                                       break;




                                                       
                                                        case skinC:Serial.print("  Skin3  ");
                                                               if (sonskinC==0){player.play(9);}
                                                              sonskinC=1;
                                                              sonskinA=0;
                                                              sonskinB=0;
                                                              sonmenu=0;
                                                              if(nbrbouton==2){Setcouleur(color1skn3,0);}
                                                              if(nbrbouton==2){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                              if (nbrbouton==2&&testm2==1){if(digitalRead(12)==1){activemenuskin=1;nbrbouton=3;nbrcodeur=3;menuskin=0;testm2=0;delayMicroseconds(100);}}
                                                             
                                                             if(activemenuskin==1){
                                                              switch(menuskin){
                                                                case 0:if(sonactive==0){player.play(19);}Serial.print("  Reglage   ");
                                                                       sonactive=1;
                                                                       sonret3=0;
                                                                       sonreglage=0;

                                                                       
                                                 if(activereglageskin==1){switch(menucolor){
                                                                        case 0:
                                                                          Serial.print("  couleur1   ");
                                                                          if (sonscool1==0){player.play(10);}
                                                                              sonscool1=1;
                                                                              sonscool2=0;
                                                                              sonscool3=0;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(color1skn3,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=color1skn3;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        color1skn3=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 1:
                                                                          Serial.print("  couleur2   ");
                                                                            if (sonscool2==0){player.play(11);}
                                                                              sonscool1=0;
                                                                              sonscool2=1;
                                                                              sonscool3=0;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(color2skn3,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=color2skn3;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        color2skn3=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 2:
                                                                          Serial.print("  couleureffet   ");
                                                                        if  (sonscool3==0){player.play(12);}
                                                                              sonscool1=0;
                                                                              sonscool2=0;
                                                                              sonscool3=1;
                                                                              sonscool4=0;
                                                                              if(nbrbouton==4){Setcouleur(coloreskn3,0);}
                                                                              switch(okcouleur){
                                                                                                  case 0:
                                                                                                      if(nbrbouton==4){if(menubtn()==1){;okcouleur=1;nbrbouton=5;nbrcodeur=5;delay(500);}}
                                                                                                      
                                                                                                  break;
                                                                                                  case 1:
                                                                                                          
                                                                                                          if(unfcolor==0){Nbactuel2=coloreskn3;unfcolor=1;Serial.print("  OK unf   ");}
                                                                                                      Serial.print("  selection   ");
                                                                                                      Serial.print(Nbactuel2);
                                                                                                                                                                       
                                                                                                      Serial.print("  R   ");
                                                                                                      Serial.print(CLPR);
                                                                                                      Serial.print("  V   ");
                                                                                                      Serial.print(CLPV);
                                                                                                      Serial.print("  B   ");
                                                                                                      Serial.print(CLPB);
                                                                                                      Setcouleur(selecolor,0);
                                                                                                      if(nbrbouton==5){if(menubtn()==1){
                                                                                                                                        coloreskn3=selecolor;
                                                                                                                                        Serial.print("  ON");unfcolor=0;nbrbouton=4;nbrcodeur=4;okcouleur=0;menucolor=1;player.play(20);delay(2100);}}
                                                                                                      

                                                                                                   
                                                                                                  break;
                                                                                }
                                                                              
                                                                            
                                                                            
                                                                            
                                                                        break;
                                                                        case 3:
                                                                          Serial.print("  retour   ");
                                                                         if (sonscool4==0){player.play(16);}
                                                                              sonscool1=0;
                                                                              sonscool2=0;
                                                                              sonscool3=0;
                                                                              sonscool4=1;
                                                                              /*Nocolor*/
                                                                             if(nbrbouton==4){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                                             if (nbrbouton==4&&testm2==1){if(digitalRead(12)==1){activereglageskin=0;nbrbouton=3;nbrcodeur=3;Valcodeur=1;sonactive=0;testm2=0;delayMicroseconds(100);}}
                                                                        break;
                                                                                    }}
                                                                       if(nbrbouton==3){if(digitalRead(12)==0){Serial.print("  ON");testm2=1;}}
                                                                       if (nbrbouton==3&&testm2==1){if(digitalRead(12)==1){activereglageskin=1;testm2=0;nbrbouton=4;nbrcodeur=4;delayMicroseconds(100);}}
                                                                       break;
                                                                case 1:if(sonreglage==0){player.play(18);}Serial.print(" Activer   ");
                                                                       sonreglage=1;
                                                                       sonret3=0;
                                                                       sonactive=0;
                                                                       if(nbrbouton==3){if(menubtn()==1){
                                                                                                         
                                                                                                         Serial.print("  O=======K"); color1sabr=color1skn3; color2sabr=color2skn3; coloresabr=coloreskn3;
                                                                                                         nbrcodeur=1;nbrbouton=1;activemenuskin=0;
                                                                                                         Nbactuel=0;
                                                                                                         sonret1=0;player.play(20);delay(2100);menu0=rett;sonskinA=0;}}       
                                                                break;
                                                                       break;
                                                                case 2:if(sonret3==0){player.play(16);}Serial.print("  Retour   ");
                                                                       sonret3=1;
                                                                       sonreglage=0;
                                                                       sonactive=0;
                                                                       if(nbrbouton==3){ if(digitalRead(12)==0){Serial.print("  menuskinON");nbrcodeur=2;nbrbouton=2;activemenuskin=0;menuskin=0;delay(1000);/*Nocolor*/menuskin=1;Nbactuel=1;}}
                                                                       break;
                                                                                }
                                                                                      }
                                                        break;
                
                                                    }
                                                  }
                                      
                          break;

                          case audio:Serial.print(" Audio ");
                                     if(sonson==0){player.play(13);}
                                       sonson=1;
                                       sonskin=0;
                                       sonsensi=0;
                                       sonret1=0;

                                       
                                       if(nbrbouton==1){if(menubtn()==1){nbrbouton=2;nbrcodeur=2;player.play(15);Nbactuel=volume; delay(2300); player.loop(2);delay(10);}}
                                       if(nbrcodeur==2){ if (Selectcodeur(38)!=selecvolum){unfcolor=0;}  selecvolum =  Selectcodeur(38); if(Nbactuel>30&&Nbactuel<35){Nbactuel=30;}if(Nbactuel>35){Nbactuel=0;}
                                        
                                        if(selecvolum<4){ /*LED*/}
                                        if(selecvolum>4&&selecvolum<7){ /*LED*/}
                                        if(selecvolum>7&&selecvolum<10){ /*LED*/}
                                        if(selecvolum>10&&selecvolum<13){ /*LED*/}
                                        if(selecvolum>13&&selecvolum<17){ /*LED*/}
                                        if(selecvolum>17&&selecvolum<21){ /*LED*/}
                                        if(selecvolum>21&&selecvolum<24){ /*LED*/}
                                        if(selecvolum>24&&selecvolum<29){ /*LED*/}
                                        if(selecvolum==30){ /*LED*/}
                                        
                                        if(menubtn()==1){player.play(20);delay(2100);menu0=rett;nbrbouton=1;nbrcodeur=1;volume=selecvolum;player.pause();}
                                                      
                                        
                                           if(millis() - timer > 1000){
                                                                        player.volume(selecvolum);
                                                                         timer = millis();
                                                                        }
                                   
                                       
                                       Serial.print(selecvolum);
                                       
                                       }

                                       
                          break;

                          case sensi:
                                    if(sonsensi==0){player.play(14);}
                                       sonsensi=1;
                                       sonskin=0;
                                       sonret1=0;
                                       sonson=0;
                          break;       
                          }

                          
Serial.println();
break;
                                 
                                 
                                 
                                 
                                 }
   


                           

                               
                               }
  /*PRATIX
   if(millis() - timer > 1000){
    
    timer = millis();
    }*/
//G


   

       

/*//selection de couleur
Colorcod = Selectcodeur(100) * Calibre;
Setcouleur(Colorcod,10);  
Bandeled(1,1,1,0,0,0,0,0,0,0);

*/


  //Teste



  
  /*if(millis() - timer > 200){    
    mpu6050.update();
     Serial.print("  ");
     
   // Serial.print(CTemps);
   // Serial.print(" Seconde");
    Serial.print("  Valeur du codeur");
    Serial.print(rotVal);
    Serial.print("  Valeur Colorcod ");
    Serial.print(Colorcod);
    Serial.print("  Gyroscope Temp");
    Serial.print(mpu6050.getTemp());*//*
    Serial.print("  Acceleration X  ");
    Serial.print(mpu6050.getAccX());
    Serial.print("  Y  ");
    Serial.print(mpu6050.getAccY());
    Serial.print("  Z  ");
    Serial.print(mpu6050.getAccZ());
    Serial.print("  Pos X  ");
    Serial.print(mpu6050.getGyroX());
    Serial.print("  Y  ");
    Serial.print(mpu6050.getGyroY());
    Serial.print("  Z  ");
    Serial.print(mpu6050.getGyroZ());
    Serial.print("  ANGL X  ");
    Serial.print(mpu6050.getAngleX());
    Serial.print("  Y  ");
    Serial.print(mpu6050.getAngleY());
    Serial.print("  Z  ");
    Serial.print(mpu6050.getAngleZ());
    Serial.println ();
timer = millis();}*/

//Interuption

void lecturCodeur(void) {
  // Switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

    bouton = false;
    //lire les signal A et B
    boolean A_val = digitalRead(A1);
    boolean B_val = digitalRead(A2);

  static unsigned long dateDernierChangement3 = 0;
 
  unsigned long date3 = millis();
   
  if ((date3 - dateDernierChangement3) > dureeAntiRebond) {
    if (digitalRead(pinEncodeurB) == HIGH) {
      compte++;
    }
    else {
      compte--;
    }
    dateDernierChangement3 = date3;
  } ;  
  rotVal=compte;

}
