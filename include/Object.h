#pragma once 
#include "Macros.h"
#include "Textures.h"
#include <SFML/Graphics.hpp>

class GameController;//
class Prince;
class Wall;
class Stair;
class Coin;
class Door;
class KeyMonster;
class BallMonster;

class Object
{
public:	

	Object();
	Object(Toolbar_t symbol, sf::Vector2f position);
	void draw(sf::RenderWindow&);

	bool collidesWith(const Object& obj) const;
	sf::Vector2f getposition()const;
	sf::Vector2f getprevPos()const;

	virtual void handleCollision(Object&, GameController&) = 0;
	virtual void handleCollision(Prince&, GameController&) = 0;
	virtual void handleCollision(Wall&, GameController&) = 0;
	virtual void handleCollision(Stair&, GameController&) = 0;
	virtual void handleCollision(Coin&, GameController&) = 0;
	virtual void handleCollision(Door&, GameController&) = 0;
	virtual void handleCollision(KeyMonster&, GameController&) = 0;
	virtual void handleCollision(BallMonster&, GameController&) = 0;

protected:
	bool m_open;
	sf::Sprite m_icon;
	sf::Vector2f m_prevPos;
	bool  m_princeCollisStair  = false;


};


