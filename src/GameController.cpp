#include "GameController.h"
#include <iostream>

void GameController::run() {
	m_lose = false;
	m_menu.activateMenu(window);
	creatObject();
	m_caption.resetartCaptions();
	m_timer.restart();


	while (window.isOpen()) {
		window.clear();
		window.draw(m_gameWallp);
		m_board.drawBoard(window);
		m_caption.drawCaptions(window);

		for (auto evnt = sf::Event(); window.pollEvent(evnt); ){
			switch (evnt.type)
			{case sf::Event::Closed:		window.close();		break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Escape) { window.close(); break; }
				else if (evnt.key.code == sf::Keyboard::X)
					addBullet(m_timer.restart());
			default:	break;
			}
		}
		move(m_timer.restart());
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			 we need to add func that check with wich object the bukket coolis
			m_board.createMovingObject('b', m_board.m_prince->getposition());
		}*/
		window.display();
	}

}

void GameController::creatObject() 
{
	// חריגה
	if (!m_pTexture.loadFromFile("Background1.jpg"))
		;
	m_gameWallp.setTexture(m_pTexture);
	m_gameWallp.setScale(0.5, 0.5);
	std::vector<std::string> boadrdmap = m_board.getMap();
	sf::Vector2f position;
	float xLoc, yLoc;
	char c;
	for (int row = 0; row < m_board.getHeight(); row++)
	{
		for (int col = 0; col < m_board.getWidth(); col++){
			xLoc = 50 * col;
			yLoc = 50 * row;
			position = { xLoc, yLoc };
			c = boadrdmap[row][col];
			if (c == ' ')	continue;
			//static object 
			if (isStaticObj(c)) m_board.createStaticObject(c, position);
			//moving object
			else   m_board.createMovingObject(c, position);
		}
	}
}

bool GameController::isStaticObj(char c)
{
	if (c == WALL_C || c == STAIR_C || c == COIN_C || c == GIFT_C || c == ADDLIFE_C || c== DDOR_C)
		return true;
	return false;

}

void GameController::move(sf::Time deltaTime)
{
	m_board.m_prince->move(deltaTime, m_board.m_prince.get()->getposition());

	checkCollision(*m_board.m_prince);

	for (int index = 0; index < m_board.m_keyMonster.size(); index++){
		m_board.m_keyMonster[index]->move(deltaTime, m_board.m_prince.get()->getposition());
		checkCollision(*m_board.m_keyMonster[index]);
	}
}


void GameController::checkCollision(MovingObject& thisObj)
{
	if (thisObj.collidesWith(*m_board.m_prince))
		thisObj.handleCollision(*m_board.m_prince, *this);
	m_board.checkCollision(thisObj, *this); //check collisions with static objects
}

void GameController::increaseScore(const int number)
{m_caption.increaseScore(number);}

void GameController::increaseTime()
{m_caption.updateTime(BOUNUSTIME);}

void GameController::addLife()
{m_caption.increaseLife();}


void GameController::addBullet(sf::Time deltaTime) {
	if (m_caption.getBullet() > 0){
		m_board.createMovingObject('b', m_board.m_prince->getposition());
		m_board.m_bullet->move(deltaTime, m_board.m_prince.get()->getposition());
	}
}
void GameController::eraseStaticObject(StaticObject& staticObj)
{m_board.eraseStaticObject(staticObj);}

void GameController::did(){
	m_caption.dicreaseLife();
	if (m_caption.getLife() > 0)
	{
		std::unique_ptr<Prince> help = std::make_unique<Prince>(PRINCE, m_board.getiInitailPrincePos());
		m_board.m_prince = std::move(help);
	}
	else
	{
		losing();
		//return EXIT_SUCCESS;
	}
}

void GameController::losing()
{
	window.clear();
	m_board.clearBoard();
	run();
	m_lose = true;
}

bool GameController::haveKey()
{
	return m_caption.haveKey();
}

bool GameController::isLosing()
{
	return m_lose;
}

void GameController::increaseBullet()
{
	m_caption.increaseBullet();
}
