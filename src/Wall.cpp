#include "Wall.h"

Wall::Wall(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position){}

void Wall::handleCollision(Prince& prince, GameController& game)
{
	prince.handleCollision(*this, game);
}

void Wall::handleCollision(Queen&queen, GameController&game)
{
	queen.handleCollision(*this, game);

}

void Wall::handleCollision(KeyMonster &keyMonster, GameController&game)
{
	keyMonster.handleCollision(*this, game);
}

void Wall::handleCollision(BallMonster& ballMonster, GameController&game)
{
	ballMonster.handleCollision(*this, game);
}

void Wall::handleCollision(Bullet& bullet, GameController& game)
{
	bullet.handleCollision(*this, game);

}
