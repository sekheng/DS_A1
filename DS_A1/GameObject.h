#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

using std::string;

class GameObject
{
private:
	const string kName;
	static int count_;
protected:
	//Constructors
	GameObject(const string& str);	//need string
public:
	//Destructor
	virtual ~GameObject();

	//Getter
	string getName(void);
	static int getCount();
};

#endif