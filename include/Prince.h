#pragma once
#include "MovingObject.h"

class Prince : public MovingObject
{
public:
	Prince(Toolbar_t symbol, sf::Vector2f position);
	~Prince() {}
	virtual void move(sf::Time deltaTime, sf::Vector2f, GameController& game)override;

private:
	Stair* m_currentStair;
	sf::Vector2f m_stairDirection;
};
