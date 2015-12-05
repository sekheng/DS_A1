#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
protected:
	int durability_;
public:
	//constructor
    Item(const string& str, const int& num) : GameObject(str), durability_(num) {};

	//Destructor
    ~Item() {};

	//setter
	virtual void receiveDamage(const int& num) = 0;

	//getter
    int getDurability() const { return durability_; };
};

#endif  // ITEM_H