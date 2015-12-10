#include "Item.h"

Item::Item(const string& str, const int& num) : GameObject(str), durability_(num) 
{

}

Item::~Item()
{

}

const int Item::getDurability() 
{
    return durability_;
}