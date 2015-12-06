#include "Item.h"

Item::Item(const string& str, const int& num) : GameObject(str), durability_(num) 
{

}

Item::~Item()
{

}

int Item::getDurability() const
{
    return durability_;
}