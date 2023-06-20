#pragma once
#include "MovingObject.h"

class Monster : public MovingObject
{
public:
	Monster(Toolbar_t symbol, sf::Vector2f position);

	virtual void move(sf::Time deltaTime, sf::Vector2f) = 0;
	virtual void handleCollision(Prince&, GameController&) override =0;
	virtual void handleCollision(Stair&, GameController&) override {};
	virtual void handleCollision(Object&, GameController&) override {};
	virtual void handleCollision(Wall&, GameController&) override=0;
	void handleCollision(Coin&, GameController&) override {};
	void handleCollision(KeyMonster&, GameController&) override {};
	void handleCollision(BallMonster&, GameController&) override {};
	void handleCollision(BeastMonster&, GameController&) override {};
	virtual void handleCollision(Bullet&, GameController&) override {};
	virtual void handleCollision(Gift&, GameController&) override {};
	virtual void handleCollision(Door&, GameController&) override { moveToPrevPos(); };



private:

	sf::Vector2f m_positionMonster;
};
