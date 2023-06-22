#pragma once
#include <chrono>
#include "MovingObject.h"

class Queen : public MovingObject
{
public:
	Queen(Toolbar_t symbol, sf::Vector2f position);


	virtual void handleCollision(Prince&, GameController&) override {};
	virtual void handleCollision(Gift&, GameController&) override {};
	virtual void handleCollision(Stair& , GameController&) override{};
	virtual void handleCollision(Object&, GameController&) override;
	virtual void handleCollision(Wall&, GameController&) override;
	virtual void handleCollision(Coin&, GameController&) override {};
	virtual void handleCollision(Door&, GameController&) override;
	virtual void handleCollision(KeyMonster&, GameController&) override {};
	virtual void handleCollision(BallMonster&, GameController&) override {};
	virtual void handleCollision(BeastMonster&, GameController&) override {};
	virtual void handleCollision(Bullet&, GameController&) override {};



	virtual void move(sf::Time deltaTime, sf::Vector2f)override ;

	sf::Vector2f getDirection();

	//sf::Vector2f getDirection(sf::Vector2f princePos);

private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	sf::Vector2f m_dir;
};
