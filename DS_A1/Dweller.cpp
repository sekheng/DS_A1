#include "Dweller.h"


Dweller::Dweller(const string& str, const int& special)
	: GameObject(str), SPECIAL_(special), position_(0,0),
	health_(100), radiation_(0), stimpak_(0), radaway_(0),
		outfit_(NULL), weapon_(NULL)
{
}


Dweller::~Dweller()
{
}


int Dweller::getSPECIAL() const
{
	return SPECIAL_;
}


int Dweller::getCurrentHealth() const
{
	return health_;
}


int Dweller::getCurrentRadDamage() const
{
	return radiation_;
}


int Dweller::getAttackDmg() const
{
	if (weapon_->getAttackDmg() == NULL)
	{
		return 1;
	}
	else
	{
		return weapon_->getAttackDmg();
	};
}


Vec2D Dweller::getPosition() const
{
	return position_;
}


void Dweller::setPosition(const Vec2D& pos)
{
	position_.x = pos.x;
	position_.y = pos.y;
}


bool Dweller::receiveHealthDamage(const int& dmg)
{
	return false;
}


bool Dweller::receiveRadDamage(const int& dmg)
{
	return false;
}


// make sure the equipment's durability decrease
void Dweller::receiveEquipmentDamage(const int& dmg)
{
}


// store the number of stimpak received
void Dweller::addStimpak(const int& num)
{
}


// store the number of radaway received
void Dweller::addRadAway(const int& num)
{
}

//when users want to use radaway, this function is called
void Dweller::useStimpak()
{
}


// This function is called when the user wants to use radaway
void Dweller::useRadAway()
{
}


// copy the outfit given to the dweller's outfit
Outfit* Dweller::assignOutfit(Outfit* clothes)
{
	return NULL;
}


// copying the weapon given and assign it to the dweller's weapon
Weapon* Dweller::assignOutift(Weapon* weapon)
{
	return NULL;
}


// check dweller's health
bool Dweller::isDead()
{
	if (health_ < 1)
	{
		return true;
	}
	return false;
}
