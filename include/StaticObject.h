#pragma once 
#include "Object.h"
#include "Prince.h"
#include "Queen.h"
#include "KeyMonster.h"
#include "BallMonster.h"
#include "Monster.h"
#include "Bullet.h"

class StaticObject : public Object
{
public:
	StaticObject (Toolbar_t symbol, sf::Vector2f position);
	virtual void handleCollision(Object&, GameController&) {}


private:
	
};
