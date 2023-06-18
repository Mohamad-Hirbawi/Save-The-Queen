#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "Wall.h"
#include "Door.h"
#include "Stair.h"
#include "Prince.h"
#include "KeyMonster.h"
#include "BallMonster.h"
#include <Gift.h>
#include <IncreasingTime.h>
#include <AddLife.h>
#include "Coin.h"
#include "StaticObject.h"
#include <SFML/System/Vector2.hpp>

class Board
{
public:
	Board();
	//~Board() = default;
	std::vector<std::string> getMap() const;
	int getHeight()const;
	int getWidth()const;
	void drawBoard(sf::RenderWindow& window);
	void createStaticObject(char c, sf::Vector2f position);
	void createMovingObject(char c, sf::Vector2f position);


	void checkCollision(MovingObject& thisObj, GameController& game);
	void eraseStaticObject(StaticObject& staticObj);
	sf::Vector2f getiInitailPrincePos()const;

	std::unique_ptr<Prince> m_prince;
	std::vector<std::unique_ptr<BallMonster>> m_ballMonster;
	std::vector<std::unique_ptr<KeyMonster>> m_keyMonster;

private:
	bool readLvlMap();
	void readLvlSize();
	std::unique_ptr<Gift> selectGiftType(sf::Vector2f position, const char c);
	std::ifstream m_read;
	std::vector<std::string> m_map;
	int m_height;
	int m_width;
	sf::Vector2f m_initailPrince;

	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	bool m_erased;
	//Prince m_prince;
};

