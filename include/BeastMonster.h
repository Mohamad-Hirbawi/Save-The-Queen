#pragma once
#include "Monster.h"
#include<chrono>

class BeastMonster : public Monster
{
public:
	BeastMonster(Toolbar_t symbol, sf::Vector2f position);

	sf::Vector2f directionFollowPrince(sf::Vector2f princePos);

	sf::Vector2f getDirection(sf::Vector2f princePos);

	virtual void move(sf::Time deltaTime, sf::Vector2f, GameController& game)override ;


private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	std::chrono::time_point<std::chrono::steady_clock> m_startTime2;
	sf::Vector2f m_dir;
	sf::Clock m_changeDircectionAlarm;
	sf::Vector2f m_positionKeyMonster;


};
