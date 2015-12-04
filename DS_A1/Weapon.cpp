#include "Weapon.h"


Weapon::Weapon(const string& str, const int& dur, const int& attck)
	: Item(str, dur), kAttackDmg(attck)
{
}

Weapon::~Weapon()
{
}


// getter
int Weapon::getAttackDmg() const
{
	return kAttackDmg;
}


void Weapon::receiveDamage(const int& num)
{
    durability_ -= (num / 2);
}
