  unsigned char R;
  unsigned char V;
  unsigned char B;

  unsigned char R4;
  unsigned char V4;
  unsigned char B4;

  unsigned char R5;
  unsigned char V5;
  unsigned char B5;
  
  unsigned char Cal1;
  unsigned char Cal2;

    void Setcouleur( unsigned int Codecouleure, unsigned char Sat){
    if(Codecouleure <= 255){
                R = 255 - Codecouleure;
                V = Codecouleure;
                B = Sat;
                }
                
    if(Codecouleure > 255 && Codecouleure <= 500){
                Cal1 = Codecouleure - 255;
                V = 255 - Cal1;
                B = Cal1;
                R = Sat; 
                }
    if(Codecouleure > 500){
                Cal2 = Codecouleure - 500;
                B = 255 - Cal2;
                R = Cal2;
                V = Sat; 
                }

  }

  unsigned int skntst=100;

   //_______________________________________SKIN___________________________________
  //epprom 0
  unsigned char skinnbr;
 
  unsigned int coul1sabre;
  unsigned int coul2sabre;
  unsigned int coulesabre;
  unsigned int luminosite;
  boolean modeecono;
//eprom 1-4
  unsigned int skn1c1=111;
    unsigned int skn1c2=333;
      unsigned int skn1ce=444;
        unsigned int skn1lum;
//eprom 5-8    
  unsigned int skn2c1=444;
    unsigned int skn2c2=555;
      unsigned int skn2ce=666;
        unsigned int skn2lum;        
//eprom 9-12
  unsigned int skn3c1=765;
    unsigned int skn3c2=555;
      unsigned int skn3ce=333;
        unsigned int skn3lum;
////eprom 9-12
  unsigned int skn4c1;
    unsigned int skn4c2;
      unsigned int skn4ce;
        unsigned int skn4lum;
      
