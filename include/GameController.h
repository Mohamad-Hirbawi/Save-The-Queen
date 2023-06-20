#pragma once
#include "Macros.h"
#include "Menu.h"
#include "Board.h"
#include "Caption.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>



class Bullet;
class GameController
{
public:
	GameController()
	{
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Titlebar | sf::Style::Close);
	}

	void run();
	void creatObject();
	void increaseScore(const int number);
	void increaseTime();
	void addLife();
	void setLastDirection(sf::Vector2f direction);

	void eraseStaticObject(StaticObject& staticObj);
	void eraseMovingObject(MovingObject& movingObject, Toolbar_t  /*,const std::vector <std::unique_ptr<MovingObject>> &vector*/);
	void dead();
	//std::vector <std::unique_ptr<Bullet>> getBuelltVector();
	void increaseBullet();
	bool haveKey();
	bool isLosing();
  
private:
	sf::Vector2f m_lastPrinceDirection;
	sf::RenderWindow window;
	sf::Sprite m_gameWallp;
	sf::Clock m_timer;
	void creatBullet();

	sf::Sprite m_backgroundSprite;
	void losing();
	bool isStaticObj(const char &c);
	bool m_lose;
	void move(sf::Time deltaTime);
	sf::Texture m_pTexture;
	void checkCollision(MovingObject& thisObj);

	Caption m_caption;
	Menu m_menu;
	Board m_board;

};
//template<typename T>
//void templateMove(const std::vector<std::unique_ptr<T>>& movigObjects, sf::Time deltaTime, const int & index) {
//
//	movigObjects[index]->move(deltaTime, movigObjects->getposition());
//	//m_board.m_keyMonster[index]->move(deltaTime, m_board.m_prince.get()->getposition());
//
//
//}