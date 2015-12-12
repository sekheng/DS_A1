#include "Outfit.h"

/******************************************************************************/
/*!
\brief
constructor with a string argument and 2 int arguments - Construct an Outift by assigning a name, it's durability, and SPECIAL values

\param str - the name of the Outfit

\param dur - the durability of the Outfit

\param special - the kSPECIAL value of the Outfit
*/
/******************************************************************************/
Outfit::Outfit(const string& str, const int& dur, const int& special)
	: Item(str, dur), kSPECIAL(special)
{
}

/******************************************************************************/
/*!
\brief
Destroy the Outfit when it goes out of scope or deleted
*/
/******************************************************************************/
Outfit::~Outfit()
{

}

/******************************************************************************/
/*!
\brief
get the value of kSPECIAL

\return
const int value of kSPECIAL
*/
/******************************************************************************/
const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}


/******************************************************************************/
/*!
\brief
set the amount of damage to reduce the durability of Outfit

\param num - the amount of damage that is to be dealt to the durability of the Outfit

\return 
void
*/
/******************************************************************************/
void Outfit::receiveDamage(const int& num)
{
    durability_ -= num;
}
