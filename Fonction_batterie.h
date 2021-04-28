// Pour la lecture du niveu de batterie brancher le + de l element li ion avan le module eleveur de tension a BATLVL_PIN (ici A6) 
/*  analogread
 *   
 *  BAT  LVL ANALOG
 *  3V   0   614
 *  3,5V 20  717
 *  4V   10  819
 *  
 *  0-205 = lvl 0 - 10
 *   
 */

 int batlvl(){
               int LVL;

               LVL=map(analogRead(A6)-619,0,167,1,10);
               return LVL;
  
  }
