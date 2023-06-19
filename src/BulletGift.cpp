#include "BulletGift.h"
#include "GameController.h"

BulletGift::BulletGift(Toolbar_t symbol, sf::Vector2f position)
	:Gift(symbol, position) {}

void BulletGift::handleCollision(Prince& , GameController&game)
{
	game.eraseStaticObject(*this);
	game.increaseBullet();
	m_numBallGift += 3;
	
	
}

