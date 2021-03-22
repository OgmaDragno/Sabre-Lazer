

 // Librairie led

//Led adressable

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(NOMBRE_LED, LED_PIN, NEO_GRB);

//FONCTION ALUMAGE LAMME DU SABRE


unsigned char ledemm=5;
unsigned int pos=0;
unsigned int couleur=skntst;


void nocolor(){
  strip.setBrightness(LUMINOSITE);
  for(int i;i<NOMBRE_LED;i++){strip.setPixelColor(i, strip.Color(0,   0,   0) );}
  strip.show(); 
  
  }




  

void lum(unsigned char nbrLED,unsigned char force){
  Setcouleur(couleur,0);
  
  strip.setBrightness(force);
  
  for (int i=0;i<nbrLED;i++){
  strip.setPixelColor(i, strip.Color(R,  V,   B));
  strip.setPixelColor((NOMBRE_LED - (i+pos)), strip.Color(R,  V,   B));}
  
  strip.show(); 
  delay(1);
  
  }






  
void opensabr(int wait) {
     
   Setcouleur(couleur,0);
  for (int i=0;i<ledemm;i++){
    
    strip.setPixelColor(i+pos, strip.Color(R,  V,   B));
    strip.setPixelColor((NOMBRE_LED - (i+pos)), strip.Color(R,  V,   B));
    Serial.print(i);
    }
  pos=pos+ledemm ;
  delay(wait);
  if(pos>NOMBRE_LED){pos=0;}
  
 strip.show();  
  }
