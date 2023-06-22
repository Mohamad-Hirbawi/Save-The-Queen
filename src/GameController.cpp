#include "GameController.h"
#include <iostream>

GameController::GameController()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Titlebar | sf::Style::Close);
}

void GameController::run() {
	m_lose = false;
	m_menu.activateMenu(window);
	creatObject();
	m_caption.resetartCaptions();
	m_timer.restart();
	m_view = window.getView();
	
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
		//updateView();
		window.display();
	}

}

void GameController::updateView() 
{
	float playerPosX,
		playerPosY,
		viewX,
		viewY;

	sf::View view = window.getView();
	playerPosX = viewX = m_board.m_prince->getposition().x;
	playerPosY = viewY = m_board.m_prince->getposition().y;

	if (playerPosX > WINDOW_WIDTH - VIEWSIZE / 2)
		viewX = WINDOW_WIDTH - VIEWSIZE / 2;
	else if (playerPosX < VIEWSIZE / 2)
		viewX = VIEWSIZE / 2;

	if (playerPosY < WINDOW_HEIGHT / 2)
		viewY = VIEWSIZE / 2;
	else if (playerPosY > WINDOW_HEIGHT - VIEWSIZE / 2)
		viewY = WINDOW_HEIGHT - VIEWSIZE / 2;

	view.setSize(VIEWSIZE, VIEWSIZE);
	view.setCenter(viewX, viewY);
	window.setView(view);
	
}
void GameController::creatObject() 
{
	// throw
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
			if (c == EMPTY_C)	continue;
			if (c == COIN_C)
				m_caption.UpdateNumCoin(1);
			//static object 
			if (isStaticObj(c)) m_board.createStaticObject(c, position);
			//moving object
			else   m_board.createMovingObject(c, position);
		}
	}
}

bool GameController::isStaticObj(const char& c)
{
	if (c == WALL_C || c == STAIR_C || c == COIN_C || c == ADDTIME_C || c == ADDLIFE_C || c== DDOR_C ||
		c == GIFTBULLET_C || c== KEY_C)
		return true;
	return false;

}

void GameController::move(sf::Time deltaTime)
{
	m_board.m_prince->move(deltaTime, m_board.m_prince.get()->getposition());

	if(m_board.m_beastMonster)
		m_board.m_beastMonster->move(deltaTime, m_board.m_prince.get()->getposition());
	m_lastPrinceDirection = m_board.m_prince->m_dirPrince;

	//m_board.m_queen->move(deltaTime, m_board.m_prince.get()->getposition());
	m_board.move(deltaTime, *this);
}

void GameController::increaseScore(const int number)
{m_caption.increaseScore(number);}

void GameController::increaseTime()
{m_caption.updateTime(BOUNUSTIME);}

void GameController::increaseKey()
{m_caption.increaseKey();}

void GameController::addLife()
{m_caption.increaseLife();}

void GameController::setLastDirection(sf::Vector2f direction)
{
	m_lastPrinceDirection = direction;
}

void GameController::eraseObject(Object& movingObject , Toolbar_t typeVector )
{
	m_board.setErased(m_board.erase(movingObject, typeVector));
}
bool GameController::ifErased()
{
	return m_board.getErased();
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
	window.setView(m_view);
	run();
	m_lose = true;
}

bool GameController::haveKey()
{return m_caption.haveKey();}

bool GameController::isLosing()
{return m_lose;}

void GameController::increaseBullet()
{m_caption.increaseBullet();}

void GameController::dicreaseCoin()
{
	m_caption.UpdateNumCoin(-1);
}

void GameController::creatBullet() 
{
	m_board.createMovingObject(BULLET_C, m_lastPrinceDirection);
	m_caption.dicreaseBullet();
}

void GameController::creatKey(sf::Vector2f posotion)
{
	m_board.createStaticObject(KEY_C, posotion);
}

bool GameController::collide(Object& obj1, Object& obj2)
{
	return obj1.collidesWith(obj2);
}

void GameController::checkCollis()
{
	m_board.setErased(false);

	collideAndProcessPairs(m_board.m_keyMonster, m_board.m_staticObj ,* this);
	collideAndProcessPairs(m_board.m_bullet, m_board.m_staticObj, *this);
	collideAndProcessPairs(m_board.m_keyMonster, m_board.m_bullet, *this);
	collideAndProcessPairs(m_board.m_ballMonster, m_board.m_staticObj, *this);
	collideAndProcessPairs(m_board.m_ballMonster, m_board.m_bullet, *this);

	collideAndProcessOnePair(m_board.m_staticObj, m_board.m_prince.get(), *this);
	collideAndProcessOnePair(m_board.m_keyMonster, m_board.m_prince.get(), *this);
	collideAndProcessOnePair(m_board.m_ballMonster, m_board.m_prince.get(), *this);
	collideAndProcessOnePair(m_board.m_bullet, m_board.m_prince.get(), *this);
}


