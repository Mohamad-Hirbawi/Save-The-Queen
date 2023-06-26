#pragma once
#include "Object.h"

class MovingObject :public Object
{
public:
	MovingObject(Toolbar_t symbol, sf::Vector2f position);
	~MovingObject() {}

	virtual void move(sf::Time deltaTime, sf::Vector2f, GameController& game) = 0;
	virtual void handleCollision(Object&, GameController&) {}


	sf::Vector2f m_dirPrince;

protected:
	sf::Vector2f m_positionPrince;


};




