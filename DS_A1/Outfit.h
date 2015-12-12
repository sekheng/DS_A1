#ifndef OUTFIT_H
#define OUTFIT_H
/******************************************************************************/
/*!
\file       Outfit.h
\author  Lee Sek Heng
\par        email: 150629Z@mymail.nyp.edu.sg
\brief
Class to define an Outift, which inheirited from the Item class
*/
/******************************************************************************/
#include "Item.h"

/******************************************************************************/
/*!
class Outfit:
\brief  Defines the Outfit and it's SPECIAL value
*/
/******************************************************************************/
class Outfit : public Item
{
private:
	const int kSPECIAL;

public:
	Outfit(const string& str, const int& dur, const int& special);

	virtual ~Outfit();

	const int getSPECIAL();
    virtual void receiveDamage(const int& num);
};

#endif