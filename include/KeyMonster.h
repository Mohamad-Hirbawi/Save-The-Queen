#pragma once
#include "Monster.h"
#include <chrono>

class KeyMonster : public Monster
{
public:
	KeyMonster(Toolbar_t symbol, sf::Vector2f position);
	virtual void move(sf::Time deltaTime)override;

	virtual void handleCollision(Prince&, GameController&) override {};
	virtual void handleCollision(Stair&, GameController&) override {};
	void handleCollision(Object&, GameController&) override ;
	void handleCollision(Wall&, GameController&) override ;
	void handleCollision(Coin&, GameController&) override {};
	void handleCollision(KeyMonster&, GameController&) override {};
	void handleCollision(BallMonster&, GameController&) override {};

	//virtual void move(sf::Time deltaTime)override;

private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	sf::Vector2f getDirection();
	sf::Vector2f m_dir;
	sf::Clock m_changeDircectionAlarm;
	sf::Vector2f m_positionKeyMonster;
};
