#include "Cleric.h"

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
	int Cleric::getDamage() {
	    return(fighterMagic);
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
	void Cleric::reset() {
	    fighterHitPoints = maxHitPoints;
	    mana = fighterMagic * 5;
	}
    
    /*
	*	useAbility()
	*
	*	Attempts to perform a special ability based on the type of fighter.  The
	*	fighter will attempt to use this special ability just prior to attacking
	*	every turn.
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
	bool Cleric::useAbility() {
	    int healing_amount;
	    
	    if (fighterHitPoints == maxHitPoints) {
	        return false;
	    }
	    
	    if (mana >= CLERIC_ABILITY_COST) {
	        healing_amount = fighterMagic / 3;
	        if ((fighterHitPoints + healing_amount) >= maxHitPoints) {
	            fighterHitPoints = maxHitPoints;
	        }
	        else {
	            fighterHitPoints += healing_amount;
	        }
	        mana -= CLERIC_ABILITY_COST;
	        return true;
	    }
	    else {
	        return false;
	    }
	}
	
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
    void Cleric::regenerate() {
		int amount_recovered;
		int mana_recovered;
		
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
		
		mana_recovered = fighterMagic / 5;
		if (mana_recovered == 0) {
		    mana_recovered = 1;
		}
		
		if ((mana_recovered + mana) >= (5 * fighterMagic)) {
			mana = 5 * fighterMagic;
		}
		else {
			mana += mana_recovered;
		}
	}
