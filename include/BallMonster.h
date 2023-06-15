#pragma once
#include "Monster.h"

class BallMonster : public Monster
{
public:
	BallMonster(Toolbar_t symbol, sf::Vector2f position);

	virtual void move(sf::Time deltaTime, sf::Vector2f)override;
	virtual void handleCollision(Prince&, GameController&) override;

	void handleCollision(Wall&, GameController&) override{};

private:

};
