#pragma once
#include "Monster.h"
#include <chrono>
class BallMonster : public Monster
{
public:
	BallMonster(Toolbar_t symbol, sf::Vector2f position);
	~BallMonster(){}
	sf::Vector2f getDirection(const sf::Vector2f &princePos);
	virtual void move(sf::Time deltaTime, sf::Vector2f princePos, GameController& game)override;

private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	std::chrono::time_point<std::chrono::steady_clock> m_startTime2;
	sf::Vector2f m_dir;
	sf::Clock m_changeDircectionAlarm;
	sf::Vector2f m_positionKeyMonster;

};
