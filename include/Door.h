#pragma once 
#include"StaticObject.h"

class Door : public StaticObject
{
public:
	Door(Toolbar_t symbol, sf::Vector2f position);
	virtual void handleCollision(Prince&, GameController&) override;
	void handleCollision(KeyMonster& keyMonster, GameController& game);
	virtual void handleCollision(Bullet&, GameController&) override;

private:
};

