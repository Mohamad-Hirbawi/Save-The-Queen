#include "Prince.h"

Prince::Prince(Toolbar_t symbol, sf::Vector2f position)
	:MovingObject(symbol, position), m_positionPrince(position) {}

//void Prince::handleCollision(Stair&, GameController&)
//{
//	moveToPrevPos();
//
//}

void Prince::handleCollision(Stair&, GameController&)
{
	m_princeCollisStair = true;
}

void Prince::handleCollision(Object& obj, GameController& game)
{
	obj.handleCollision(*this, game);
}

void Prince::handleCollision(Wall&, GameController&)
{

	moveToPrevPos();
}

void Prince::handleCollision(Coin&, GameController&)
{
	moveToPrevPos();
}

//void Prince::handleCollision(Coin&, GameController&)
//{
//	moveToPrevPos();
//
//}
