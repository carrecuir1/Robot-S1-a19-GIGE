#include <Arduino.h>
#include <../lib/LibRobUS/src/LibRobus.h>
float speed_G;
float speed_D;
#define Ki 0
#define Kp 0
#define Kd 0
#define Periode 200 
float pid(int consigne,int feedback); // consigne = v mit, feedback = v réel
float iPresent = 0;  // pas touche

void setup() {
  BoardInit();
  speed_G = 0.5;
  speed_D = 0.5;
  
}

void loop() {






  //Pulse par ms
  /*if(ROBUS_IsBumper(3)){
    MOTOR_SetSpeed(1, 1);
    MOTOR_SetSpeed(0, 1);
  
    delay(1000);
    for(int i = 0; i < 50; i++){
      delay(100);
      Serial.println(ENCODER_Read(0));
      //Serial.println(",")
    }
    Serial.print("*************************************************************");
    for(int i = 0; i < 50; i++){
      delay(100);
      Serial.println(ENCODER_Read(1));
    }
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
    
  }*/
  
  int encoder_G, encoder_D;
  if(ROBUS_IsBumper(3)){
    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0)){
        encoder_G = ENCODER_ReadReset(0);
        encoder_D = ENCODER_ReadReset(1);
        MOTOR_SetSpeed(1, speed_G);
        MOTOR_SetSpeed(0, speed_D);
        speed_G = speed_G + 0.00015*(encoder_D - encoder_G);
        delay(100);
      }

  }
  MOTOR_SetSpeed(1, 0);
  MOTOR_SetSpeed(0, 0);
}


float pid(int consigne,int feedbackPresent, int feedbackPasse)
{

  float iPasse; 
  int erreur = consigne - feedbackPresent;
  float p = Kp * erreur ;
  iPasse = iPresent; 
  float iPresent = Ki * (( erreur * Periode ) + iPasse);
  float d = Kd * (( feedbackPresent - feedbackPasse)/Periode);
  float commande = p +iPresent - d ;

  return commande;  
}
