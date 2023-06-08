#pragma once 
#include"StaticObject.h"

class Coin : public StaticObject
{
public:
	Coin(Toolbar_t symbol, sf::Vector2f position);
	virtual void handleCollision(Prince&, GameController&) override;


private:

};

