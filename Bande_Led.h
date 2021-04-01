

 // Librairie led

//Led adressable

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(NOMBRE_LED, LED_PIN, NEO_GRB);

//FONCTION ALUMAGE LAMME DU SABRE


unsigned char ledemm=5;
unsigned int pos=0;
unsigned int couleur=skntst;

unsigned long timer1;
unsigned long timer2;


void nocolor(){
  strip.setBrightness(LUMINOSITE);
  for(int i=0;i<NOMBRE_LED;i++){strip.setPixelColor(i, strip.Color(0,   0,   0) );}
  strip.show(); 
  
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
  if(pos>NOMBRE_LED){pos=0;}
  
 strip.show();  
 
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
    
    strip.setPixelColor(z+40+r, strip.Color(R,  V,   B));
    strip.setPixelColor(i+z+40+r,   strip.Color(R4,  V4,   B4));

    strip.setPixelColor(z+80+r, strip.Color(R,  V,   B));
    strip.setPixelColor(i+z+80+r,   strip.Color(R4,  V4,   B4));
                                  }
    if(z>NOMBRE_LED+80){z=0;}
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
  
  for (int i=0;i<NOMBRE_LED;i++){
  strip.setPixelColor(i, strip.Color(R,  V,   B));
  
  }
  strip.show();
  timer = millis();}
  
  }

int x=NOMBRE_LED;
int i;
int aten=1;

void fermsabr(int attend,unsigned char seq){
              
              for(i=0;i<NOMBRE_LED;i++){
                                        x=x-i;
                                        strip.setPixelColor(x, strip.Color(0,  0,   0));
                                        strip.show();
                                        
                                        if(i>0){
                                          if (btnT()==0){i=NOMBRE_LED;}
                                          delay(attend);
                                          }
                                        if(i>87){{i=NOMBRE_LED;}
                                          
                                          }
                                        x=NOMBRE_LED;
                                        if(millis() - timer1 > 50){attend=attend+3; timer1 = millis();}
                                        
                                        
                                        
                                        }
               
              }
  
  int numvol;
 void ledvolum(int couleur,int num){
  Setcouleur(couleur,0);
  
  for (int i=0;i<num;i++){
    strip.setPixelColor(i, strip.Color(R,  V,   B));
  
  }
  for (int i=num+1;i<NOMBRE_LED;i++){
    strip.setPixelColor(i, strip.Color(0,  0,   0));
    }
  strip.show();
  
  }

 
