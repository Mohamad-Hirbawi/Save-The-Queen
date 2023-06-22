#include "KeyMonster.h"
KeyMonster::KeyMonster(Toolbar_t symbol, sf::Vector2f position)
	:Monster(symbol, position), m_positionKeyMonster(position) 
{
    m_startTime = std::chrono::steady_clock::now();
    int num = rand() % 2;
    if(num ==0)          m_dir = RIGHT;
    else                 m_dir = LEFT;
    
}


sf::Vector2f KeyMonster::directionFollowPrince(sf::Vector2f princePos)
{
    if (getposition().x < princePos.x)
        return RIGHT;
    return LEFT;
}

sf::Vector2f KeyMonster::getDirection(sf::Vector2f princePos)
{
    if (std::abs(getposition().y - princePos.y) <= 15)
        return directionFollowPrince(princePos);
 
    std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
    
    std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime);

    if (elapsedTime >= std::chrono::seconds(2)){
        m_startTime = currentTime;
        if (m_dir == RIGHT)    return LEFT;
        else    return RIGHT;

    }
    else     return m_dir;
 
}

void KeyMonster::move(sf::Time deltaTime, sf::Vector2f princePos,GameController& game)
{
    m_prevPos = m_icon.getPosition();
    m_dir = getDirection(princePos);
    m_icon.move(m_dir * MONSTERSPEED * deltaTime.asSeconds());
}

