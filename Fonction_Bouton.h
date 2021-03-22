

       
       volatile boolean btnC(){return !digitalRead(btn1pin);}
       volatile boolean btnT(){
                                if(analogRead(btn2pin)>500){return 1;}
                                else{return 0;}
                              }
       

       
    boolean Kbouton(int Option,int Bouton,int Optionmode){

      switch(Option){

 //clic
       case 1 :
  
         if (Bouton == 1) {
         return 1;}
         else{return 0;}      
           
            
        break;

 //Maintien
         case 2 :

         if (Bouton==1){
         Serial.print("Le bouton est presser");
         if (Crono(Optionmode)== 1){Serial.print("  mais inactif");Serial.println ();return 0;}
         else{Serial.print("  Actif");return 1;}
         Serial.println ();
                           }
         else{return 0;}
         break;



          // On/off
         case 3 :

                                                               /*    if (Bouton == 1) {InternOK = !InternOK;Serial.print("Le bouton est presser");} 
                                                                    if (InternOK == 1) {Serial.print(" Actif");return 1;}
                                                                    else{Serial.print(" Inactif");return 0;}
                                                                    Serial.println ();*/

                                                                    break;
                                                        
                          }
                                                   }





  
