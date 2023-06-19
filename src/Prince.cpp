#include "Prince.h"
#include "GameController.h"

Prince::Prince(Toolbar_t symbol, sf::Vector2f position)
	:MovingObject(symbol, position)
{
    m_positionPrince = position;
}

void Prince::handleCollision(Stair& , GameController&)
{
    
    //if(stair.getposition().y == m_icon.getPosition().y + 1);
    //    m_princeCollisStair = true;


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
{}

void Prince::handleCollision(Door&, GameController&)
{  
    moveToPrevPos();
}

void Prince::handleCollision(KeyMonster&, GameController& game)
{
    game.did();
}

void Prince::handleCollision(BallMonster&, GameController& game)
{
    game.did();
}

sf::Vector2f dirFromKey()
{
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
            return pair.second;
        }
    }

    return { 0, 0 };
}


void Prince::move(sf::Time deltaTime, sf::Vector2f)
{
    
    m_prevPos = m_icon.getPosition();
    sf::Vector2f dir = dirFromKey();
    if ((dir == RIGHT || dir == LEFT) && !m_princeCollisStair)
        m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());
    else if (m_princeCollisStair)

        m_icon.move(dir * MOVEMENTSPEED * deltaTime.asSeconds());


    m_princeCollisStair = false;
    m_positionPrince = m_icon.getPosition();
}

//void Prince::handleCollision(Wall&, GameController&)
//{
//    moveToPrevPos();
//}
