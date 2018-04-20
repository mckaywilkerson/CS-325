#include "Fighter.h"

    Fighter::Fighter(string name, int hitPoints, int strength, int speed, int magic) {
        fighterName = name;
        fighterHitPoints = hitPoints;
        fighterStrength = strength;
        fighterSpeed = speed;
        fighterMagic = magic;
        maxHitPoints = hitPoints;
        originalSpeed = speed;
    }

	/*
	*	getName()
	*
	*	Returns the name of this fighter.
	*/
	string Fighter::getName() const {
	    return (fighterName);
	}

	/*
	*	getMaximumHP()
	*
	*	Returns the maximum hit points of this fighter.
	*/
	int Fighter::getMaximumHP() const {
	    return (maxHitPoints);
	}

	/*
	*	getCurrentHP()
	*
	*	Returns the current hit points of this fighter.
	*/
	int Fighter::getCurrentHP() const {
	    return (fighterHitPoints);
	}

	/*
	*	getStrength()
	*
	*	Returns the strength stat of this fighter.
	*/
	int Fighter::getStrength() const {
	    return (fighterStrength);
	}

	/*
	*	getSpeed()
	*
	*	Returns the speed stat of this fighter.
	*/
	int Fighter::getSpeed() const {
	    return (fighterSpeed);
	}

	/*
	*	getMagic()
	*
	*	Returns the magic stat of this fighter.
	*/
	int Fighter::getMagic() const {
	    return (fighterMagic);
	}

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
	int Fighter::getDamage() {}

	/*
	*	takeDamage(int)
	*
	*	Reduces the fighter's current hit points by an amount equal to the given
	*	damage minus one fourth of the fighter's speed.  This method must reduce
	*	the fighter's current hit points by at least one.  It is acceptable for
	*	this method to give the fighter negative current hit points.
	*
	*	Examples:
	*		damage=10, speed=7		=> damage_taken=9
	*		damage=10, speed=9		=> damage_taken=8
	*		damage=10, speed=50		=> damage_taken=1
	*/
	void Fighter::takeDamage(int damage) {
		int damage_taken, damage_dodged;
		
		damage_dodged = fighterSpeed / 4;
		damage_taken = damage - damage_dodged;
		if (damage_taken <= 0) {
			damage_taken = 1;
		}
		fighterHitPoints = fighterHitPoints - damage_taken;
	}

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
	void Fighter::reset() {}

	/*
	*	regenerate()
	*
	*	Increases the fighter's current hit points by an amount equal to one sixth of
	*	the fighter's strength.  This method must increase the fighter's current hit
	*	points by at least one.  Do not allow the current hit points to exceed the
	*	maximum hit points.
	*
	*	Cleric:
	*	Also increases a Cleric's current mana by an amount equal to one fifth of the
	*	Cleric's magic.  This method must increase the Cleric's current mana by at
	*	least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
	*/
	void Fighter::regenerate() {
		int amount_recovered;
		
		amount_recovered = fighterStrength / 6;
		if (amount_recovered == 0) {
			amount_recovered = 1;
		}
		
		if ((amount_recovered + fighterHitPoints) >= maxHitPoints) {
			fighterHitPoints = maxHitPoints;
		}
		else {
			fighterHitPoints = fighterHitPoints + amount_recovered;
		}
	}

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
	*	Archer: Quickstep
	*	Increases the Archer's speed by one point each time the ability is used.
	*	This bonus lasts until the reset() method is used.
	*	This ability always works; there is no maximum bonus speed.
	*
	*	Cleric: Healing Light
	*	Increases the Cleric's current hit points by an amount equal to one third of its magic.
	*	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
	*	Will be used even if the Cleric's current HP is equal to their maximum HP.
	*	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
	*	Cleric Note:
	*	This ability, when successful, must increase the Cleric's current hit points
	*	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
	*	Do not allow the current hit points to exceed the maximum hit points.
	*
	*	Return true if the ability was used; false otherwise.
	*/
	bool Fighter::useAbility() {}