#include "IncreasingTime.h"
#include "GameController.h"

IncreasingTime::IncreasingTime(Toolbar_t symbol, sf::Vector2f position)
	:Gift(symbol, position) {}

void IncreasingTime::handleCollision(Prince&, GameController& game)
{
	game.eraseObject(*this, STATICS);

	  
	game.increaseTime();
}
