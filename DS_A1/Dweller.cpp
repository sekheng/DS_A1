#include "Dweller.h"


Dweller::Dweller(const string& str, const int& special)
	: GameObject(str), SPECIAL_(special), position_(0,0),
	health_(100), radiation_(0), stimpak_(0), radaway_(0),
		outfit_(NULL), weapon_(NULL)
{
}


Dweller::~Dweller()
{
    delete outfit_;
    delete weapon_;
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
	if (weapon_ == NULL || weapon_->getDurability() < 0)
	{
		return 1;
	}
    else if (weapon_->getAttackDmg() < 0)
    {
        return 0;
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


void Dweller::receiveHealthDamage(const int& dmg)
{
    health_ -= dmg;
}


void Dweller::receiveRadDamage(const int& dmg)
{
    radiation_ += dmg;
    health_ -= dmg;
}


// make sure the equipment's durability decrease
void Dweller::receiveEquipmentDamage(const int& dmg)
{
    if (outfit_ != NULL)
    {
        outfit_->receiveDamage(dmg);
    }
    if (weapon_ != NULL)
    {
        weapon_->receiveDamage(dmg);
    }
}


// store the number of stimpak received
void Dweller::addStimpak(const int& num)
{
    stimpak_ += num;
}


// store the number of radaway received
void Dweller::addRadAway(const int& num)
{
    radaway_ += num;
}

//when users want to use radaway, this function is called
void Dweller::useStimpak()
{
    stimpak_ -= 1;
    for (int num = 0; num < 20; ++num)
    {
        if (health_ >= (100 - radiation_))
            break;
        ++health_;
    }
}


// This function is called when the user wants to use radaway
void Dweller::useRadAway()
{
    radaway_ -= 1;
    radiation_ -= 10;
}


// copy the outfit given to the dweller's outfit
Outfit* Dweller::assignOutfit(Outfit* clothes)
{
    delete outfit_;
    outfit_ = new Outfit(clothes->getName(), clothes->getDurability(), clothes->getSPECIAL());
    return outfit_;
}


// copying the weapon given and assign it to the dweller's weapon
Weapon* Dweller::assignWeapon(Weapon* weapon)
{
    delete weapon_;
    weapon_ = new Weapon(weapon->getName(), weapon->getDurability(), weapon->getAttackDmg());
    return weapon_;
}


// check dweller's health
bool Dweller::isDead()
{
	if (health_ < 1)
	{
		return true;
	}
    else
    {
        return false;
    };
}
