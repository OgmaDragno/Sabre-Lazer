

 // Librairie led

//Led adressable

#include <Adafruit_NeoPixel.h>

#define LED_MANCH 6



Adafruit_NeoPixel strip(NOMBRE_LED, LED_PIN, NEO_GRB);
Adafruit_NeoPixel stripbatt(LED_MANCH, LEDBATT_PIN, NEO_GRB);
unsigned int LED_LAM = NOMBRE_LED-LED_MANCH;


//FONCTION ALUMAGE LAMME DU SABRE


unsigned char ledemm=5;
unsigned int pos=0;
unsigned int couleur=skntst;

unsigned long timer1;
unsigned long timer2;

//etein tout les led du bandeau
void nocolor(){
  strip.setBrightness(LUMINOSITE);
  for(int i=0;i<LED_LAM;i++){strip.setPixelColor(i, strip.Color(0,   0,   0) );}
  strip.show(); 
  
  }

//fonction alumage led menu
void ledmenu(byte led,int couleur){
                        
                        stripbatt.setPixelColor(led, stripbatt.Color(R,   255,   B) );
                        stripbatt.show(); 
  }
void noledmenu(byte led){
                        
                        stripbatt.setPixelColor(led, stripbatt.Color(0,   0,   0) );
                        stripbatt.show(); 
  }
//Jauge battrie le niveau ce situe entre 0 et 10
unsigned long timetbat;
unsigned int effetbat=0;
boolean efetmanch=0;
void jaugebatterie(int pourcentbat,int couleur,int couleur2){
                           int numledall;
                           int Rs;
                           int Vs;
                           int Bs;
                           int Rs1;
                           int Vs1;
                           int Bs1;
                           Setcouleur(coulesabre,0);
                           R5=R;
                           V5=V;
                           B5=B;
                           Setcouleur(couleur2,0);
                           Rs=R;
                           Vs=V;
                           Bs=B;
                           Setcouleur(couleur,0);
                           
                           numledall = map(pourcentbat,1,10,0,LED_MANCH);
                        //0 = Jauge battrie
                        if(efetmanch==0){
                         
                         //alumer led
                         if(pourcentbat<=3){
                               for(int i=0;i<=numledall;i++){ stripbatt.setPixelColor(i, stripbatt.Color(255,   0,   0) );}
                          }
                         if(pourcentbat>3 && pourcentbat<=8){
                               
                               for(int i=0;i<=numledall;i++){ stripbatt.setPixelColor(i, stripbatt.Color(R,   V,   B) );}
                               stripbatt.show();
                               
                               
                               stripbatt.setPixelColor(effetbat-1, stripbatt.Color(Rs,   Vs,   Bs) );
                               stripbatt.setPixelColor(effetbat-2, stripbatt.Color(Rs1,   Vs1,   Bs1) );
                               
                               stripbatt.setBrightness(LUMINOSITEBAT+5);
                               stripbatt.setPixelColor(effetbat, stripbatt.Color(R5,   V5,   B5) );
                               if(millis() - timetbat> 99){  effetbat++; 
                                                              if(effetbat>numledall){effetbat=0;} 
                                                              timetbat = millis();}
                          }
                         if(pourcentbat>8 && pourcentbat<11){
                               ;
                               for(int i=0;i<=numledall;i++){ stripbatt.setPixelColor(i, stripbatt.Color(R5,   V5,   B5) );}
                               stripbatt.show(); 
                               stripbatt.setBrightness(LUMINOSITEBAT+15);
                               stripbatt.setPixelColor(effetbat, stripbatt.Color(R,   V,   B) );
                               stripbatt.setPixelColor(effetbat-1, stripbatt.Color(Rs,   Vs,   Bs) );
                               stripbatt.setPixelColor(effetbat-2, stripbatt.Color(Rs,   Vs,   Bs) );
                               if(millis() - timetbat> 144){  effetbat++; 
                                                              if(effetbat>numledall){effetbat=0;} 
                                                              timetbat = millis();}
                          }
                          if(pourcentbat>11){
                              for(int i=0;i<=numledall;i++){ stripbatt.setPixelColor(i, stripbatt.Color(0,   155,   0) );}
                               stripbatt.show(); 
                               stripbatt.setBrightness(LUMINOSITEBAT+15);
                               stripbatt.setPixelColor(effetbat, stripbatt.Color(0,   255,   0) );
                               stripbatt.setPixelColor(effetbat+1, stripbatt.Color(0,   200,   0) );
                               stripbatt.setPixelColor(effetbat+2, stripbatt.Color(0,   150,   0) );
                               if(millis() - timetbat> 144){  effetbat--; 
                                                              if(effetbat<0){effetbat=numledall;} 
                                                              timetbat = millis();}
                            
                            
                            }
                        stripbatt.show(); 
                        }
                        //-----------

                        //menu
  
  
  }
  void manchemenu(unsigned char num){
                                      int couleur;
                                      couleur = map(num,1,4,144,765);
                                      Setcouleur(couleur,0);

                                      for(int i=0;i<=LED_MANCH;i++){ stripbatt.setPixelColor(i, stripbatt.Color(R,   V,   B) );}
                                      if(num>0){for(int i=0;i<=num-1;i++){ stripbatt.setPixelColor(i, stripbatt.Color(255,   255,   255) );}}
                                      
                                      
                                      stripbatt.show(); 
    
    
    
    }

void lum(unsigned char nbrLED,unsigned char force){
  Setcouleur(couleur,0);
  
  strip.setBrightness(force);
  
  for (int i=0;i<nbrLED;i++){
  strip.setPixelColor(i, strip.Color(R,  V,   B));
  }
  
  strip.show(); 
  delay(1);
  
  }






  
void opensabr(int wait) {
     
   Setcouleur(coul1sabre,0);
  for (int i=0;i<ledemm;i++){
    
    strip.setPixelColor(i+pos, strip.Color(R,  V,   B));
    
    Serial.print(i);
    }
  pos=pos+ledemm ;
  delay(wait);
  if(pos>LED_LAM){pos=0;}
  
 strip.show();  
 
  }
unsigned long timespe;
int ledled;
int ledledincr=1;
void effetdemarage(int temps ,int couleur,int couleur2){
                                    Setcouleur(couleur2,0);
                                     R4=R;
                                     V4=V;
                                     B4=B;
                                     Setcouleur(couleur,0);
                                 for(int i=ledled;i<ledled+ledledincr;i++){
                                  strip.setPixelColor(i, strip.Color(R, V  , B  ));
                                 }
                                 for(int i=ledled;i>ledled-ledledincr;i--){
                                  strip.setPixelColor(i, strip.Color(R4, V4  , B4  ));
                                 }
                                 ledled=ledled+ledledincr;
                                 if(ledled>NOMBRE_LED+4){ledled=0;}
                                 strip.show();
                                 
                                 if(millis()-timespe>temps/13){
                                                          ledledincr++;
                                                          if (ledledincr>15){ledledincr=13;}
                                                          timespe=millis();}
  
  
  }

  
int z=0;
unsigned char r;
unsigned char lumi=20;
boolean lumeffect=0;

int izi;

void effetwomble(int couleur,int couleur2, int wait,int nombrefee) {
   Setcouleur(couleur2,0);
   R4=R;
   V4=V;
   B4=B;
   Setcouleur(couleur,0);
   r=random(0,5);
   for (int i=0;i<nombrefee;i++){ 
    
    strip.setPixelColor(z-40+r, strip.Color(R,  V,   B));
    strip.setPixelColor(i+z-40+r,   strip.Color(R4,  V4,   B4));

    strip.setPixelColor(z-80+r, strip.Color(R,  V,   B));
    strip.setPixelColor(i+z-80+r,   strip.Color(R4,  V4,   B4));

    strip.setPixelColor(z-120+r, strip.Color(R,  V,   B));
    strip.setPixelColor(i+z-120+r,   strip.Color(R4,  V4,   B4));

    strip.setPixelColor(z-160+r, strip.Color(R,  V,   B));
    strip.setPixelColor(i+z-160+r,   strip.Color(R4,  V4,   B4));
    
    strip.setPixelColor(z+r, strip.Color(R,  V,   B));
    strip.setPixelColor(i+z+r,   strip.Color(R4,  V4,   B4));
    

                                  }
    if(z>LED_LAM-r){z=0;}
    z=z+1;
   
    strip.show();
    
    
  if(millis() - timer2 > random(10,100)){
             lumeffect=!lumeffect;
  timer2 = millis();}

  if(lumeffect==1){
                     strip.setBrightness(10);
    }
  else{strip.setBrightness(LUMINOSITE);
  }
  



  
}

 void toutledal(int couleur){
  Setcouleur(couleur,0);

  if(millis() - timer > 300){ 
  
  for (int i=0;i<LED_LAM;i++){
  strip.setPixelColor(i, strip.Color(R,  V,   B));
  
  }
  strip.show();
  timer = millis();}
  
  }

int x=LED_LAM;



boolean fermsabr(){
              
                        
                        strip.setPixelColor(x, strip.Color(0,  0,   0));
                        strip.show();
                        x--;
                        Serial.print("Test = ");
                        Serial.print(x);
                        if (x<=5){x=LED_LAM;return 0;}
                        return 1;
                
                
             /* for(i=0;i<LED_LAM;i++){
                                        x=x-i;
                                        strip.setPixelColor(x, strip.Color(0,  0,   0));
                                        strip.show();
                                        if(i>0){
                                          delay(attend);
                                          }
                                        
                                        x=LED_LAM;
                                        if(millis() - timer > 50){attend=attend+3; timer = millis();}
                                        
                                        
                                        
                                        }*/
              }
  
  int numvol;
 void ledvolum(int couleur,int num){
  Setcouleur(couleur,0);
  
  for (int i=0;i<num;i++){
    strip.setPixelColor(i, strip.Color(R,  V,   B));
  
  }
  for (int i=num+1;i<LED_LAM;i++){
    strip.setPixelColor(i, strip.Color(0,  0,   0));
    }
  strip.show();
  
  }

 
