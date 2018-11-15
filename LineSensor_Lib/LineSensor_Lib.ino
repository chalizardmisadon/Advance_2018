//==================== LineSensor Header ====================

#ifndef Sumobot_LineSensor_h
#define Sumobot_LineSensor_h

#define check_high_value true

#include <Arduino.h>     //Arduino library

class Sumobot_LineSensor {
  public:
    Sumobot_LineSensor(int analogPin, int tolerance);
    int getPin(void);
    int getAnalog(void);
    bool detectLine(void);
    
  private:
    int pin, tolerance;
  
};

#endif

//==================== LineSensor Source ====================
Sumobot_LineSensor::Sumobot_LineSensor(int analogPin, int tol = 100){
  pin = analogPin;
  tolerance = tol;
}

inline int Sumobot_LineSensor::getPin(){
  return pin;
}

inline int Sumobot_LineSensor::getAnalog(){
  return analogRead(pin);
}

bool Sumobot_LineSensor::detectLine(){
  #if check_high_value
    if ((1023-tolerance) < getAnalog()){
      return true;
    } else {
      return false;
    }
  #else
    if (getAnalog() < (0+tolerance)){
      return true;
    } else {
      return false;
    }
   #endif
}





void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
