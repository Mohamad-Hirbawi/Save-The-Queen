#include "Bullet.h"
#include "GameController.h"

Bullet::Bullet(Toolbar_t symbol, sf::Vector2f position, sf::Vector2f direction)
	:MovingObject(symbol, position), m_direction(direction)
{}

void Bullet::handleCollision(Prince&, GameController&)
{
}

void Bullet::handleCollision(Object& obj, GameController& game)
{
	obj.handleCollision(*this, game);

}

void Bullet::handleCollision(Wall& wall, GameController& game)
{
	game.eraseMovingObjectBullt(*this);
}

void Bullet::handleCollision(KeyMonster&, GameController&)
{
}

void Bullet::handleCollision(BallMonster&, GameController&)
{
}

void Bullet::handleCollision(Door&, GameController& game)
{
	game.eraseMovingObjectBullt(*this);
}


void Bullet::move(sf::Time deltaTime, sf::Vector2f)
{
	sf::Vector2f dir;
	m_prevPos = m_icon.getPosition();
	m_icon.move(m_direction * BULEETSPEED * deltaTime.asSeconds());
}
