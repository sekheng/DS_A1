#include "Weapon.h"


Weapon::Weapon(const string& str, const int& dur, const int& attck)
	: Item(str, dur), kAttackDmg(attck)
{
}

Weapon::~Weapon()
{
}


// getter
const int Weapon::getAttackDmg() 
{
	return kAttackDmg;
}


void Weapon::receiveDamage(const int& num)
{
    durability_ -= (num / 2);
}
