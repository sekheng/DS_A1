#include "Item.h"

Item::Item(const string& str, const int& num) : GameObject(str)
{
	durabiliy_ = num;
}

Item::~Item()
{

}

void Item::reduceDurability(const int& num)
{
	durabiliy_ -= num;
}

int Item::getDurability() const 
{
	return durabiliy_;
}