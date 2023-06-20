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
				else if (evnt.key.code == sf::Keyboard::X && m_caption.getBullet() > 0)		creatBullet();
			default:	break;
			}
		}
		if (m_caption.getTime() <= 0)		dead();

		move(m_timer.restart());
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

bool GameController::isStaticObj(const char& c)
{
	if (c == WALL_C || c == STAIR_C || c == COIN_C || c == GIFT_C || c == ADDLIFE_C || c== DDOR_C ||
		c == GIFTBULLET_C)
		return true;
	return false;

}

void GameController::move(sf::Time deltaTime)
{

	m_board.m_prince->move(deltaTime, m_board.m_prince.get()->getposition());
	m_board.m_beastMonster->move(deltaTime, m_board.m_prince.get()->getposition());
	m_lastPrinceDirection = m_board.m_prince->m_dirPrince;

	checkCollision(*m_board.m_prince);

	//m_board.m_prince->move(deltaTime, m_board.m_prince->getposition());

	for (int index = 0; index < m_board.m_keyMonster.size(); index++){
		m_board.m_keyMonster[index]->move(deltaTime, m_board.m_prince.get()->getposition());
		checkCollision(*m_board.m_keyMonster[index]);
	
		//templateMove(m_board.m_keyMonster, deltaTime ,index);
		//m_board.m_keyMonster[index]->move(deltaTime, m_board.m_prince->getposition());

	}
	for (int i = 0; i < m_board.m_bullet.size(); i++)
		m_board.m_bullet[i]->move(deltaTime, m_board.m_prince.get()->getposition());

	for (int i = 0; i < m_board.m_ballMonster.size(); i++)
		m_board.m_ballMonster[i]->move(deltaTime,m_board.m_prince->getposition());

		//templateMove(m_board.m_bullet, deltaTime, i);
	//m_board.m_bullet[i]->move(deltaTime, m_board.m_prince->getposition());



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

void GameController::setLastDirection(sf::Vector2f direction)
{
	m_lastPrinceDirection = direction;
}


void GameController::eraseStaticObject(StaticObject& staticObj)
{m_board.eraseStaticObject(staticObj);}

void GameController::dead(){
	m_caption.dicreaseLife();
	if (m_caption.getLife() > 0)
	{
		m_caption.newLevel(TIMEOFGAME);
		std::unique_ptr<Prince> help = std::make_unique<Prince>(PRINCE, m_board.getiInitailPrincePos());
		m_board.m_prince = std::move(help);
	}
	else		losing();

}

void GameController::losing()
{
	window.clear();
	m_board.clearBoard();
	run();
	m_lose = true;
}

bool GameController::haveKey()
{return m_caption.haveKey();}

bool GameController::isLosing()
{return m_lose;}

void GameController::increaseBullet()
{m_caption.increaseBullet();}

void GameController::creatBullet() 

{m_board.createMovingObject('b', m_lastPrinceDirection);
m_caption.dicreaseBullet();

}

