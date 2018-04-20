#pragma once
#include "Car.h"

class Panda: public Car {
    
public:
    Panda(string pandaName, int pandaSpeed): Car(pandaName, pandaSpeed) {}
    ~Panda() {}
    
    int getSpeed();
    
    
};