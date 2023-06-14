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

sf::Vector2f dirFromKey()
{
    static const
        std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
        keyToVectorMapping =
    {
        { sf::Keyboard::Right, { 1, 0 } },
        { sf::Keyboard::Left , { -1, 0 } },
        { sf::Keyboard::Up   , { 0, -1 } },
        { sf::Keyboard::Down , { 0, 1 } },
    };
    for (const auto& pair : keyToVectorMapping)
    {
        if (sf::Keyboard::isKeyPressed(pair.first))
        {
            return pair.second;
        }
    }

    return { 0, 0 };
}


void Prince::move(sf::Time deltaTime)
{
    m_prevPos = m_icon.getPosition();
    sf::Vector2f dir = dirFromKey();
    if ((dir == sf::Vector2f(1, 0) || dir == sf::Vector2f(-1, 0)) && !m_princeCollisStair)
        m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());
    else if (m_princeCollisStair)
        m_icon.move(dirFromKey() * MOVEMENTSPEED * deltaTime.asSeconds());

    m_princeCollisStair = false;

}