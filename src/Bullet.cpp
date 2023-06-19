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


}
