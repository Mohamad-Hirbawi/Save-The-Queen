#pragma once
#include "MovingObject.h"

class Monster : public MovingObject
{
public:
	Monster(Toolbar_t symbol, sf::Vector2f position);
	~Monster() {}
	virtual void move(sf::Time deltaTime, sf::Vector2f,GameController& game) = 0;
private:

	sf::Vector2f m_positionMonster;
};
