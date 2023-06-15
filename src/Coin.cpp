#include "Coin.h"
#include "GameController.h"

Coin::Coin(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position) {}

void Coin::handleCollision(Prince& prince, GameController& game)
{
	game.ChangeStaticObj(COIN,m_icon.getPosition());
	game.increaseScore(EATCOIN);
}
