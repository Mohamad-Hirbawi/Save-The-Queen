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
	~GameController() {}

	void run();
	void creatObject();
	void ChangeStaticObj(Toolbar_t type, sf::Vector2f position);
	void increaseScore(const int number);

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

	Caption m_caption;

};
