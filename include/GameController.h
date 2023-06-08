#pragma once
#include "Macros.h"
#include "Menu.h"
#include "Board.h"

#include <SFML/Graphics.hpp>

class GameController
{
public:
	GameController() {}
	~GameController() {}

	void run();
	void creatObject();
private:
	sf::Sprite m_gameWallp;
	sf::Clock m_timer;

	sf::Sprite m_backgroundSprite;
	Menu m_menu;
	Board m_board;
	bool isStaticObj(char c);
	void move(sf::Time deltaTime);
	sf::Texture m_pTexture;
	void checkCollision(MovingObject& thisObj, sf::Time deltaTime);


};
