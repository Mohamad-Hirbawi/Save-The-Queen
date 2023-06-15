#include "IncreasingTime.h"
#include "GameController.h"

IncreasingTime::IncreasingTime(Toolbar_t symbol, sf::Vector2f position)
	:Gift(symbol, position) {}

void IncreasingTime::handleCollision(Prince&, GameController& game)
{
	game.ChangeStaticObj(GIFT, m_icon.getPosition());
	game.increaseTime();
}
