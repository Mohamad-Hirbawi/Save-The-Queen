#pragma once
#include "MovingObject.h"
//#include "Stair.h"

class Bullet : public MovingObject
{
public:
	Bullet(Toolbar_t symbol, sf::Vector2f position);
	

	virtual void handleCollision(Prince&, GameController&) override {};
	virtual void handleCollision(Stair&, GameController&) override{};
	virtual void handleCollision(Object&, GameController&) override;
	virtual void handleCollision(Wall&, GameController&) override;
	virtual void handleCollision(Coin&, GameController&) override {};
	virtual void handleCollision(KeyMonster&, GameController&) override {};
	virtual void handleCollision(BallMonster&, GameController&) override {};
	virtual void handleCollision(Bullet&, GameController&) override {};
	virtual void handleCollision(Gift&, GameController&) override {};


	virtual void move(sf::Time deltaTime, sf::Vector2f)override;

private:
};