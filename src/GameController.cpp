#include "GameController.h"
#include <iostream>

void GameController::run() {

	auto window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Titlebar | sf::Style::Close);
	m_menu.activateMenu(window);
	creatObject();
	m_timer.restart();
	m_caption.resetartCaptions();

	while (window.isOpen()) {
		window.clear();
		window.draw(m_gameWallp);
		m_board.drawBoard(window);
		m_caption.drawCaptions(window);

		for (auto evnt = sf::Event(); window.pollEvent(evnt); )
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Escape)
				{
					window.close();
					break;
				}


			default:
				break;
			}
		}

		move(m_timer.restart());
		window.display();

	}
}

void GameController::creatObject() {
	//m_pTexture.loadFromFile("wall1.jpg");
	//m_sprite.setTexture(m_pTexture);
	//m_sprite.setScale(1.2, 1.3);
	//m_cake = 0;

	if (!m_pTexture.loadFromFile("Background1.jpg"))
		std::cout << "wrong";
	m_gameWallp.setTexture(m_pTexture);
	m_gameWallp.setScale(0.5, 0.5);
	std::cout << "true";


	std::vector<std::string> boadrdmap = m_board.getMap();
	sf::Vector2f position;
	float xLoc, yLoc;

	for (int row = 0; row < m_board.getHeight(); row++)
	{
		for (int col = 0; col < m_board.getWidth(); col++)
		{

			xLoc = 50 * col;

			yLoc = 50 * row;
			position = { xLoc, yLoc };


			char c = boadrdmap[row][col];
			if (c == ' ')
				continue;

			if (isStaticObj(c)) //static object
			{
				m_board.createStaticObject(c, position);
			}
			else   //moving object
			{
				m_board.createMovingObject(c, position);

				//	std::unique_ptr<MovingObject> movable = createMovingObject(c, position);
				//	if (c != SHADOW_C)
				//	{
				//		m_pacman.push_back(std::move(movable));
				//		m_initailPacmanLocation = position;
				//	}
				//	else
				//	{
				//		m_shadow.push_back(std::move(movable));
				//		m_initailShadowsLocation.push_back(position);
				//	}
			}
		}
	}


}

bool GameController::isStaticObj(char c)
{
	if (c == WALL_C || c == STAIR_C || c == COIN_C)
		return true;
	return false;

}

void GameController::move(sf::Time deltaTime)
{

	m_board.m_prince->move(deltaTime);
	checkCollision(*m_board.m_prince, m_timer.restart());


}

void GameController::checkCollision(MovingObject& thisObj, sf::Time deltaTime)
{
	m_board.checkCollision(thisObj, *this, deltaTime); //check collisions with static objects

}

void GameController::ChangeStaticObj(Toolbar_t type, sf::Vector2f position)
{
	m_board.changeStatic(type, position);

}

void GameController::increaseScore(const int number)
{
	m_caption.increaseScore(number);
}