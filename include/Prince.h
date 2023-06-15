#pragma once
#include "MovingObject.h"

class Prince : public MovingObject
{
public:
	Prince(Toolbar_t symbol, sf::Vector2f position);


	virtual void handleCollision(Prince&, GameController&) override {};
	virtual void handleCollision(Stair&, GameController&) override ;
	virtual void handleCollision(Object&, GameController&) override;
	virtual void handleCollision(Wall&, GameController&) override;
	virtual void handleCollision(Coin&, GameController&) override;
	virtual void handleCollision(KeyMonster&, GameController&) override;
	virtual void handleCollision(BallMonster&, GameController&) override;


	virtual void move(sf::Time deltaTime)override;

private:
	
	sf::Vector2f m_positionPrince;
};
