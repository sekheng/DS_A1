#include "Dweller.h"

/******************************************************************************/
/*!
\brief
Constructor with a string argument and const int argument - 
creates a Dweller by assigning a name, it's SPECIAL, initialize health to 100, radiation level to 0, 
number of stimpak and radaway to 0, initializing it's position to (0, 0), and initialize both 
outfit pointer and weapon pointer to a NULL pointer

\param str - the name of Dweller

\param special - the kSPECIAL_ of Dweller
*/
/******************************************************************************/
Dweller::Dweller(const string& str, const int& special)
	: GameObject(str), SPECIAL_(special), position_(0,0),
	health_(100), radiation_(0), stimpak_(0), radaway_(0),
		outfit_(NULL), weapon_(NULL)
{
}


/******************************************************************************/
/*!
\brief
Destructor - destroys Dweller and it's pointers when it goes out of scope or deleted
*/
/******************************************************************************/
Dweller::~Dweller()
{
    delete outfit_;
    delete weapon_;
}


/******************************************************************************/
/*!
\brief
get the SPECIAL value of both the Dweller and outfit combined

\exception The outfit_ is a NULL pointer or outfit's durability is less than 1 - 
it will only return Dweller's SPECIAL value

\return
const int of the resulting SPECIAL value
*/
/******************************************************************************/
const int Dweller::getSPECIAL()
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


/******************************************************************************/
/*!
\brief
get the values of Dweller's health

\return
const int value of health_
*/
/******************************************************************************/
const int Dweller::getCurrentHealth()
{
	return health_;
}


/******************************************************************************/
/*!
\brief
get the radiation value of the Dweller

\return
const int value of radiation_
*/
/******************************************************************************/
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}


/******************************************************************************/
/*!
\brief
get the attack damage of the Dweller

\return return 1 if Weapon pointer is a NULL or Weapon's durability is less than 1

\return
const int value of weapon_'s attack damage
*/
/******************************************************************************/
const int Dweller::getAttackDmg()
{
	if (weapon_ == NULL || weapon_->getDurability() < 1)
	{
		return 1;
	}
	else
	{
		return weapon_->getAttackDmg();
	};
}


/******************************************************************************/
/*!
\brief
get the current position of the Dweller

\return
const Vec2D of position_
*/
/******************************************************************************/
const Vec2D Dweller::getPosition()
{
	return position_;
}


/******************************************************************************/
/*!
\brief
set the new postion of the Dweller

\param pos - a const vec2D of Dweller's new position

\exception isDead() returns true - cannot set new position to the dweller when it is dead

\return
void
*/
/******************************************************************************/
void Dweller::setPosition(const Vec2D& pos)
{
    if (isDead() == false)
    {
	    position_.x = pos.x;
	    position_.y = pos.y;
    }
}


/******************************************************************************/
/*!
\brief
set the amount of damage that the Dweller received

\param dmg - the values of damage to reduce the dweller's health

\exception isDead() returns true - the Dweller will not receive any more damage when it is dead

\return void
*/
/******************************************************************************/
void Dweller::receiveHealthDamage(const int& dmg)
{
    if (isDead() == false)
        health_ -= dmg;
}


/******************************************************************************/
/*!
\brief
set the amount of radiation that the dweller received

\param dmg - the value of radiation that increase dweller's radiation

\exception isDead() returns true - the dweller will not receive anymore radiation when it is dead

\return void
*/
/******************************************************************************/
void Dweller::receiveRadDamage(const int& dmg)
{
    if (isDead() == false)
    {
        radiation_ += dmg;
        health_ -= dmg;
    }
}


/******************************************************************************/
/*!
\brief
set the amount of damage that dweller's equipment recieved

\param dmg - the value of damage to reduce the equipment's durability

\exception isDead() returns true - dweller's equipments can't receive anymore damage when it is dead

\exception when the outfit is a NULL pointer or outfit's durability is less than 1 - 
the outfit won't receive anymore damage

\exception when weapon is a NULL pointer or weapon's durability is less than 1 -
the weapon won't receive anymore damage

\return
void
*/
/******************************************************************************/
void Dweller::receiveEquipmentDamage(const int& dmg)
{
    if (isDead() == false)
    {
        if (outfit_ != NULL && outfit_->getDurability() > 0)
        {
            outfit_->receiveDamage(dmg);
        }
        if (weapon_ != NULL && weapon_->getDurability() > 0)
        {
            weapon_->receiveDamage(dmg);
        }
    }
}


/******************************************************************************/
/*!
\brief
add the number of Stimpak to the Dweller's stimpak

\param num - the number of Stimpak that the Dweller will receive

\exception isDead() returns true - the Dweller can't receive anymore Stimpak when it is dead

\return
void
*/
/******************************************************************************/
void Dweller::addStimpak(const int& num)
{
    if (isDead() == false)
        stimpak_ += num;
}


/******************************************************************************/
/*!
\brief
add the number of RadAway to the Dweller's radaway_

\param num -  the number of radaway that the Dweller received

\exception isDead() returns true - the Dweller can't receive anymore radaway when it dies

\return
void
*/
/******************************************************************************/
void Dweller::addRadAway(const int& num)
{
    if (isDead() == false)
        radaway_ += num;
}

/******************************************************************************/
/*!
\brief
decrease the number of Stimpak that the dweller has by 1 and increases the Dweller's health by 20

\exception isDead() returns true - the Dweller can't increases it's health when it dies

\exception when the maximun amount of health has reached - the Dweller can't use anymore of the Stimpak

\exception when Dweller has 0 Stimpak

\return
void
*/
/******************************************************************************/
void Dweller::useStimpak()
{
    if (health_ < (100 - radiation_) && isDead() == false && stimpak_ > 0)
    {
        stimpak_ -= 1;
        health_ += 20;
        if (health_ >= (100 - radiation_))
            health_ = (100 - radiation_);
    }
}


/******************************************************************************/
/*!
\brief
decrease the number of radaway by 1 and decreases the dweller's radiation by 10

\exception isDead() returns true - the Dweller can't use any radaway when it is dead

\exception when Dweller has 0 radaway

\exception when Dweller's radiation is less than 1 - the Dweller can't use any radaway

\return void
*/
/******************************************************************************/
void Dweller::useRadAway()
{
    if (isDead() == false && radiation_ > 0 && radaway_ > 0)
    {
        radaway_ -= 1;
        radiation_ -= 10;
        if (radiation_ <= 0)
        {
            radiation_ = 0;
        }
    }
}


/******************************************************************************/
/*!
\brief
copying the outfit pointer into the Dweller's outfit pointer

\param clothes - an Outfit pointer

\exception isDead() returns true - the Dweller can't be assigned a new outfit when it is dead

\return 
void
*/
/******************************************************************************/
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


/******************************************************************************/
/*!
\brief
copying the weapon pointer into the Dweller's outfit pointer

\param weapon - a Weapon pointer

\exception isDead() returns true - the Dweller can't be assigned a new weapon when it is dead

\return
void
*/
/******************************************************************************/
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


/******************************************************************************/
/*!
\brief
check whether the Dweller's health_ is less than 1

\return
true if dweller's health is less than 1

\return 
false if dweller's health is more than 0
*/
/******************************************************************************/
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
