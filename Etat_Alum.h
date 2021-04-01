
unsigned char seq1;

 void Etat_Alum(boolean bouton){
                   Serial.print("Alum   ");
 
  
                 switch(seq1){

                          ///////////Ouverture
                          case 0:
                                      delay(333);
                                      player.play(1);
                                      seq1++;
                                      
                          break;
                          case 1:
                                      lum(5,233);
                                      seq1++;
                          break;
                          case 2:Serial.print("OK"); if(Crono(1000)==0){seq1++;} break;
                          
                          case 3:
                                     nocolor();
                                     seq1++;
                          break;
                          case 4: Serial.print("attente"); if(Crono(650)==0){seq1++;} break;
                                     
                          case 5:    
                                     Serial.print("lame");
                                     opensabr(0);
                                     if(Crono(25)==0){seq1++;}
                                     
                          break;
                          case 6:
                                   Serial.print("lameeffet increment");
                                   if(Crono(100)==0){seq1++;}//2300
                                   effetwomble(coul1sabre,coul2sabre,0,5);
                                   //AFAIREEEEEEEEEEEEEEEEEEE
                          break;


                          ///////////statik
                          
                          case 7:delay(10);player.loop(2);delay(10); seq1++;
                          break;
                          case 8: 
                                   
                                   Serial.print("lame wimble   Statik    moov=");
                                   //AFAIRE LED EFFECT
                                   effetwomble(coul1sabre,coul2sabre,0,5);

                                   Gyro();
                                   
                                   Serial.print(moov);
                                   if(moov==1){seq1++;}
                          break;

                          ///////////Mouvement
                          
                          case 9:
                                 player.play(3);seq1++;
                          break;
                          case 10:
                                 Serial.print("lame Mov");
                                   //AFAIRE LED EFFECT

                                 Gyro();
                                 if(moov==0){seq1=7;delay(3000);}
                          break;


                         ///////////Fermeture
                          
                          case 33:delay(10);player.play(5);delay(10);
                          seq1++;
                                 
                                   //AFAIRE LED EFFECT

                               
                          break;

                          case 34:
                               Serial.print("Rengainer");
                               fermsabr(aten,seq1);
                               if (btnT()==0){seq1=7;}
                               else{seq1++;aten=1;Serial.print(" OK");delay(1000);}
                               
                               
                          break;
                          case 35:
                              Serial.print("Fermeture definitif");
                              nocolor();
                              Etat=Etein;
                              seq1=0;
                              delay(1000);
                          break;
                           }
if(seq1>3 && seq1<33){
       if(Kbouton(2,bouton,200)==1){seq1=33;}
       
  }
  
  
  }
