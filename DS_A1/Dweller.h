#ifndef DWELLER_H
#define DWELLER_H

/******************************************************************************/
/*!
\file       Dweller.h
\author  Lee Sek Heng
\par        email: 150629Z@mymail.nyp.edu.sg
\brief
class to define a Dweller, which inheirited from GameObject class
*/
/******************************************************************************/
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

/******************************************************************************/
/*!
class Dweller:
\brief  Defines the Dweller, it's variables, Weapon pointer, Outfit pointer, and it's method
*/
/******************************************************************************/
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
	Dweller(const string& str, const int& special);

	virtual ~Dweller();

	const int getSPECIAL();
    const int getCurrentHealth();
    const int getCurrentRadDamage();
    const int getAttackDmg();
    const Vec2D getPosition();

	void setPosition(const Vec2D& pos);

	void receiveHealthDamage(const int& dmg);
	void receiveRadDamage(const int& dmg);
	void receiveEquipmentDamage(const int& dmg);
	void addStimpak(const int& num);
	void addRadAway(const int& num);
	void useStimpak();
	void useRadAway();
	Outfit* assignOutfit(Outfit* clothes);
    Weapon* assignWeapon(Weapon* weapon);
	bool isDead();
};

#endif