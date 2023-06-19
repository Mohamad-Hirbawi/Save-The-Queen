#include "Bullet.h"

Bullet::Bullet(Toolbar_t symbol, sf::Vector2f position) 
	:MovingObject(symbol, position){}

void Bullet::handleCollision(Object& obj, GameController& game)
{
	obj.handleCollision(*this, game);

}

void Bullet::handleCollision(Wall&, GameController&)
{

}

void Bullet::move(sf::Time deltaTime, sf::Vector2f)
{
	sf::Vector2f dir;
	m_prevPos = m_icon.getPosition();
	if (m_dirPrince == RIGHT)
		 dir = RIGHT;
	else
		 dir = LEFT;
	m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());
}
