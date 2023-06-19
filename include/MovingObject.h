#pragma once
#include "Object.h"

class MovingObject :public Object
{
public:
	MovingObject() {}
	MovingObject(Toolbar_t symbol, sf::Vector2f position);

	void moveToPrevPos();

	virtual void move(sf::Time deltaTime, sf::Vector2f) = 0;
	virtual void handleCollision(Object&, GameController&) override =0;
	virtual void handleCollision(Prince&, GameController&) override = 0;
	virtual void handleCollision(Wall&, GameController&) override=0;
	virtual void handleCollision(Stair&, GameController&) override =0;
	virtual void handleCollision(Coin&, GameController&) override =0;
	virtual void handleCollision(Door&, GameController&) override =0;
	virtual void handleCollision(KeyMonster&, GameController&) override =0;
	virtual void handleCollision(BallMonster&, GameController&) override =0;
	virtual void handleCollision(Bullet&, GameController&) override =0;
	virtual void handleCollision(Gift&, GameController&) override =0;



protected:
	sf::Vector2f m_positionPrince;
	sf::Vector2f m_dirPrince;


};




