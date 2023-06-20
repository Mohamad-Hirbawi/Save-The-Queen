#pragma once
#include "Monster.h"
#include <chrono>
class BallMonster : public Monster
{
public:
	BallMonster(Toolbar_t symbol, sf::Vector2f position);

	sf::Vector2f getDirection(sf::Vector2f princePos);
	virtual void move(sf::Time deltaTime, sf::Vector2f princePos)override;
	virtual void handleCollision(Prince&, GameController&) override;
	sf::Vector2f directionFollowPrince(sf::Vector2f princePos);
	virtual void handleCollision(Wall&, GameController&) override{};
	//virtual void handleCollision(Bullet&, GameController&) override {};

private:
	//sf::Vector2f directionFollowPrince(sf::Vector2f princePos);
	//sf::Vector2f getDirection(sf::Vector2f princePos);
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	sf::Vector2f m_dir;
	sf::Clock m_changeDircectionAlarm;
	sf::Vector2f m_positionKeyMonster;

};
