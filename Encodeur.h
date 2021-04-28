
 //Codeur
 
volatile unsigned int rotVal = 0;


   void lecturCodeur(void) {
    Serial.print("codeur moov");
  // Switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

    
    //lire les signal A et B
    boolean A_val = digitalRead(22);
    boolean B_val = digitalRead(23);

  static unsigned long dateDernierChangement = 0;
 
  
   
  if ((millis() - dateDernierChangement) > dureeAntiRebond) {
    if (digitalRead(pinEncodeurB) == HIGH) {
      rotVal++;
      rotVal=rotVal+incrementC;
    }
    else {
      rotVal--;
      rotVal=rotVal-incrementC;
    }
    dateDernierChangement = millis();
  } ;  


                              }

  int Selectcodeur(unsigned int de,unsigned int a,boolean modeinf){
  

  if (rotVal< de){   
    
                    if(modeinf==1){rotVal = a;}
                    else{rotVal = de;}
                }
  if (rotVal> a){
                    if(modeinf==1){rotVal = de;}
                    else{rotVal = a;}
                }
  
  return rotVal;
}
