#include "Weapon.h"


/******************************************************************************/
/*!
\brief
constructor with string argument  and 2 int arguments - Construct a Weapon by assigning a name, it's durability, and it's damage

\param str - the name of the Weapon

\param dur - the durability of the Weapon

\param attck - the kAttackDmg of the Weapon
*/
/******************************************************************************/
Weapon::Weapon(const string& str, const int& dur, const int& attck)
	: Item(str, dur), kAttackDmg(attck)
{
}
/******************************************************************************/
/*!
\brief
Destroy Weapon when it goes out of scope or deleted
*/
/******************************************************************************/
Weapon::~Weapon()
{
}


/******************************************************************************/
/*!
\brief
get the value of kAttackDmg

\return
const int value of kAttackDmg
*/
/******************************************************************************/
const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}

/******************************************************************************/
/*!
\brief
set the amount of damage then divide it by half before using it's value to reduce the Weapon's durability

\param num - the value of the damage dealt to it's durability

\exception Divide 1 by half - the value becomes 0 since it is rounded down

\return 
void
*/
/******************************************************************************/
void Weapon::receiveDamage(const int& num)
{
    durability_ -= (num / 2);
}