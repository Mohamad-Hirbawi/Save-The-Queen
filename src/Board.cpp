#include "Board.h"
#include <GameController.h>


Board::Board()
{
	m_read.open("board.txt", std::ios_base::in);
	readLvlMap();
}
bool Board::readLvlMap() {
	readLvlSize();

	if (this->m_read.eof())
		return false;

	auto line = std::string();
	for (int row = 0; row < m_height; row++)
	{
		getline(m_read, line);
		m_map.push_back(line);
	}
	return true;

}
void Board::readLvlSize(){
	std::string number;
	this->m_read >> number;
	if (m_read.eof())
		return;
	this->m_height = std::stoi(number);
	this->m_read >> number;
	this->m_width = std::stoi(number);
	//	this->m_read >> number;
	//this->m_leveltime = std::stoi(number);

	this->m_read.ignore();
	//std::cout << m_height << " " << m_width << std::endl;

}
std::vector<std::string> Board::getMap() const
{
	return m_map;
}

int Board::getHeight() const
{
	return m_height;
}

int Board::getWidth() const
{
	return m_width;
}

// templete
void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_staticObj.size(); i++)
	{
		if (m_staticObj[i] != nullptr)
			m_staticObj[i]->draw(window);
	}

	m_prince->draw(window);
}
void Board::createStaticObject(char c, sf::Vector2f position)
{
	switch (c)
	{
	case WALL_C:
		m_staticObj.push_back(std::make_unique<Wall>(WALL, position));
		break;
	case STAIR_C:
		m_staticObj.push_back(std::make_unique<Stair>(STAIR, position));
		break;
	case COIN_C:
		m_staticObj.push_back(std::make_unique<Coin>(COIN, position));
		break;
		//case KEY_C:
		//	m_staticObj.push_back(std::make_unique<Key>(KEY, position));
		//	break;
		//case CAKE_C:
		//	m_staticObj.push_back(std::make_unique<Cake>(CAKE, position));
		//	break;
		//case GATE_C:
		//	m_staticObj.push_back(std::make_unique<Gate>(GATE, position));
		//	break;
		//case GIFT_C:
		//	m_staticObj.push_back(selectGiftType(position));
		//	break;


	}
}

void Board::createMovingObject(char c, sf::Vector2f position)
{
	switch (c)
	{
	case PRINCE_C:
		m_prince = std::make_unique<Prince>(PRINCE, position);
		break;



	}
}




void Board::checkCollision(MovingObject& thisObj, GameController& game, const sf::Time& deltaTime)
{

	//sf::Vector2f pos = thisObj.getposition();
	//pos = { pos.x,pos.y - 1 };

	// check collision between moving objects and static objects
	for (auto& unmovable : m_staticObj)
	{

		if (unmovable != nullptr && thisObj.collidesWith(*unmovable))
		{
			thisObj.handleCollision(*unmovable, game);
		}
	}

}
