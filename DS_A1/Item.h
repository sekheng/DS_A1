#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
protected:
	int durabiliy_;
public:
	//constructor
	Item(const string& str, const int& num);

	//Destructor
	~Item();

	//setter
	void reduceDurability(const int& num);

	//getter
	int getDurability() const;
};

#endif