#include "GameController.h"
#include <iostream>

GameController::GameController():m_finishGame(false)
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Titlebar | sf::Style::Close);
}

void GameController::run() {
	m_finishGame = false;
	//m_sound.playMusic("menuMusic.ogg");
	m_sound.playMusic("Luchando En El Peligro 2.0.ogg");
	m_menu.activateMenu(window);
	m_caption.resetartCaptions();
	creatObject();
	m_timer.restart();
	m_view = window.getView();
	
	while (window.isOpen() && !m_finishGame) {
		window.clear();
		window.draw(m_gameWallp);
		m_board.drawBoard(window);
		m_caption.drawCaptions(window);

		for (auto evnt = sf::Event(); window.pollEvent(evnt); ){
			switch (evnt.type)
			{case sf::Event::Closed:		window.close();		break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Escape) { window.close(); break; }
				else if (evnt.key.code == sf::Keyboard::X && m_caption.getBullet() > 0)
				{
					creatBullet(m_lastPrinceDirection,PRINCE);	m_caption.dicreaseBullet();
				}
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
	playerPosX = viewX = m_board.getPrince()->getposition().x;
	playerPosY = viewY = m_board.getPrince()->getposition().y;

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
	if (!m_pTexture.loadFromFile("Background1.jpg"))
		throw std::runtime_error("Failed to load the texture");
	m_gameWallp.setTexture(m_pTexture);
	m_gameWallp.setScale(0.5, 0.5);
	std::vector<std::string> boadrdmap = m_board.getMap();
	sf::Vector2f position;
	float xLoc, yLoc;
	char c;
	for (int row = 0; row < m_board.getHeight(); row++)
	{
		for (int col = 0; col < m_board.getWidth(); col++){
			xLoc = float (50 * col);
			yLoc = float (50 * row);
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
		c == GIFTBULLET_C || c== KEY_C || c == GATE_C)
		return true;
	return false;

}

void GameController::move(sf::Time deltaTime)
{
	m_board.getPrince()->move(deltaTime, m_board.getPrince().get()->getposition(), *this);

	m_lastPrinceDirection = m_board.getPrince()->m_dirPrince;

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

// we have a problem with MovingObject position without the prince;
void GameController::dead(){
	m_caption.dicreaseLife();
	if (m_caption.getLife() > 0)
	{
		printMsg("You have " + std::to_string(m_caption.getLife()) + " lives left before losing");
		m_caption.newLevel(TIMEOFGAME);
		std::unique_ptr<Prince> help = std::make_unique<Prince>(PRINCE, m_board.getiInitailPrincePos());
		m_board.getPrince() = std::move(help);
		m_board.getBullet().clear();
		

	}
	else		losing();

}

void GameController::losing()
{
	finishGame("Game over!");
}

bool GameController::haveKey()
{return m_caption.haveKey();}

bool GameController::isLosing()
{return m_finishGame;}

void GameController::increaseBullet()
{m_caption.increaseBullet();}

void GameController::dicreaseCoin()
{
	m_caption.UpdateNumCoin(-1);
}
bool GameController::chekCoin() {

	return m_caption.checkEmptyCoin();
}
void GameController::playSound(const int& place) {

	m_sound.playSound(place);
}

void GameController::creatBullet(sf::Vector2f direction, Toolbar_t type)
{
	m_board.setTypeBullet(type);
	m_board.createMovingObject(BULLET_C, direction);

}

void GameController::newLevel()
{
	m_board.clearBoard();
	m_board.resetLevelMap();
	if (!m_board.readLvlMap()) // last level  
		win();

	else {
		m_sound.playSound(winGameSound);
		printMsg("Next level");
		m_caption.resetartCaptions();
		creatObject();
	}



}

void GameController::printMsg(std::string msg)
{
	sf::Font font;
	font.loadFromFile("SundayMorning.ttf");

	sf::Text text(msg, font, 50);
	text.setPosition((WINDOW_WIDTH - text.getLocalBounds().width) / 2, (WINDOW_HEIGHT - text.getLocalBounds().height) / 2);

	window.clear();
	window.draw(text);
	window.display();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	
}
void GameController::finishGame(std::string msg)
{
	printMsg(msg);
	window.close();
	m_finishGame = true;
}

void GameController::win()
{
	m_sound.playSound(GameWin);
	finishGame("You win");
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

	collideAndProcessPairs(m_board.getKeyMonster(), m_board.getStatic(),* this);
	collideAndProcessPairs(m_board.getBullet(), m_board.getStatic(), *this);
	collideAndProcessPairs(m_board.getKeyMonster(), m_board.getBullet(), *this);
	collideAndProcessPairs(m_board.getBallMonster(), m_board.getStatic(), *this);
	collideAndProcessPairs(m_board.getBallMonster(), m_board.getBullet(), *this);
	collideAndProcessPairs(m_board.getBeastMonster(), m_board.getStatic(), *this);
	collideAndProcessPairs(m_board.getBeastMonster(), m_board.getBullet(), *this);

	collideAndProcessOnePair(m_board.getStatic(), m_board.getPrince().get(), *this);
	collideAndProcessOnePair(m_board.getKeyMonster(), m_board.getPrince().get(), *this);
	collideAndProcessOnePair(m_board.getBallMonster(), m_board.getPrince().get(), *this);
	collideAndProcessOnePair(m_board.getBeastMonster(), m_board.getPrince().get(), *this);
	collideAndProcessOnePair(m_board.getBullet(), m_board.getPrince().get(), *this);


}


