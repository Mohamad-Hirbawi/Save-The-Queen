#pragma once
#include"Gift.h"
class AddLife : public Gift
{ 
public:
	AddLife(Toolbar_t symbol, sf::Vector2f position);
	~AddLife() {}
};