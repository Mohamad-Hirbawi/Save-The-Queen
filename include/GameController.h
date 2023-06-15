#pragma once
#include "Macros.h"
#include "Menu.h"
#include "Board.h"
#include "Caption.h"

#include <SFML/Graphics.hpp>

class GameController
{
public:
	GameController() {}

	void run();
	void creatObject();
	void increaseScore(const int number);
	void increaseTime();
	void addLife();

	void eraseStaticObject(StaticObject& staticObj);
	void did();
private:
	sf::Sprite m_gameWallp;
	sf::Clock m_timer;

	sf::Sprite m_backgroundSprite;

	bool isStaticObj(char c);
	void move(sf::Time deltaTime);
	sf::Texture m_pTexture;
	void checkCollision(MovingObject& thisObj);

	Caption m_caption;
	Menu m_menu;
	Board m_board;

};
