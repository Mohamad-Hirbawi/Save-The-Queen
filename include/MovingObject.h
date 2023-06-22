#pragma once
#include "Object.h"

class MovingObject :public Object
{
public:
	MovingObject() {}
	MovingObject(Toolbar_t symbol, sf::Vector2f position);

	//void moveToPrevPos();

	virtual void move(sf::Time deltaTime, sf::Vector2f) = 0;

	virtual void handleCollision(Object&, GameController&) override {};
	virtual void handleCollision(Prince&, GameController&) override {};
	virtual void handleCollision(Queen&, GameController&) override {};
	virtual void handleCollision(Wall&, GameController&) override {};
	virtual void handleCollision(Stair&, GameController&) override {};
	virtual void handleCollision(Coin&, GameController&) override {};
	virtual void handleCollision(Door&, GameController&) override {};
	virtual void handleCollision(KeyMonster&, GameController&) override {};
	virtual void handleCollision(BallMonster&, GameController&) override {};
	virtual	void handleCollision(BeastMonster&, GameController&) override {};
	virtual void handleCollision(Bullet&, GameController&) override {};
	virtual void handleCollision(Gift&, GameController&) override {};

	sf::Vector2f m_dirPrince;

protected:
	sf::Vector2f m_positionPrince;


};




