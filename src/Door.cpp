#include "Door.h"
#include "GameController.h"

Door::Door(Toolbar_t symbol, sf::Vector2f position) 
	:StaticObject(symbol, position) {
	m_open = false;
}

void Door::handleCollision(Prince& prince, GameController& game)
{
	if (m_open)
		return;
	if (game.haveKey())
	{
		m_icon.setTexture(*Textures::instance().getIcon(OPENDOOR));
		m_open = true;
	}
	else
	prince.handleCollision(*this, game);
}

void Door::handleCollision(KeyMonster& keyMonster, GameController& game)
{
	if (m_open)
		return;
	keyMonster.handleCollision(*this, game);
}

//void Door::handleCollision(BallMonster& ballMonster, GameController& game)
//{
//	//ballMonster.handleCollision(*this, game);
//}
