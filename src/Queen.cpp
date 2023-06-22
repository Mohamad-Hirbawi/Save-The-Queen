#include "Queen.h"
#include "GameController.h"

Queen::Queen(Toolbar_t symbol, sf::Vector2f position)
    :MovingObject(symbol, position)
{
}



void Queen::handleCollision(Object& obj, GameController& game)
{
    obj.handleCollision(*this, game);
}

void Queen::handleCollision(Wall&, GameController&)
{
    moveToPrevPos();
}


void Queen::handleCollision(Door&, GameController&)
{
    moveToPrevPos();
}
