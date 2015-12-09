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
    if ( outfit_ != NULL && outfit_->getDurability() > 0)
    {
        int value = 0;
        for (int special = 1000000, remainder = 10; special > 0; special /= 10)
        {
            int num = (SPECIAL_ / special) % remainder;
            num += (outfit_->getSPECIAL() / special) % remainder;
            if (num > 9)
                num = 9;
            value += (num * special);
        }
        return value;
    }
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
    //else if (weapon_->getAttackDmg() < 0)
    //{
    //    return 0;
    //}
    //yolo
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
    if (isDead() == false)
        health_ -= dmg;
}


void Dweller::receiveRadDamage(const int& dmg)
{
    if (isDead() == false)
    {
        radiation_ += dmg;
        health_ -= dmg;
    }
}


// make sure the equipment's durability decrease
void Dweller::receiveEquipmentDamage(const int& dmg)
{
    if (isDead() == false)
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
}


// store the number of stimpak received
void Dweller::addStimpak(const int& num)
{
    stimpak_ += num;
}


// store the number of radaway received
void Dweller::addRadAway(const int& num)
{
    if (isDead() == false)
        radaway_ += num;
}

//when users want to use radaway, this function is called
void Dweller::useStimpak()
{
    if (health_ < (100 - radiation_) && isDead() == false)
    {
        stimpak_ -= 1;
        health_ += 20;
        if (health_ >= (100 - radiation_))
            health_ = (100 - radiation_);
        }
}


// This function is called when the user wants to use radaway
void Dweller::useRadAway()
{
    if (isDead() == false && radiation_ > 0)
    {
        radaway_ -= 1;
        radiation_ -= 10;
        if (radiation_ <= 0)
        {
            radiation_ = 0;
        }
    }
}


// copy the outfit given to the dweller's outfit
Outfit* Dweller::assignOutfit(Outfit* clothes)
{
    if (isDead() == false)
    {
        delete outfit_;
        outfit_ = new Outfit(clothes->getName(), clothes->getDurability(), clothes->getSPECIAL());
        return outfit_;
    }
    return outfit_;
}


// copying the weapon given and assign it to the dweller's weapon
Weapon* Dweller::assignWeapon(Weapon* weapon)
{
    if (isDead() == false)
    {
        delete weapon_;
        weapon_ = new Weapon(weapon->getName(), weapon->getDurability(), weapon->getAttackDmg());
        return weapon_;
    }
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
