  unsigned char R;
  unsigned char V;
  unsigned char B;
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
