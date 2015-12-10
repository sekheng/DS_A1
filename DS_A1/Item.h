#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
protected:
	int durability_;
public:
	//constructor
    Item(const string& str, const int& num);

	//Destructor
    virtual ~Item();

	//setter
	virtual void receiveDamage(const int& num) = 0;

	//getter
    const int getDurability();
};

#endif  // ITEM_H