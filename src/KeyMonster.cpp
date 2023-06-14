#include "KeyMonster.h"

KeyMonster::KeyMonster(Toolbar_t symbol, sf::Vector2f position)
	:Monster(symbol, position), m_positionKeyMonster(position) {}





sf::Vector2f getRandomDirection()
{
    int num = rand();
    num = num % 4;
    //switch (num)
    //{
    //case 0:
    //    return sf::Vector2f(1, 0);
    //    break;
    //case 1:
    //    return sf::Vector2f(0, 1);
    //    break;
    //case 2:
    //    return sf::Vector2f(-1, 0);
    //    break;
    //case 3:
    //    return sf::Vector2f(0, -1);
    //    break;

    //default: 
    //    return sf::Vector2f(0, 0);

    //    break;
    //}
        return sf::Vector2f(1, 0);


}

void KeyMonster::move(sf::Time deltaTime)
{
    m_prevPos = m_icon.getPosition();
    sf::Vector2f dir = getRandomDirection();
    m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());
}

void KeyMonster::handleCollision(Object& obj, GameController& game)
{
    obj.handleCollision(*this, game);
}

void KeyMonster::handleCollision(Wall&, GameController&)
{
    moveToPrevPos();

}
