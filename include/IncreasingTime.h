#pragma once
#include"Gift.h"

class IncreasingTime: public Gift
{
public:
	IncreasingTime(Toolbar_t symbol, sf::Vector2f position);
	virtual void handleCollision(Prince&, GameController&) override;
	virtual void handleCollision(Queen&, GameController&) override {};
	
};