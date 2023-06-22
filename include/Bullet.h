#pragma once
#include "MovingObject.h"
#include "Prince.h"

class Bullet : public MovingObject
{
public:
	Bullet(Toolbar_t symbol, sf::Vector2f position, sf::Vector2f direction);
	virtual void move(sf::Time deltaTime, sf::Vector2f)override;

private:
	sf::Vector2f m_direction;
};
