#include "BeastMonster.h"
#include "GameController.h"

BeastMonster::BeastMonster(Toolbar_t symbol, sf::Vector2f position)
    :Monster(symbol, position) {
    m_startTime = std::chrono::steady_clock::now();
    m_startTime2 = std::chrono::steady_clock::now();


}
sf::Vector2f BeastMonster::directionFollowPrince(sf::Vector2f princePos)
{
    
    if (getposition().x < princePos.x && std::abs(getposition().y - princePos.y) <= 15)
        return RIGHT;
    else if (getposition().x > princePos.x &&  std::abs(getposition().y - princePos.y) <= 15)
        return LEFT;

    else if (getposition().y < princePos.y && getposition().x < princePos.x)
        return DOWNRIGHT;

    else if (getposition().y < princePos.y && getposition().x > princePos.x)
        return DOWNLEFT;

    else if (getposition().y > princePos.y && getposition().x < princePos.x)
        return UPRIGHT;

    else if (getposition().y > princePos.y && getposition().x > princePos.x)
        return UPLEFT;

}

sf::Vector2f BeastMonster::getDirection(sf::Vector2f princePos)
{
    if(std::abs( princePos.x - getposition().x) < 500 )
         return directionFollowPrince(princePos); 

    std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
    std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime);

    if (elapsedTime >= std::chrono::duration<double, std::chrono::microseconds::period>(1)) {
        m_startTime = currentTime;
        int num = rand() % 8;

        if (num == 0)          m_dir = RIGHT;
        else if (num == 1)        m_dir = LEFT;
        else if (num == 2)        m_dir = UP;
        else if (num == 3)        m_dir = DOWN;
        else if (num == 4)        m_dir = UPRIGHT;
        else if (num == 5)        m_dir = UPLEFT;
        else if (num == 6)        m_dir = DOWNRIGHT;
        else if (num == 7)        m_dir = DOWNLEFT;
        return m_dir;
    }
    else     return m_dir;

}

void BeastMonster::move(sf::Time deltaTime, sf::Vector2f princePos,GameController& game)
{
    m_prevPos = m_icon.getPosition();
    m_dir = getDirection(princePos);
    if (abs(getposition().y - princePos.y) <= 20)
    {
        std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
        std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime2);

        if (elapsedTime >= std::chrono::seconds(2))
        {
            m_startTime2 = currentTime;
            game.creatBullet(m_icon.getPosition(), BEASTMONSTER);
        }

    }
    m_icon.move(m_dir * MONSTERSPEED * deltaTime.asSeconds());
}
