#pragma once 
#include "StaticObject.h"

class Stair : public StaticObject
{
public:
	Stair(Toolbar_t symbol, sf::Vector2f position);
	virtual void handleCollision(Prince& prince, GameController& game);

	bool isBottomCollision(const sf::Sprite& playerIcon) const;

	sf::FloatRect getGlobalBounds() const;

private:

};

