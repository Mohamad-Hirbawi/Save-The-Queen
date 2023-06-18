#include "MovingObject.h"

 MovingObject::MovingObject(Toolbar_t symbol, sf::Vector2f position):
	 Object(symbol, position) {}

 void MovingObject::moveToPrevPos()
 {
     m_icon.setPosition(m_prevPos);
 }