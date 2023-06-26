#include "Prince.h"

Prince::Prince(Toolbar_t symbol, sf::Vector2f position) 
	:MovingObject(symbol, position)
{
    m_positionPrince = position;
}


sf::Vector2f dirFromKey()
{
    sf::Vector2f direction;
    static const
        std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
        keyToVectorMapping =
    {
        { sf::Keyboard::Right, { RIGHT } },
        { sf::Keyboard::Left , { LEFT} },
        { sf::Keyboard::Up   , { UP } },
        { sf::Keyboard::Down , { DOWN } },
    };

    for (const auto& pair : keyToVectorMapping)
    { 
        if (sf::Keyboard::isKeyPressed(pair.first))
        { 
            direction = pair.second;
            return pair.second;
        }
    }

    return direction;
}


void Prince::move(sf::Time deltaTime, sf::Vector2f, GameController& )
{
    m_prevPos = m_icon.getPosition();
    sf::Vector2f dir = dirFromKey();

    if (m_princeCollisStairUp && dir == UP || m_princeCollisStairDown && dir == DOWN) {
            m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());
            m_dirPrince = dir;
    }
    else {
        if (dir == RIGHT || dir == LEFT) {
            m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());
            m_dirPrince = dir;
        }

        //else if (dir == DOWN && playerRect.intersects(m_currentStair->getGlobalBounds())) {

        //    // التحقق من وجود السلم أسفل اللاعب
        //    if (playerRect.intersects(m_currentStair->getGlobalBounds())) {
        //        // النزول على السلم
        //        m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());
        //        m_dirPrince = dir;
        //    }
        //}
    }

    m_princeCollisStairUp = false;
    m_princeCollisStairDown = false;
    m_positionPrince = m_icon.getPosition();
}

