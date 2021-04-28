
unsigned char seq1;
unsigned long timertest;

 void Etat_Alum(boolean bouton){
                   Serial.print("Alum   ");
                   Serial.print(seq1);
                   Serial.print(" <=Seq  ");
 
  
                 switch(seq1){

                          ///////////Ouverture
                          case 0:
                                      delay(10);
                                      player.play(1);
                                      delay(20);
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
                          case 4: Serial.print("attente"); if(Crono(561)==0){seq1++;} break;
                                     
                          case 5:    
                                     Serial.print("lame");
                                     opensabr(0);
                                     if(Crono(100)==0){seq1++;}
                                     
                          break;
                          case 6:
                                   Serial.print("lameeffet increment");
                                   if(Crono(6000)==0){seq1++;}//2300
                                   if(timertest<millis()){timertest=millis();}//////////////////???????????????????????????????????????????????????
                                   else{Serial.print("  cronook");}
                                   effetdemarage(10000,coul2sabre,coul1sabre);
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
                               if (fermsabr()==0){Serial.print(" OK");seq1++;x=10;delay(500);}  
                               
                               if(Crono(2000)==1){if (btnT()==0){seq1=7;x=NOMBRE_LED;}}
                               //else{Serial.print(" OK");seq1++;delay(1000);}
                               
                               
                          break;
                          case 35:
                               strip.setBrightness(255);
                               
                               if(millis() - timer3 > 700){ 
                               strip.setPixelColor(x, strip.Color(0,  0,   0));
                               x--;
                               strip.show();
                               if (x<=1){seq1++;}
                               Serial.print(" X=  ");
                               Serial.print(x);
                               timer3=millis();} 
                               

                              
                          
                          break;
                          case 36:
                              delay(700);
                              Serial.print("Fermeture definitif");
                              nocolor();
                              Etat=Etein;
                              seq1=0;
                              x=NOMBRE_LED;
                              timerBA=1;
                              timerB=1;
                              delay(5000);
                          break;
                           }
if(seq1>3 && seq1<33){
       if(Kbouton(2,bouton,2000)==1){seq1=33;}
       
  }
  
  
  }
