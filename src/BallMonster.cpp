#include "BallMonster.h"
#include "BallMonster.h"

BallMonster::BallMonster(Toolbar_t symbol, sf::Vector2f position)
	:Monster(symbol, position), m_positionBallMonster(position) {}

void BallMonster::move(sf::Time deltaTime)
{
	//m_prevPos = m_icon.getPosition();
	//sf::Vector2f dir = getRandomDirection();
	//m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds() * 10.f);
}
