#pragma once
#include "Object.h"

class MovingObject :public Object
{
public:
	MovingObject() {}
	MovingObject(Toolbar_t symbol, sf::Vector2f position);

	void moveToPrevPos();

	virtual void move(sf::Time deltaTime) = 0;
	virtual void handleCollision(Object&, GameController&) override =0;
	virtual void handleCollision(Prince&, GameController&) override = 0;
	virtual void handleCollision(Wall&, GameController&) override=0;
	virtual void handleCollision(Stair&, GameController&) override =0;
	virtual void handleCollision(Coin&, GameController&) override =0;
	virtual void handleCollision(KeyMonster&, GameController&) override =0;
	virtual void handleCollision(BallMonster&, GameController&) override =0;

private:
};




