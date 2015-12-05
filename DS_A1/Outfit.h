#ifndef OUTFIT_H
#define OUTFIT_H

#include "Item.h"

class Outfit : public Item
{
private:
	const int kSPECIAL;
public:
	//constructor
	Outfit(const string& str, const int& dur, const int& special);

	//destructor
	virtual ~Outfit();

	//getter
	int getSPECIAL() const;
    virtual void receiveDamage(const int& num);
};

#endif