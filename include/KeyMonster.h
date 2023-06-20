#pragma once
#include "Monster.h"
#include <chrono>

class KeyMonster : public Monster
{
public:
	KeyMonster(Toolbar_t symbol, sf::Vector2f position);
	virtual void move(sf::Time deltaTime, sf::Vector2f)override;

	virtual void handleCollision(Prince&, GameController&) override;
	virtual void handleCollision(Object&, GameController&) override ;

	virtual void handleCollision(Bullet&, GameController&) override;
	virtual void handleCollision(Wall&, GameController&) override;
	virtual void handleCollision(Door&, GameController&)override;



private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	sf::Vector2f directionFollowPrince(sf::Vector2f princePos);
	sf::Vector2f getDirection(sf::Vector2f princePos);
	sf::Vector2f m_dir;
	sf::Clock m_changeDircectionAlarm;
	sf::Vector2f m_positionKeyMonster;
};
