#pragma once 
#include "Object.h"
#include "Prince.h"
#include "KeyMonster.h"
#include "BallMonster.h"
#include "Monster.h"

class StaticObject : public Object
{
public:
	StaticObject (Toolbar_t symbol, sf::Vector2f position);

	virtual void handleCollision(Object&, GameController&) override {};
	virtual void handleCollision(Prince&, GameController&) override = 0;
	virtual void handleCollision(Wall&, GameController&) override {};
	virtual void handleCollision(Stair&, GameController&) override {};
	virtual void handleCollision(Coin&, GameController&) override {};
	virtual void handleCollision(Door&, GameController&) override {};
	virtual void handleCollision(KeyMonster&, GameController&) override {};
	virtual void handleCollision(BallMonster&, GameController&) override {};
	virtual void handleCollision(Gift&, GameController&) override {};
	virtual void handleCollision(Bullet&, GameController&) override {};

private:

};
