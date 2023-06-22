#include "Queen.h"
#include "GameController.h"

Queen::Queen(Toolbar_t symbol, sf::Vector2f position)
    :MovingObject(symbol, position)
{
}

void Queen::move(sf::Time deltaTime, sf::Vector2f, GameController& game)
{
   
   m_dir = getDirection();  
    m_prevPos = m_icon.getPosition();
    m_icon.move(m_dir * MONSTERSPEED * deltaTime.asSeconds());

}

sf::Vector2f Queen::getDirection()
{


    std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
    std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime);

    if (elapsedTime >= std::chrono::seconds(4)) {
        m_startTime = currentTime;
        if (m_dir == RIGHT)    return LEFT;
        else    return RIGHT;

    }
    else     return m_dir;

}
