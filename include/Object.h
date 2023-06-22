#pragma once 
#include "Macros.h"
#include "Textures.h"
#include <SFML/Graphics.hpp>

class GameController;//
class Prince;
class Queen;
class Wall;
class Stair;
class Coin;
class Door;
class KeyMonster;
class BallMonster;
class BeastMonster;
class Bullet;
class Gift;

class Object
{
public:	

	Object();
	Object(Toolbar_t symbol, sf::Vector2f position);
	void draw(sf::RenderWindow&);

	bool collidesWith(const Object& obj) const;
	sf::Vector2f getposition()const;
	sf::Vector2f getprevPos()const;
	void moveToPrevPos();
	virtual void handleCollision(Object&, GameController&) = 0;
	virtual void handleCollision(Prince&, GameController&) = 0;
	virtual void handleCollision(Queen&, GameController&) = 0;
	virtual void handleCollision(Wall&, GameController&) = 0;
	virtual void handleCollision(Stair&, GameController&) = 0;
	virtual void handleCollision(Coin&, GameController&) = 0;
	virtual void handleCollision(Door&, GameController&) = 0;
	virtual void handleCollision(KeyMonster&, GameController&) = 0;
	virtual void handleCollision(BeastMonster&, GameController&) = 0;
	virtual void handleCollision(BallMonster&, GameController&) = 0;
	virtual void handleCollision(Bullet&, GameController&)  = 0;
	virtual void handleCollision(Gift&, GameController&)  = 0;
	bool isDoorOpen()const;
	void setDoorOpen();
	void setPrinceCollisStair();
	sf::Sprite& getIcon();


protected:
	sf::Sprite m_icon;
	bool m_open;
	sf::Vector2f m_prevPos;
	bool  m_princeCollisStair  = false;


};


