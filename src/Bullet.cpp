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

	m_icon.move(RIGHT *MOVEMENTSPEED * deltaTime.asSeconds());

		//m_icon.move(LEFT * MOVEMENTSPEED * deltaTime.asSeconds());

}
