//==================== RangeFinder Header ====================
#ifndef Sumobot_Rangefinder_h
#define Sumobot_Rangefinder_h

#include <Arduino.h>     //Arduino library
#include <Wire.h>        //Wire library
#include <VL53L0X.h>     //Pololu library

class Sumobot_Rangefinder {
  public:
    Sumobot_Rangefinder(int XShutPin , uint8_t address);
    int getDistance(void);
    bool detect(void);


  private:
    VL53L0X sensor;
    int distance;
};

#endif

//==================== RangeFinder Source ====================
Sumobot_Rangefinder::Sumobot_Rangefinder(int XShutPin, uint8_t address = 0x29){
  pinMode(XShutPin, OUTPUT);
  digitalWrite(XShutPin, LOW);       //pull XSHUT pin low
  delay(10);                    //delay 10 ms to reset
  pinMode(XShutPin, INPUT);          //set pin to input to allow sensor board to pull XSHUT to 2.8
  sensor.init(true);
  delay(100);                   //init delay
  sensor.setAddress(address);   //set different address
  sensor.setTimeout(500);
  sensor.startContinuous();
}

inline int Sumobot_Rangefinder::getDistance(){
  return sensor.readRangeContinuousMillimeters();
}

inline bool Sumobot_Rangefinder::detect(){
  distance = getDistance();
  return (2 < distance && distance < 100);
  
}

//==================== Main ==================================
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
