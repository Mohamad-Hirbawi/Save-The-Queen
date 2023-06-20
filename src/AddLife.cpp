#include "AddLife.h"
#include "GameController.h"

AddLife::AddLife(Toolbar_t symbol, sf::Vector2f position)
	:Gift(symbol, position) {}

void AddLife::handleCollision(Prince&, GameController& game)
{
	game.eraseObject(*this, STATICS);
	  
	game.addLife();

}
