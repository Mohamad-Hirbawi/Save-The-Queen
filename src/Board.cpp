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
void Board::readLvlSize() {
	std::string number;
	this->m_read >> number;
	if (m_read.eof())
		return;
	m_height = std::stoi(number);
	m_read >> number;
	m_width = std::stoi(number);
	m_read.ignore();

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
void Board::drawBoard(sf::RenderWindow& window)
{
	for (int i = 0; i < m_staticObj.size(); i++)
	{
		if (m_staticObj[i] != nullptr)
			m_staticObj[i]->draw(window);
	}
	// throw if we dont have prince
	m_prince->draw(window);

	for(int index = 0 ; index < m_keyMonster.size(); index ++)
		m_keyMonster[index]->draw(window);
	
	for (int index = 0; index < m_ballMonster.size(); index++)
		m_ballMonster[index]->draw(window);
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
	default:
		m_staticObj.push_back(selectGiftType(position,c));
		break;
	}
}

void Board::createMovingObject(char c, sf::Vector2f position)
{
	switch (c)
	{
	case PRINCE_C:
		m_prince = std::make_unique<Prince>(PRINCE, position);
		m_initailPrince = position;
		break;
	case KEYMONSTER_C:
		m_keyMonster.push_back(std::make_unique<KeyMonster>(KEYMONSTER, position));
		break;
	case BALLMONSTER_C:
		m_ballMonster.push_back(std::make_unique<BallMonster>(BALLMONSTER, position));
		break;
	}
}




void Board::checkCollision(MovingObject& thisObj, GameController& game)
{
	m_erased = false;
	for (auto& unmovable : m_staticObj)
	{
		if(!m_erased)
			if (unmovable != nullptr && thisObj.collidesWith(*unmovable))
				thisObj.handleCollision(*unmovable, game);
	}

}

std::unique_ptr<Gift> Board::selectGiftType(sf::Vector2f position,const char c)
{
	switch (c)
	{
	case GIFT_C:
		return std::make_unique <IncreasingTime>(INCREASETIME, position);

	case ADDLIFE_C:
		return std::make_unique <AddLife>(ADDLIFE, position);
	}
}

void Board::eraseStaticObject(StaticObject& staticObj)
{
	auto staticPtr = m_staticObj.begin();
	for (; staticPtr != m_staticObj.end(); staticPtr++)
	{
		if ((*staticPtr)->getposition() == staticObj.getposition())
		{
			m_staticObj.erase(staticPtr);
			m_erased = true;
			return;
		}
	}
}

sf::Vector2f Board::getiInitailPrincePos() const
{
	return m_initailPrince;
}
