#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon :
	public Item
{
private:
	const int kAttackDmg;
public:
	//constructor
	Weapon(const string& str, const int& dur, const int& attck);

	//destructor
	virtual ~Weapon();

	// getter
	int getAttackDmg() const;


    virtual void receiveDamage(const int& num);
};

#endif