#ifndef ITEM_H
#define ITEM_H
/******************************************************************************/
/*!
\file       Item.h
\author  Lee Sek Heng
\par        email: 150629Z@mymail.nyp.edu.sg
\brief
The Base class of Weapon and Outfit and to define an Item, which inheirited from GameObject class
*/
/******************************************************************************/
#include "GameObject.h"
/******************************************************************************/
/*!
            class Item:
\brief  Defines the Item and Item's durability, and recieveDamage(const int& num) as a pure virtual function
*/
/******************************************************************************/
class Item : public GameObject
{
protected:
	int durability_;

public:
    Item(const string& str, const int& num);

    virtual ~Item();

	virtual void receiveDamage(const int& num) = 0;

    const int getDurability();
};

#endif  // ITEM_H