//   if(millis() - timer > XXXX){timer = millis();} fais une fois tout les XXXXms
unsigned long timer;

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
           
       boolean Crono(unsigned int temps){       
                                           
                            
                                            if (testtemps<=0){testtemps=temps;}
                                            
                                            if (derniertemps != millis()){ testtemps--;}
                                            derniertemps = millis();
                                            
                                            
                                            if (testtemps<=0) {testtemps=0; return 0;}
                                            else{return 1;}
                                            
                                            }
                            
