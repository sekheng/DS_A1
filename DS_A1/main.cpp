#include <iostream>
#include "GameObject.h"
#include "Item.h"
#include "Outfit.h"
#include "Vec2D.h"
#include "Weapon.h"
#include "Dweller.h"

using std::cout;
using std::endl;

void main()
{
	//GameObject object("yolo");
	//cout << object.getName() << endl;
	Item item("Hello",2);
	cout << item.getName() << endl;
	cout << item.getDurability() << endl;
	cout << item.getCount() << endl;

	Outfit outfit("armor", 3, 1923001);
	cout << outfit.getCount() << endl;
	cout << outfit.getDurability() << endl;
	cout << outfit.getName() << endl;
	cout << outfit.getSPECIAL() << endl;
	cout << endl;

	Weapon weapon("reap", 10, 10);
	cout << weapon.getAttackDmg() << endl;
	cout << weapon.getCount() << endl;
	cout << weapon.getDurability() << endl;
	cout << weapon.getName() << endl;
	cout << endl;
}