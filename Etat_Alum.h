 int ok=333;
unsigned char seq=0;

 void Etat_Alum(boolean bouton){
                   Serial.print("Alum   ");
  
  
                 switch(seq){

                          ///////////Ouverture
                          case 0:
                                      delay(333);
                                      player.play(1);
                                      seq++;
                                      delay(10);
                          break;
                          case 1:
                                      lum(5,233);
                                     seq++;
                          break;
                          case 2:Serial.print("OK"); if(Crono(600)==0){seq++;} break;
                          
                          case 3:
                                     nocolor();
                                     seq++;
                          break;
                          case 4: Serial.print("attente"); if(Crono(625)==0){seq++;} break;
                                     
                          case 5:    
                                     Serial.print("lame");
                                     opensabr(0);
                                     if(Crono(25)==0){seq++;}
                                     
                          break;
                          case 6:
                                   Serial.print("lameeffet increment");
                                   if(Crono(1000)==0){seq++;}

                                   //AFAIREEEEEEEEEEEEEEEEEEE
                          break;


                          ///////////statik
                          
                          case 7:player.loop(2); seq++;
                          break;
                          case 8: 
                                   
                                   Serial.print("lame wimble   Statik    moov=");
                                   //AFAIRE LED EFFECT

                                   Gyro();
                                   
                                   Serial.print(moov);
                                   if(moov==1){seq++;}
                          break;

                          ///////////Mouvement
                          
                          case 9:
                                 player.play(3);seq++;
                          break;
                          case 10:
                                 Serial.print("lame Mov");
                                   //AFAIRE LED EFFECT

                                 Gyro();
                                 if(moov==0){seq=7;delay(3000);}
                          break;


                         ///////////Fermeture
                          
                          case 33:player.play(5);
                          seq++;
                                 
                                   //AFAIRE LED EFFECT

                               
                          break;

                          case 34:
                               Serial.print("Fermeture lamm");
                               if (bouton==0){seq=7;}
                               if(Crono(4000)==0){seq++;}
                          break;
                          case 35:
                              Serial.print("Fermeture definitif");
                          break;
                           }
if(seq>6 && seq<33){
       if(Kbouton(2,bouton,1500)==1){seq=33;}
       
  }
  
  
  }
