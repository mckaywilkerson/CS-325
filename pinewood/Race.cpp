    #include "Race.h"
    #include "CarInterface.h"
    #include "Rocket.h"
    #include "Panda.h"
    #include <sstream>
    
	/*
	*	addCar(string)
	*
	*	Adds a new car to the collection of cars in the race. 
	*
	*	Return true if a new car was added; false otherwise.
	*   The info string should have the name, type, speed
	*/
	bool Race::addCar(string info) {
	    stringstream ss(info);
	    string name, type;
	    int speed;
		
		if (ss >> name >> type >> speed) {
    		cout << "addCar got "<< name << " " << type << " " << speed << endl;
  			if (type == "R") { /* Rocket */
  				cout << "Adding Rocket"<<endl;
  				raceCars.push_back(new Rocket(name, speed));
  			}
  			else if (type == "P") { /* Panda */
  				cout << "Adding Panda"<<endl;
  				raceCars.push_back(new Panda(name, speed));
  			}
  			else {
  				return false; //not a valid type of car
  			}
  			return true;
		}
		return false; //invalid input, not enough tokens or wrong input type
	}

	/*
	*	removeCar(string)
	*
	*	Removes the car whose name is equal to the given name.  
	*
	*	Return true if a car is removed; false otherwise.
	*/
	bool Race::removeCar(string name) {
	    for (int i = 0; i < raceCars.size(); i++) {
  			if (raceCars.at(i)->getName() == name) {
  				delete(raceCars[i]);
  				raceCars.erase(raceCars.begin() + i);
  				return true;
			}
		}
		return false;
	}

	/*
	*	getCar(string)
	*
	*	Returns the memory address of a car whose name is equal to the given
	*	name.  Returns NULL if no fighter is found with the given name.
	*
	*	Return a memory address if a fighter is found; NULL otherwise.
	*/
	CarInterface* Race::getCar(string name) {
	    for (Car* cp : raceCars) {
  			if (cp->getName() == name) {
  				return cp;
  				}
			}
		return NULL;
	}

	/*
	*	getSize()
	*
	*	Returns the number of cars in the race.
	*
	*	Return a non-negative integer.
	*/
	int Race::getSize() const {
	    return (raceCars.size());
	}