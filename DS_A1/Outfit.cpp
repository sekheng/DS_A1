#include "Outfit.h"

Outfit::Outfit(const string& str, const int& dur, const int& special) 
	: Item(str, dur), kSPECIAL(special)
{
}

Outfit::~Outfit()
{

}

int Outfit::getSPECIAL() const
{
	return kSPECIAL;
}


void Outfit::receiveDamage(const int& num)
{
    durability_ -= num;
}
