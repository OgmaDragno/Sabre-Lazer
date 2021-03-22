
 //librairie Gyroscope

#include <MPU6050_tockn.h>
#include <Wire.h>
#include "PinChangeInterrupt.h"
MPU6050 mpu6050(Wire);


double anglx;
double angly;
double anglz;

double anglxC;
double anglyC;
double anglzC;

boolean rtrn;
boolean moov=0;
boolean moovN=0;




boolean gyrod=0;

#define dureeAntiRebond2  300

 void Gyro(){  
   if(millis() - timer > 500){
                       mpu6050.update();

              
                   if(anglx<(mpu6050.getAngleX()-Calibr)||anglx>(mpu6050.getAngleX()+Calibr)){moov=1 ;}
                    else{moov=0;}
                    if(anglz<(mpu6050.getAngleZ()-Calibr)||anglz>(mpu6050.getAngleZ()+Calibr)){moov=1 ;}
                    else{moov=0;}

                   anglx=mpu6050.getAngleX();
                   angly=mpu6050.getAngleY();
                   anglz=mpu6050.getAngleZ();

    timer = millis();}

             /*
                    
                  Serial.print(moov);
                  Serial.print("        X");
                  Serial.print(anglx);
                  Serial.print("        Z");
                  Serial.print(anglz);
                  Serial.println();
*/


                  
  
  
  

                  }
