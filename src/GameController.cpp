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
		checkCollis();
		m_view = window.getView();
		//updateView();
		window.display();
	}

}

void GameController::updateView() {


	sf::View view = window.getView();
	m_playerPosX = m_viewX = m_board.m_prince->getposition().x;
	m_playerPosY = m_viewY = m_board.m_prince->getposition().y;

	if (m_playerPosX > WINDOW_WIDTH - VIEWSIZE / 2)
		m_viewX = WINDOW_WIDTH - VIEWSIZE / 2;
	else if (m_playerPosX < VIEWSIZE / 2)
		m_viewX = VIEWSIZE / 2;

	if (m_playerPosY < WINDOW_HEIGHT / 2)
		m_viewY = VIEWSIZE / 2;
	else if (m_playerPosY > WINDOW_HEIGHT - VIEWSIZE / 2)
		m_viewY = WINDOW_HEIGHT - VIEWSIZE / 2;

	view.setSize(VIEWSIZE, VIEWSIZE);
	view.setCenter(m_viewX, m_viewY);
	window.setView(view);
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
	checkCollision(*m_board.m_prince);

	if(m_board.m_beastMonster)
		m_board.m_beastMonster->move(deltaTime, m_board.m_prince.get()->getposition());
	m_lastPrinceDirection = m_board.m_prince->m_dirPrince;

	m_board.move(deltaTime, *this);
}


void GameController::checkCollision(MovingObject& thisObj)
{
	m_board.checkCollision(thisObj, *this); //check collisions with static objects

	//if (thisObj.collidesWith(*m_board.m_prince))
	//	thisObj.handleCollision(*m_board.m_prince, *this);
	

	//m_board.checkCollisionMoving(thisObj, *this);

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

void GameController::eraseObject(Object& movingObject , Toolbar_t typeVector )
{
	m_board.m_erased = m_board.eraseMoving(movingObject, typeVector);
}
bool GameController::ifErased()
{
	return m_board.m_erased;
}


void GameController::dead(){
	m_caption.dicreaseLife();
	if (m_caption.getLife() > 0)
	{
		m_caption.newLevel(TIMEOFGAME);
		std::unique_ptr<Prince> help = std::make_unique<Prince>(PRINCE, m_board.getiInitailPrincePos());
		m_board.m_prince = std::move(help);
		m_board.m_bullet.clear();

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

void GameController::checkCollis()
{
	for_each_pair(m_board.m_keyMonster.begin(), m_board.m_keyMonster.end(),
		m_board.m_staticObj.begin(),m_board.m_staticObj.end(),*this, [this](auto& a, auto& b)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b,*this);
			}
		});
	
	for_each_pair(m_board.m_bullet.begin(), m_board.m_bullet.end(),
		m_board.m_staticObj.begin(),m_board.m_staticObj.end(), *this, [this](auto& a, auto& b)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b, *this);
			}
		});	

	for_each_pair(m_board.m_keyMonster.begin(), m_board.m_keyMonster.end(),
		m_board.m_bullet.begin(), m_board.m_bullet.end(), *this, [this](auto& a, auto& b)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b, *this);
			}
		});
	
	for_each_pair(m_board.m_ballMonster.begin(), m_board.m_ballMonster.end(),
		m_board.m_staticObj.begin(),m_board.m_staticObj.end(), *this, [this](auto& a, auto& b)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b, *this);
			}
		});
	if (ifErased())
		return;


	for_each_pair(m_board.m_ballMonster.begin(), m_board.m_ballMonster.end(),
		m_board.m_bullet.begin(),m_board.m_bullet.end(), *this, [this](auto& a, auto& b)
		{
			if (collide(*a, *b))
			{
				processCollision(*a, *b, *this);
			}
		});	if (ifErased())
			return;
	for_one_pair(m_board.m_keyMonster.begin(), m_board.m_keyMonster.end(),
	*m_board.m_prince.get(), *this,
	[this](auto& a, auto& b)
	{
		if (collide(*a, b))
		{
			processCollision(*a, b, *this);

		}
	});	if (ifErased())
		return;
for_one_pair(m_board.m_bullet.begin(), m_board.m_bullet.end(),
	*m_board.m_prince.get(), *this,
	[this](auto& a, auto& b)
	{
		if (collide(*a, b))
		{
			processCollision(*a, b, *this);

		}
	});	if (ifErased())
		return;

//for_one_pair(m_board.m_staticObj.begin(), m_board.m_staticObj.end(),
//	*m_board.m_prince.get(),*this,
//	[this](auto& a, auto& b)
//	{
//		if (collide(*a, b))
//		{
//			processCollision(*a, b, *this);

//		}
//	});

}


bool GameController::collide(Object& obj1, Object& obj2)
{
	return obj1.collidesWith(obj2);
}