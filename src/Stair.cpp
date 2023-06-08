#include "Stair.h"

Stair::Stair(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position) {}


void Stair::handleCollision(Prince& prince, GameController& game)
{
	prince.handleCollision(*this, game);
}




//void StairWall::handleCollision(Prince& prince, GameController& game)
//{
//	prince.handleCollision(*this, game);
//}
