#include "GiftBuleet.h"
#include "GameController.h"

GiftBuleet::GiftBuleet(Toolbar_t symbol, sf::Vector2f position)
	:Gift(symbol, position) {}

void GiftBuleet::handleCollision(Prince& , GameController&game)
{
	game.eraseStaticObject(*this);
	game.increaseBullet();
	//game.creatBullet();
	

	
}

