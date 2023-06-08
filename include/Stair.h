#pragma once 
#include "StaticObject.h"

class Stair : public StaticObject
{
public:
	Stair(Toolbar_t symbol, sf::Vector2f position);
	void handleCollision(Prince& prince, GameController& game);
	//virtual void handleCollision(Stair&, GameController&) override;


private:

};

