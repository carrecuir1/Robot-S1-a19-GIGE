#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>

#define voltageNoirM 4.60 //Valeur de tension associable à une couleur noire captée par le capteur, un peu arbitraire.
#define voltageNoirD 4.40
#define voltageNoirG 3.30

struct suiveurLigne{
    //Capteur avant sur port analogique 0, milieu sur 1, arrière sur 2.
    float voltage[3];

    void detection(float voltage[3]){
    
        voltage[0] = analogRead(0)*5.0/1023.0;
        voltage[1] = analogRead(1)*5.0/1023.0;
        voltage[2] = analogRead(2)*5.0/1023.0;
    }

    void suivreLigneDroite()
    {       //Voltage0 = gauche, 1 = centre, 2 = droite
            float voltage[3];
           //float encodeur_droit = 0,encodeur_gauche = 0;
            int retour = 0;
            detection(voltage);
            Motor moteur;
            moteur.resetPIDAndEncoder(0.2);
            moteur.move(0.2);
        while(retour !=1){
            Serial.println("test");
                
                if(voltage[0]>=voltageNoirG && voltage[1]<voltageNoirM && voltage[2]<voltageNoirD){
                    MOTOR_SetSpeed(0, 0.05);
                    MOTOR_SetSpeed(1,0.2);
                    while(voltage[0]>=voltageNoirG && voltage[1]<voltageNoirM && voltage[2]<voltageNoirD){
                        delay(50);
                        detection(voltage);
                    }
                    moteur.stopMotors();
                    delay(50);
                }
                else{

                    if(voltage[2]>=voltageNoirD && voltage[0]<voltageNoirG && voltage[1]<voltageNoirM){
                        MOTOR_SetSpeed(0, 0.2);
                        MOTOR_SetSpeed(1, 0.05);
                        while(voltage[2]>=voltageNoirD && voltage[1]<voltageNoirM && voltage[0]<voltageNoirG){
                            delay(50);
                            detection(voltage);
                        }
                        moteur.stopMotors();
                        delay(50);
                    }
                    else{
                        if(voltage[0]>=voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]<voltageNoirD){
                            MOTOR_SetSpeed(0, 0.05);
                            MOTOR_SetSpeed(1,0.2);
                            while(voltage[0]>=voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]<voltageNoirD){
                                delay(50);
                                detection(voltage);
                            }
                            moteur.stopMotors();
                            delay(50);
                        }
                        else{
                            if(voltage[0]<voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]>=voltageNoirD){
                                MOTOR_SetSpeed(0, 0.2);
                                MOTOR_SetSpeed(1, 0.05);
                                while(voltage[2]>=voltageNoirD && voltage[1]>=voltageNoirM && voltage[0]<voltageNoirG){
                                    delay(50);
                                    detection(voltage);
                                }
                                moteur.stopMotors();
                                delay(50);
                            }
                            else{
                                if(voltage[0]>=voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]>=voltageNoirD){
                                    moteur.angleTurn(1);
                                }
                                else
                                    moteur.move(0.2);
                            }
                        }
                    }
                }
                 detection(voltage);
            }
            moteur.stopMotors();
        };
    

            /*
        while(retour != 1)
        {
            Serial.println("-----");
            Serial.println(voltage[0]);
            Serial.println(voltage[1]);
            Serial.println(voltage[2]);
            //Si les trois capteurs voient la ligne noire
            if(voltage[0]>=voltageNoir && voltage[1]>=voltageNoir && voltage[2]>=voltageNoir){

                Serial.println("les trois");
                moteur.move(0.2); 
                delay(50);
                detection(voltage);
                moteur.stopMotors();
            }
            else
            {
                if(voltage[1]>=voltageNoir && (voltage[0]<voltageNoir || voltage[2]<voltageNoir)){
            
                    ENCODER_Reset(0);
                    ENCODER_Reset(1);
                    Serial.println("capteur central voit ligne noire");
                    //Tourne à gauche jusqu'à ce qu'il trouve, pour un max de 30 degrés.
                    while(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir){

                        if(encodeur_droit>90)
                            break;
                
                        moteur.angleTurn(-3); //Valeurs de ±3 peut-être à revoir, parfaitement arbitraire
                        detection(voltage);
                        encodeur_droit+=ENCODER_Read(1);
                        delay(50);
                    }
                    encodeur_droit = 0;
                    moteur.stopMotors();
                    //Après le 30 degrés à gauche, si pas trouvé la ligne, refait la même opération vers la droite.
                    if(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir){

                        moteur.angleTurn(30);
                        ENCODER_Reset(0);
                        ENCODER_Reset(1);
                        while(voltage[0]<voltageNoir||voltage[1]<voltageNoir||voltage[2]<voltageNoir){ 
                    
                            if(encodeur_gauche>90)
                                break;

                            moteur.angleTurn(3);
                            detection(voltage);
                            encodeur_gauche+=ENCODER_Read(0);
                            delay(50);
                        }
                        encodeur_gauche = 0;
                    }
                    moteur.stopMotors();

                }
                else
                {
                  //Si le capteur de l'avant voit la ligne noire mais que les deux autres capteurs non
                  if(voltage[0]>=voltageNoir && voltage[2]<voltageNoir && voltage[1]<voltageNoir){
                    Serial.println("capteur de l'avant voit ligne noire");
                    moteur.move(0.2); //Avance jusqu'à ce que le capteur central voie la ligne noire.       
                    while(voltage[1]<voltageNoir){
                        delay(50);
                        detection(voltage);
                    }
                    moteur.stopMotors();
                  }
                 else{
                    //Si le capteur arrière voit la ligne noire mais que les deux autres capteurs non
                    if(voltage[2]>=voltageNoir && voltage[1]<voltageNoir && voltage[0]<voltageNoir){
                        Serial.println("Capteur arrière voit ligne noire");
                        moteur.move(0.2); //Recule jusqu'à ce que le capteur central voie la ligne noire.
                        while(voltage[1]<voltageNoir){
                            detection(voltage);
                            delay(50);
                        }
                        moteur.stopMotors();
                    }
                    else{
                    
                        //Si aucun capteur ne voit la ligne noire
                        if(voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir){
                            Serial.println("Aucun capteur voit ligne noire");

                            ENCODER_Reset(0);
                            ENCODER_Reset(1);

                            while(voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir){

                                if(encodeur_droit>90)
                                    break;

                                moteur.angleTurn(-3);
                                detection(voltage);
                                encodeur_droit+=ENCODER_Read(1);
                                delay(50);
                            }
                            encodeur_droit = 0;
                            encodeur_gauche = 0;
                            moteur.stopMotors();
                            if(voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir){
        
                                moteur.angleTurn(30);
                                ENCODER_Reset(0);
                                ENCODER_Reset(1);
                                while(voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir){

                                    if(encodeur_gauche>90)
                                        break;

                                    moteur.angleTurn(3);
                                    detection(voltage);
                                    encodeur_gauche+=ENCODER_Read(0);
                                    delay(50);
                                }
                                encodeur_gauche = 0;
                            }
                            if((voltage[0]<voltageNoir && voltage[1]<voltageNoir && voltage[2]<voltageNoir))
                                retour = 1;
                        }
                    }
            

                }
            
            } 
        
        }         
    }*/
                      
  };