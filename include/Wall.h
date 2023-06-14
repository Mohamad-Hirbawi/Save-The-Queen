#pragma once 
#include"StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(Toolbar_t symbol, sf::Vector2f position);
	virtual void handleCollision(Prince&, GameController&) override;
	virtual void handleCollision(KeyMonster&, GameController&) override;
	virtual void handleCollision(BallMonster&, GameController&) override;


private:

};

