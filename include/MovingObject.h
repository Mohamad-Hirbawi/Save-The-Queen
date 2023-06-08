#pragma once
#include "Object.h"

class MovingObject :public Object
{
public:
	MovingObject() {}
	MovingObject(Toolbar_t symbol, sf::Vector2f position);

	//void moveToPos(sf::Vector2f pos);
	//bool outOfBounds() const;

	void move(sf::Time deltaTime);

	void moveToPrevPos();

	virtual void handleCollision(Object&, GameController&) override =0;
	virtual void handleCollision(Prince&, GameController&) override = 0;
	virtual void handleCollision(Wall&, GameController&) override=0;
	virtual void handleCollision(Stair&, GameController&) override =0;
	virtual void handleCollision(Coin&, GameController&) override =0;

private:
	//sf::Vector2f m_direction;

};




