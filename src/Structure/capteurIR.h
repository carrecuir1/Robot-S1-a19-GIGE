#include <Arduino.h>
#include <LibRobus.h>

#define NB_MESURE 4
struct capteurIR {
    capteurIR(){
    }
    float getDistance()
    {
      int Vo = 0;
      float distance = 0;
      for (int i = 0; i < NB_MESURE; i++)
      {
        delay(40);
        Vo = analogRead(A0);
        distance += 30617.0 * pow(Vo,-1.309);
      }
      return (distance / NB_MESURE);
    }
}

  
