#pragma once
#include "Fighter.h"

class Robot: public Fighter
{
protected:
    int energy, bonus_damage;

public:
    Robot(string robotName, int robotHitPoints, int robotStrength, int robotSpeed, int robotMagic): Fighter(robotName, robotHitPoints, robotStrength, robotSpeed, robotMagic) {energy = fighterMagic * 2; bonus_damage = 0;}
    ~Robot() {}

    /*
	*	getDamage()
	*
	*	Returns the amount of damage a fighter will deal.
	*
	*	Robot:
	*	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
	*
	*	Archer:
	*	This value is equal to the Archer's speed.
	*
	*	Cleric:
	*	This value is equal to the Cleric's magic.
	*/
	virtual int getDamage();
	
	/*
	*	reset()
	*
	*	Restores a fighter's current hit points to its maximum hit points.
	*
	*	Robot:
	*	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
	*	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
	*
	*	Archer:
	*	Also resets an Archer's current speed to its original value.
	*
	*	Cleric:
	*	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
	*/
	virtual void reset();
    
    /*
	*	useAbility()
	*
	*	Attempts to perform a special ability based on the type of fighter.  The
	*	fighter will attempt to use this special ability just prior to attacking
	*	every turn.
	*
    *	Robot: Shockwave Punch
	*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
	*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
	*	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
	*		Examples:
	*		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
	*		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
	*		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
	*		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
	*	Robot Note:
	*	The bonus damage formula should be computed using double arithmetic, and only
	*	the final result should be cast into an integer.
	*
	*	Return true if the ability was used; false otherwise.
	*/
	virtual bool useAbility();
    
};