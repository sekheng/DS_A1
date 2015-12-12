#include "Item.h"

/******************************************************************************/
/*!
\brief
Constructor with string argument and const int argument - construct an Item by assigning the integer to it's durability and the string to the GameObject's kName

\param str - the name of the Item

\param num - the durability of the Item
*/
/******************************************************************************/
Item::Item(const string& str, const int& num) : GameObject(str), durability_(num)
{

}

/******************************************************************************/
/*!
Destructor - destroy Item when it is deleted or goes out of scope
*/
/******************************************************************************/
Item::~Item()
{

}

/******************************************************************************/
/*!
\brief
get the value of durability_

\return
const int value of durability_
*/
/******************************************************************************/
const int Item::getDurability()
{
    return durability_;
}