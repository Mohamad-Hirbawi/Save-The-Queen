#include "BallMonster.h"
#include "Prince.h"

BallMonster::BallMonster(Toolbar_t symbol, sf::Vector2f position)
	:Monster(symbol, position) {}

void BallMonster::move(sf::Time deltaTime)
{
}

void BallMonster::handleCollision(Prince& prince, GameController& game)
{
	prince.handleCollision(*this, game);
}
