#ifndef WEAPON_H
#define WEAPON_H
/******************************************************************************/
/*!
\file       Weapon.h
\author  Lee Sek Heng
\par        email: 150629Z@mymail.nyp.edu.sg
\brief
Class to define a weapon, which inherited from Item class
*/
/******************************************************************************/
#include "Item.h"

/******************************************************************************/
/*!
class Weapon:
\brief  Defines the Weapon and and Weapon's Damage
*/
/******************************************************************************/
class Weapon :
	public Item
{
private:
	const int kAttackDmg;

public:
	Weapon(const string& str, const int& dur, const int& attck);

	virtual ~Weapon();

	const int getAttackDmg();

    virtual void receiveDamage(const int& num);
};

#endif