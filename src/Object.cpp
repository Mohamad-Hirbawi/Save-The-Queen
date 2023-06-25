#include"Object.h"



Object::Object(Toolbar_t symbol, sf::Vector2f position):m_prevPos(position),m_open(false)
{
	auto texturePtr = Textures::instance().getIcon(symbol);
	m_icon.setTexture(*texturePtr);
	m_icon.setPosition(position);
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_icon);
}

bool Object::collidesWith(const Object& obj) const
{

	return m_icon.getGlobalBounds().intersects(obj.m_icon.getGlobalBounds());
}

sf::Vector2f Object::getposition() const
{
 	return m_icon.getPosition();

}

sf::Vector2f Object::getprevPos() const
{
	 	return m_prevPos;

}

void Object::moveToPrevPos()
{
	m_icon.setPosition(m_prevPos);
}

bool Object::isDoorOpen() const
{
	return m_open;
}

void Object::setDoorOpen()
{
	m_open = true;
}

void Object::setPrinceCollisStair()
{
	m_princeCollisStair = true;
}

sf::Sprite& Object::getIcon() 
{
	return m_icon;
}

void Object::dicreaseLifeBeast()
{
	m_beastLife--;
}

int Object::getLifeBeast() const
{
	return m_beastLife;
}
