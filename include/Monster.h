#pragma once
#include "MovingObject.h"

class Monster : public MovingObject
{
public:
	Monster(Toolbar_t symbol, sf::Vector2f position);

	virtual void move(sf::Time deltaTime, sf::Vector2f) = 0;
	virtual void handleCollision(Prince&, GameController&) override =0;
	virtual void handleCollision(Stair&, GameController&) override {};
	void handleCollision(Object&, GameController&) override {};
	void handleCollision(Wall&, GameController&) override=0;
	void handleCollision(Coin&, GameController&) override {};
	void handleCollision(KeyMonster&, GameController&) override {};
	void handleCollision(BallMonster&, GameController&) override {};

private:

	sf::Vector2f m_positionMonster;
};
