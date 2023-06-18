#include "Coin.h"
#include "GameController.h"

Coin::Coin(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position) {}

void Coin::handleCollision(Prince&, GameController& game)
{
	game.eraseStaticObject(*this);
	game.increaseScore(EATCOIN);
}
