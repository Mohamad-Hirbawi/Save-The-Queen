#include "Wall.h"

Wall::Wall(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position){}

void Wall::handleCollision(Prince& prince, GameController& game)
{
	prince.handleCollision(*this, game);
}
