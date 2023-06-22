#include "Door.h"

Door::Door(Toolbar_t symbol, sf::Vector2f position) 
	:StaticObject(symbol, position) {
	m_open = false;
}
