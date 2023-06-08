#include "Coin.h"

Coin::Coin(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position) {}

void Coin::handleCollision(Prince& prince, GameController& game)
{
	
	prince.handleCollision(*this, game);
}
