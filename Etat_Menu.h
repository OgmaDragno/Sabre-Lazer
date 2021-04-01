 int ok=333;



enum {menu=0,skinselect=60,skinconf=90,skinregl=120,volum=150,sensi=180,sensiconf=210,sensiregl=240}seq=menu;
boolean menus=0;
unsigned char weriscolor;




  
  void Etat_Menu(){

                        

                   Serial.print(" Menu ");
                   Serial.print(rotVal);
                   Serial.print(" ");
                   

                   
                                /*__Menu Lvl_1__*/ if(seq>=menu && seq<=3){                         seq = Selectcodeur(menu,3,1);Serial.print(" Lvl1 "); }
                                
                                /*_______SkinSelect Lvl_2__*/ if(seq>=skinselect && seq<=63){       seq = Selectcodeur(skinselect,63,1);    Serial.print(" Lvl2 ");          }
                                /*____________Avctive Lvl_3__*/ if(seq>=skinconf && seq<=92){       seq = Selectcodeur(skinconf,92,1);     Serial.print(" Lvl3 ");            }
                                /*________________Reglage Lvl_4__*/ if(seq>=skinregl && seq<=123){  seq = Selectcodeur(skinregl,123,1);         Serial.print(" Lvl4 ");        }
                                /*___________________Couleur Lvl_5__*/ if(seq==124){Serial.print(" Lvlspe "); }
                                
                                /*_______Volume Lvl_2__*/ if(seq>=volum && seq<=150){               seq = Selectcodeur(volum,150,1);  Serial.print(" Lvl2 ");     }
                                /*__________Regler volume Lvl_3__*/ if(seq==151)   {Serial.print(" Lvlspe "); }
                                
                                /*_______Sensi  Lvl_2__*/ if(seq>=sensi && seq<=180){               seq = Selectcodeur(sensi,180,1); Serial.print(" Lvl2 ");    }
                                /*____________Sesi Select Lvl_3__*/ // inactif if(seq>=sensiconf && seq<=3){}
                                /*________________Sensi Reglage Lvl_4__*/ // inactif if(seq>=sensiregl && seq<=3){}

                   switch(seq){
                                //________________MENU Genera lvl1
                                case menu: Serial.print("Quiter ");if(menus==0){player.play(6);menus=1;}else{sonmenu(16);}    if(Kbouton(1,btnC(),0)==1){menus=0;Etat=Etein;} break;
                                case 1: Serial.print("Skin ");sonmenu(17);        if(Kbouton(1,btnC(),0)==1){ seq=skinselect; rotVal=skinselect;} break;
                                case 2: Serial.print("Volume ");sonmenu(13);                 if(Kbouton(1,btnC(),0)==1){ seq=volum; rotVal=volum;} break;
                                case 3: Serial.print("Sensibilité ");sonmenu(14);             if(Kbouton(1,btnC(),0)==1){ seq=sensi; rotVal=sensi;} break;

                                //________________Skin
                                case skinselect/*60*/: Serial.print("Skin 1 ");sonmenu(7);  if(Kbouton(1,btnC(),0)==1){ seq=skinconf; rotVal=skinconf;skinnbr=1;} 
                                toutledal(skn1c1);
                                break;
                                case 61: Serial.print("Skin 2 ");sonmenu(8);                if(Kbouton(1,btnC(),0)==1){ seq=skinconf; rotVal=skinconf;skinnbr=2;} 
                                toutledal(skn2c1);
                                break;
                                case 62: Serial.print("Skin 3 ");sonmenu(9);                if(Kbouton(1,btnC(),0)==1){ seq=skinconf; rotVal=skinconf;skinnbr=3;} 
                                toutledal(skn3c1);
                                break;
                                case 63: Serial.print("Retour ");sonmenu(16);               if(Kbouton(1,btnC(),0)==1){ seq=menu; rotVal=menu;} 
                                nocolor();
                                break;

                                //______________________sousmenuskin
                                case skinconf/*90*/: Serial.print("Activer Skin ");sonmenu(18); 
                                
                                if(Kbouton(1,btnC(),0)==1){ 
                                                            EEPROM.put(0,skinnbr);
                                                            player.play(20);
                                                            if(skinnbr==1){coul1sabre=skn1c1;
                                                                           coul2sabre=skn1c2;
                                                                           coulesabre=skn1ce;}
                                                            if(skinnbr==2){coul1sabre=skn2c1;
                                                                           coul2sabre=skn2c2;
                                                                           coulesabre=skn2ce;}
                                                            if(skinnbr==3){coul1sabre=skn3c1;
                                                                           coul2sabre=skn3c2;
                                                                           coulesabre=skn3ce;}
                                                            delay(2000);
                                                            seq=menu; rotVal=menu;
                                  }
                                
                                break;
                                case 91: Serial.print("Reglage ");sonmenu(19);                   if(Kbouton(1,btnC(),0)==1){ seq=skinregl; rotVal=skinregl;} break;
                                case 92: Serial.print("Retour ");sonmenu(16);                    if(Kbouton(1,btnC(),0)==1){ seq=skinselect; rotVal=skinselect;} break;

                                //__________________________________sousmenuskin reglage couleur
                                case skinregl/*120*/: Serial.print("Couleur 1 ");sonmenu(10); 
                                
                                                      if(skinnbr==1){toutledal(skn1c1);}
                                                      if(skinnbr==2){toutledal(skn2c1);}
                                                      if(skinnbr==3){toutledal(skn3c1);}
                                                      
                                                      if(Kbouton(1,btnC(),0)==1){ seq=124; 
                                                                                  weriscolor=1;
                                                                                  if(skinnbr==1){rotVal=skn1c1;}
                                                                                  if(skinnbr==2){rotVal=skn2c1;}
                                                                                  if(skinnbr==3){rotVal=skn3c1;}
                                                                                }
                                
                                break;
                                case 121: Serial.print("Couleur 2 ");sonmenu(11); 
                                
                                                      if(skinnbr==1){toutledal(skn1c2);}
                                                      if(skinnbr==2){toutledal(skn2c2);}
                                                      if(skinnbr==3){toutledal(skn3c2);}
                                                      
                                                      if(Kbouton(1,btnC(),0)==1){ seq=124; 
                                                                                  weriscolor=2;
                                                                                  if(skinnbr==1){rotVal=skn1c2;}
                                                                                  if(skinnbr==2){rotVal=skn2c2;}
                                                                                  if(skinnbr==3){rotVal=skn3c2;}
                                                                                }
                                break;
                                case 122: Serial.print("Couleur effets ");sonmenu(12); 
                                                      if(skinnbr==1){toutledal(skn1ce);}
                                                      if(skinnbr==2){toutledal(skn2ce);}
                                                      if(skinnbr==3){toutledal(skn3ce);}

                                                      if(Kbouton(1,btnC(),0)==1){ seq=124; 
                                                                                  weriscolor=3;
                                                                                  if(skinnbr==1){rotVal=skn1ce;}
                                                                                  if(skinnbr==2){rotVal=skn2ce;}
                                                                                  if(skinnbr==3){rotVal=skn3ce;}
                                                                                }
                                break;
                                case 123: Serial.print("Retour ");sonmenu(16);               if(Kbouton(1,btnC(),0)==1){ seq=skinconf; rotVal=skinconf;} break;
                                                                                 
                                case 124:Serial.print("REglage color   ");  incrementC=7;
                                                                            Serial.print(Selectcodeur(1,765,1));
                                                                            toutledal(Selectcodeur(1,765,1));
                                
                                
                                                                               if(weriscolor==1){ if(Kbouton(1,btnC(),0)==1){
                                                                                                                              player.play(20);
                                                                                                                              if(skinnbr==1){skn1c1=rotVal;delay(5);EEPROM.put(1, skn1c1);}
                                                                                                                              if(skinnbr==2){skn2c1=rotVal;delay(5);EEPROM.put(9, skn2c1);}
                                                                                                                              if(skinnbr==3){skn3c1=rotVal;delay(5);EEPROM.put(17,skn3c1);}
                                                                                                                              delay(2000);
                                                                                                                              seq=121;rotVal=121;
                                                                                                                              Serial.print("  Couleur_1 OK   ");
                                                                                                                              incrementC=0;
                                                                                                                              menus=0;weriscolor=0;
                                                                                                                              
                                                                                                                              }}
                                                                               if(weriscolor==2){ if(Kbouton(1,btnC(),0)==1){
                                                                                                                              player.play(20);
                                                                                                                              if(skinnbr==1){skn1c2=rotVal;delay(5);EEPROM.put(3,skn1c2);}
                                                                                                                              if(skinnbr==2){skn2c2=rotVal;delay(5);EEPROM.put(11,skn2c2);}
                                                                                                                              if(skinnbr==3){skn3c2=rotVal;delay(5);EEPROM.put(19,skn3c2);}
                                                                                                                              delay(2000);
                                                                                                                              seq=122;rotVal=122;
                                                                                                                              Serial.print("  Couleur_2 OK   ");
                                                                                                                              incrementC=0;
                                                                                                                              menus=0;weriscolor=0;
                                                                                                                              }}
                                                                               if(weriscolor==3){ if(Kbouton(1,btnC(),0)==1){
                                                                                                                              player.play(20);
                                                                                                                              if(skinnbr==1){skn1ce=rotVal;delay(5);EEPROM.put(5,skn1ce);}
                                                                                                                              if(skinnbr==2){skn2ce=rotVal;delay(5);EEPROM.put(13,skn2ce);}
                                                                                                                              if(skinnbr==3){skn3ce=rotVal;delay(5);EEPROM.put(21,skn3ce);}
                                                                                                                              
                                                                                                                             delay(2000);
                                                                                                                              seq=123;rotVal=123;
                                                                                                                              Serial.print("  Couleur_3 OK   ");
                                                                                                                              incrementC=0;
                                                                                                                              menus=0;weriscolor=0;
                                                                                                                              }}                  
                                break;
                                //________________Menu volume
                                case volum/*150*/: Serial.print("Regler le volume "); sonmenu(15);delay(2200);seq=151; player.loop(2); rotVal=volume;incrementC=1; break;
                                case 151:
                                       Serial.print("Reglage le volume ");
                                       if(millis() - timer > 500){ 
                                       volume=Selectcodeur(1,30,0);
                                       player.volume(volume); 
                                       numvol=map(volume,1,30,0,NOMBRE_LED);
                                       ledvolum(coul1sabre,numvol);
                                        timer = millis();}
                                       
                                       if(Kbouton(1,btnC(),0)==1){player.play(20);seq=menu;rotVal=menu;menus=0;delay(2000);nocolor();}
                                       Serial.print(volume);
                                       Serial.print("  Numvol  = ");
                                       Serial.print(numvol);
                                       
                                break;
                                //________________Menu Sensibilité
                                case sensi/*180*/: Serial.print("Sensibilité ");sonmenu(14);break;
                                

                                //______________________sousmenusensibilite
                                // inactif case sensiconf/*210*/: Serial.print("Regler le volume "); break;

                                //__________________________________sousmenureglage divers
                                // inactif case sensiregl/*240*/: Serial.print("Regler le volume "); break;
                    
                    
                                }

                    Navigationmenu(seq,seqdrn);
                    seqdrn=seq;
                    }
