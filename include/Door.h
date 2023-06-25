#pragma once 
#include"StaticObject.h"

class Door : public StaticObject
{
public:
	Door(Toolbar_t symbol, sf::Vector2f position);
	~Door() {}
private:
};

