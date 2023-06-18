#include "Door.h"

Door::Door(Toolbar_t symbol, sf::Vector2f position) :StaticObject(symbol, position) {}

void Door::handleCollision(Prince& prince, GameController& game)
{
	prince.handleCollision(*this, game);
}

void Door::handleCollision(KeyMonster& keyMonster, GameController& game)
{
	keyMonster.handleCollision(*this, game);
}

//void Door::handleCollision(BallMonster& ballMonster, GameController& game)
//{
//	//ballMonster.handleCollision(*this, game);
//}