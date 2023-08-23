#include "BallMonster.h"
#include "GameController.h"

BallMonster::BallMonster(Toolbar_t symbol, sf::Vector2f position)
	:Monster(symbol, position) {
    m_startTime = std::chrono::steady_clock::now();
    m_startTime2 = std::chrono::steady_clock::now();
    int num = rand() % 2;
    if (num == 0)          m_dir = RIGHT;
    else                 m_dir = LEFT;
}


sf::Vector2f BallMonster::getDirection(const sf::Vector2f &princePos)
{
    if (getposition().y - princePos.y >= -20 && getposition().y - princePos.y <= 20)// func(sameRow)
        return STANDIGSTIL;

    std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
    std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime);

    if (elapsedTime >= std::chrono::seconds(1)) {
        m_startTime = currentTime;
        if (m_dir == RIGHT)    return LEFT;
        else    return RIGHT;

    }
    else     return m_dir;

}

void BallMonster::move(sf::Time deltaTime, sf::Vector2f princePos, GameController& game)
{
    m_prevPos = m_icon.getPosition();
    m_dir = getDirection(princePos);
    if (m_dir == STANDIGSTIL)
    {
        std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
        std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime2);

        if (elapsedTime >= std::chrono::seconds(2))
        {
            m_startTime2 = currentTime;
            game.creatBullet(m_icon.getPosition(), BALLMONSTER);
        }

    }
    else
        m_icon.move(m_dir * MONSTERSPEED * deltaTime.asSeconds());
}
