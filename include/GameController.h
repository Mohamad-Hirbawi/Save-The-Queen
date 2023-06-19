#pragma once
#include "Macros.h"
#include "Menu.h"
#include "Board.h"
#include "Caption.h"

#include <SFML/Graphics.hpp>

class GameController
{
public:
	GameController(){
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Titlebar | sf::Style::Close);
	}

	void run();
	void creatObject();
	void increaseScore(const int number);
	void increaseTime();
	void addLife();

	void eraseStaticObject(StaticObject& staticObj);
	void did();
	bool haveKey();
	bool isLosing();
private:
	sf::RenderWindow window;
	sf::Sprite m_gameWallp;
	sf::Clock m_timer;

	sf::Sprite m_backgroundSprite;
	void losing();
	bool isStaticObj(char c);
	bool m_lose;
	void move(sf::Time deltaTime);
	sf::Texture m_pTexture;
	void checkCollision(MovingObject& thisObj);

	Caption m_caption;
	Menu m_menu;
	Board m_board;

};
