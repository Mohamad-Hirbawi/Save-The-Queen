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
#include "Bullet.h"
#include <Gift.h>
#include <IncreasingTime.h>
#include <AddLife.h>
#include <GiftBuleet.h>
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
	void createStaticObject(const char &c, sf::Vector2f position);
	void createMovingObject(const char &c, sf::Vector2f position);


	void checkCollision(MovingObject& thisObj, GameController& game);
	void eraseStaticObject(StaticObject& staticObj);
	//void eraseMovingObject(Bullet& );
	//void eraseMovingObject(Bullet& movingObject, const std::vector <std::unique_ptr<Bullet>> &vec);
	sf::Vector2f getiInitailPrincePos()const;
	bool eraseMoving(MovingObject& movingObject);
	void clearBoard();
	std::unique_ptr<Prince> m_prince;
	std::vector<std::unique_ptr<BallMonster>> m_ballMonster;
	std::vector<std::unique_ptr<KeyMonster>> m_keyMonster;
	std::vector <std ::unique_ptr<Bullet>> m_bullet;
	//std::vector < std::unique_ptr<Bullet>>m_giftBullet;
	bool m_erased;

private:
	bool readLvlMap();
	void readLvlSize();
	std::unique_ptr<Gift> selectGiftType(sf::Vector2f position, const char& c);
	std::unique_ptr<Bullet> selectBulltType(sf::Vector2f position);
	std::ifstream m_read;
	std::vector<std::string> m_map;
	int m_height;
	int m_width;
	sf::Vector2f m_initailPrince;

	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	//Prince m_prince;
};


template<typename T>
void drawObjects(const std::vector<std::unique_ptr<T>>& objects, sf::RenderWindow& window)
{
	for (int index = 0; index < objects.size(); index++)
	{
		objects[index]->draw(window);
	}
}

template<typename T1, typename T2 >
bool  eraseMovingObject(T1& object ,  std::vector<std::unique_ptr<T2>> &vec) {

	auto movingPtr = vec.begin();
	for (; movingPtr != vec.end(); movingPtr++)
	{
		if ((*movingPtr)->getposition() == object.getposition()) {
			vec.erase(movingPtr);
			return true; 
			//m_erased = true;	return;
		}
	}
	return false;

	
}