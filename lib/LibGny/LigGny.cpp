#include <Arduino.h>
#include <../lib/LibRobUS/src/LibRobus.h>

#define Ki 0 // intégrale
#define Kp 0 
#define Kd 0 // dériver
#define Periode 200 
float pid(int consigne,int feedbackPresent,  int feedbackPasse); // consigne = v mit, feedback = v réel
float iPresent = 0;  // pas touche

#pragma region PID
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
#pragma endregion
