//   if(millis() - timer > XXXX){timer = millis();} fais une fois tout les XXXXms
unsigned long timer;
unsigned long timer3;

//Gestion du temps
     //cronometre miliseconde V1
     /*
        boolean Oncrono;
        unsigned long Arfcrono;
        unsigned char Mcrono;
        
        int Crono(int temps){
                            
                            if (Oncrono==1){
                                            
                                            if (Arfcrono != millis()){ Mcrono++;}
                                            Arfcrono = millis();
                                            if (Mcrono>temps){Oncrono=0; return 0;}
                                            else{return 1;}
                                            }
                            else {Mcrono=0;return 0;}
                  
                            }*/
                            
unsigned char numcrono;
                                                  unsigned long derniertemps;  
                                                  unsigned long testtemps=0;  
           
 unsigned long time1;
 boolean timerB=1;
boolean Crono(int temp){
                    if (timerB==1){time1=millis();timerB=0;}
                    else{
                          if(millis()>time1+temp){
                           Serial.print("     Crono");
                           Serial.print(millis()-time1);
                           timerB=1;
                           return 0;
                          }
                          else{
                            Serial.print("     =>Crono compte<=  timerB =");Serial.print(timerB);Serial.print("  time1 ");Serial.print(time1+temp);Serial.print(" millis  ");Serial.print(millis());
                                return 1;}
                  
                    }
                          }
 unsigned long timeB=0;
 boolean timerBA=1;
boolean Crono1(int temp){
                    if (timerBA==1){timeB=millis();timerBA=0;}
                    else{
                          if(millis()>timeB+temp){
                           Serial.print("     Crono");
                           Serial.print(millis()-timeB);
                           timerBA=1;
                           return 0;
                          }
                          else{
                            //Serial.print("     =>Crono compte<=  timerB =");Serial.print(timerB);Serial.print("  time1 ");Serial.print(time1+temp);Serial.print(" millis  ");Serial.print(millis());
                                return 1;}
                  
                    }
                          }
       
        unsigned long timeC=0;
 boolean timerC=1;
boolean Crono2(int temp){
                    if (timerC==1){timeC=millis();timerC=0;}
                    else{
                          if(millis()>timeC+temp){
                           Serial.print("     Crono");
                           Serial.print(millis()-timeC);
                           timerC=1;
                           return 0;
                          }
                          else{
                            //Serial.print("     =>Crono compte<=  timerB =");Serial.print(timerB);Serial.print("  time1 ");Serial.print(time1+temp);Serial.print(" millis  ");Serial.print(millis());
                                return 1;}
                  
                    }
                          }
       
       
       
     /*  boolean Crono(unsigned int temps){       
                                                  
                            
                                            if (testtemps<=0){testtemps=temps;}
                                            
                                            if (derniertemps != millis()){ testtemps--;}
                                            derniertemps = millis();
                                            
                                            
                                            if (testtemps<=0) {testtemps=0; return 0;}
                                            else{return 1;}
                                            
                                            }*/
         volatile unsigned long derniertemps2;  
        volatile unsigned long testtemps2=0; 
  boolean Crono21(unsigned int temps){       
                                           
                            
                                            if (testtemps2<=0){testtemps2=temps;}
                                            
                                            if (derniertemps2 != millis()){ testtemps2--;}
                                            derniertemps2 = millis();
                                            
                                            
                                            if (testtemps2<=0) {testtemps2=0; return 0;}
                                            else{return 1;}
                                            
                                            }


//Gestin d interface

  boolean menuchange =0;
  unsigned char seqdrn;
  void Navigationmenu(unsigned char Switch ,unsigned char achanG){
                        
                                                                  if(achanG != Switch){ menuchange= 1;}
                                                                  else{menuchange=0;}
                                                                  
                        }
                            
