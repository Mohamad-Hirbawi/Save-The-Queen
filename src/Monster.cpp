#include "Monster.h"

Monster::Monster(Toolbar_t symbol, sf::Vector2f position)
	:MovingObject(symbol, position), m_positionPrince(position) {}