#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>
#include <Adafruit_TCS34725.h>


#define consigne 0.35

bool test;
void setup() {
  BoardInit();
  test = true;
}

void loop() {

  Adafruit_TCS34725 colorSensor(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);
  uint16_t red, blue, green, clear;
  if(ROBUS_IsBumper(3)){
    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0)){
      
      if (colorSensor.begin()) 
      {
        Serial.println("Found sensor");
      }   
      else 
      {
        Serial.println("No TCS34725 found ... check your connections");
        while (1);
      }

      colorSensor.getRawData(&red, &blue, &green, &clear);
        //red = colorSensor.read16(TCS34725_RDATAL);
        //green = colorSensor.read16(TCS34725_GDATAL);
        //blue = colorSensor.read16(TCS34725_BDATAL);

      Serial.print(red);
      Serial.print(" ");
      Serial.print(green);
      Serial.print(" ");
      Serial.print(blue);
      Serial.print(" ");
      Serial.print(clear);
      Serial.print("\n");

      delay(300);
    }
  }
}
