#ifndef DWELLER_H
#define DWELLER_H

#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

class Dweller :
	public GameObject
{
private:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit * outfit_;
	Weapon * weapon_;
public:
	//constructor
	Dweller(const string& str, const int& special);

	//destructor
	virtual ~Dweller();

	//getters
	int getSPECIAL() const;
	int getCurrentHealth() const;
	int getCurrentRadDamage() const;
	int getAttackDmg() const;
	Vec2D getPosition() const;

	//setters
	void setPosition(const Vec2D& pos);

	//flags
	void receiveHealthDamage(const int& dmg);
	void receiveRadDamage(const int& dmg);
	// make sure the equipment's durability decrease
	void receiveEquipmentDamage(const int& dmg);
	// store the number of stimpak received
	void addStimpak(const int& num);
	// store the number of radaway received
	void addRadAway(const int& num);
	void useStimpak();
	// This function is called when the user wants to use radaway
	void useRadAway();
	// copy the outfit given to the dweller's outfit
	Outfit* assignOutfit(Outfit* clothes);
	// copying the weapon given and assign it to the dweller's weapon
    Weapon* assignWeapon(Weapon* weapon);
	// check dweller's health
	bool isDead();
};

#endif