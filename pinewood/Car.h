#pragma once
#include "CarInterface.h"
using namespace std;

/*
*	WARNING: You shouldnt have to change this interface file, just inherit from it.
*/

/*
*	This class specifies the methods for a car.
*
*	All cars have the following attributes:
*		Name - The car's name
*		Speed - The speed the car can attain.
*
*	The two car types have unique abilities:
*		Rocket - doubles the speed.
*		Panda - halves the speed.
*/

class Car: public CarInterface
{
protected:
	string myname;
	int myspeed;
	
public:
	Car(string name, int speed) {myname = name; myspeed = speed;}
	virtual ~Car() {}

	/*
	*	getName()
	*
	*	Returns the name of this car.
	*/
	virtual string getName() const;

	/*
	*	getSpeed()
	*
	*	Returns the speed of this car.
	*/
	virtual int getSpeed() const;
};