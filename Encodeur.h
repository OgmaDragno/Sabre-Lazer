
 //Codeur
 
volatile unsigned int rotVal = 0;


   void lecturCodeur(void) {
  // Switch Led state
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

    
    //lire les signal A et B
    boolean A_val = digitalRead(A1);
    boolean B_val = digitalRead(A2);

  static unsigned long dateDernierChangement = 0;
 
  
   
  if ((millis() - dateDernierChangement) > dureeAntiRebond) {
    if (digitalRead(pinEncodeurB) == HIGH) {
      rotVal++;
    }
    else {
      rotVal--;
    }
    dateDernierChangement = millis();
  } ;  


                              }

  int Selectcodeur(int nbselect){


  if (rotVal< 0){rotVal = nbselect;}
  if (rotVal> nbselect){rotVal =  0;}
  
  return rotVal;
}
