#include"Object.h"

Object::Object()
{
	m_icon.setScale(0.3, 0.3);
}


Object::Object(Toolbar_t symbol, sf::Vector2f position)
{
	auto texturePtr = Textures::instance().getIcon(symbol);
	m_icon.setTexture(*texturePtr);

	//m_icon.scale((float)(46 / m_icon.getGlobalBounds().width),
	//	(float)(46 / m_icon.getGlobalBounds().height));//46

	m_icon.setPosition(position);
	m_prevPos = position;
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
