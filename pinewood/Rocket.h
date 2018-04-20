#pragma once
#include "Car.h"

class Rocket: public Car {
    
public:
    Rocket(string rocketName, int rocketSpeed): Car(rocketName, rocketSpeed) {}
    ~Rocket() {}
    
    int getSpeed();
    
    
};