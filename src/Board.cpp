﻿#include "Board.h"
#include <GameController.h>

Board::Board()
{
	// throw
	m_read.open("board.txt", std::ios_base::in);
	readLvlMap();
}


bool Board::readLvlMap() {
	readLvlSize();

	if (this->m_read.eof())		return false;

	auto line = std::string();
	for (int row = 0; row < m_height; row++){
		getline(m_read, line);
		m_map.emplace_back(line);
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
{return m_map;}

int Board::getHeight() const
{return m_height;}

int Board::getWidth() const
{return m_width;}

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
	m_beastMonster->draw(window);
	drawObjects(m_keyMonster, window);
	drawObjects(m_ballMonster, window);
	drawObjects(m_bullet, window);
}

void Board::createStaticObject(const char &c, sf::Vector2f position)
{
	switch (c){
	case WALL_C:	m_staticObj.emplace_back(std::make_unique<Wall>(WALL, position));	break;
	
	case STAIR_C:	m_staticObj.emplace_back(std::make_unique<Stair>(STAIR, position));	break;

	case COIN_C:	m_staticObj.emplace_back(std::make_unique<Coin>(COIN, position));	break;

	case DDOR_C:	m_staticObj.emplace_back(std::make_unique<Door>(DOOR, position));	break;

	default:		m_staticObj.emplace_back(selectGiftType(position,c));				break;
	}
}

void Board::createMovingObject(const char & c, sf::Vector2f position)
{
	switch (c)
	{
	case PRINCE_C: m_prince = std::make_unique<Prince>(PRINCE, position); m_initailPrince = position;	break;

	case KEYMONSTER_C: m_keyMonster.emplace_back(std::make_unique<KeyMonster>(KEYMONSTER, position));	break;
	
	case BALLMONSTER_C: m_ballMonster.emplace_back(std::make_unique<BallMonster>(BALLMONSTER, position));	break;
	
	case BEASTMONSTER_C: m_beastMonster = std::make_unique<BeastMonster>(BEASTMONSTER, position); break;
	case BULLET_C:	m_bullet.emplace_back(selectBulltType(position));
		break;
	}
}

// template
void Board::checkCollision(MovingObject& thisObj, GameController& game)
{
	if (game.isLosing())
		return;
	m_erased = false;
	for (auto& unmovable : m_staticObj){
		if(!m_erased)
			if (unmovable != nullptr && thisObj.collidesWith(*unmovable))
				thisObj.handleCollision(*unmovable, game);
	}

}

void Board::checkCollisionMoving(MovingObject& thisObj, GameController& game)
{
	if (game.isLosing())
		return;
	m_erased = false;
	for (auto& unmovable : m_keyMonster){
		if(!m_erased)
			if (unmovable != nullptr && thisObj.collidesWith(*unmovable))
				thisObj.handleCollision(*unmovable, game);
	}

}

std::unique_ptr<Gift> Board::selectGiftType(sf::Vector2f position,const char& c)
{
	switch (c)
	{
	case GIFT_C:	return std::make_unique <IncreasingTime>(INCREASETIME, position);

	case ADDLIFE_C:	return std::make_unique <AddLife>(ADDLIFE, position);
	
	case  GIFTBULLET_C: return std::make_unique <GiftBuleet>(GIFTBULLET, position);
	default:
		;

	}
}

std::unique_ptr<Bullet> Board::selectBulltType(sf::Vector2f position)
{
	sf::Vector2f princePos = m_prince->getposition();
	if (position == RIGHT)
		princePos.x += 50;
	else
		princePos.x -= 25;
		
	return std::make_unique<Bullet>(BULLET, princePos, position);

}

void Board::eraseStaticObject(StaticObject& staticObj)
{
	auto staticPtr = m_staticObj.begin();
	for (; staticPtr != m_staticObj.end(); staticPtr++)
	{
		if ((*staticPtr)->getposition() == staticObj.getposition()){
			m_staticObj.erase(staticPtr);
			m_erased = true;	return;
		}
	}
}

sf::Vector2f Board::getiInitailPrincePos() const
{
	return m_initailPrince;
}

bool Board::eraseMoving(MovingObject& movingObject, Toolbar_t typeVector)
{
	switch (typeVector)
	{
	case KEYMONSTER:
		return eraseMovingObject(movingObject, m_keyMonster);
	case BALLMONSTER:
		return eraseMovingObject(movingObject, m_ballMonster);
	case BULLET:
		return eraseMovingObject(movingObject, m_bullet);
	default:
		break;
	}//throw
	return eraseMovingObject(movingObject, m_bullet);

}

void Board::clearBoard()
{
	m_prince.reset();
	m_ballMonster.clear();
	m_keyMonster.clear();
	m_staticObj.clear();
	m_initailPrince = sf::Vector2f(0, 0);
}
