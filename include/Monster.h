#pragma once
#include "MovingObject.h"

class Monster : public MovingObject
{
public:
	Monster(Toolbar_t symbol, sf::Vector2f position);

	virtual void move(sf::Time deltaTime) = 0;
	virtual void handleCollision(Prince&, GameController&) override {};
	virtual void handleCollision(Stair&, GameController&) override {};
	void handleCollision(Object&, GameController&) override {};
	void handleCollision(Wall&, GameController&) override =0;
	void handleCollision(Coin&, GameController&) override {};
	void handleCollision(KeyMonster&, GameController&) override = 0 ;
	void handleCollision(BallMonster&, GameController&) override = 0 ;
	//virtual void move(sf::Time deltaTime) = 0 ;
	
	


private:

	sf::Vector2f m_positionPrince;
};
