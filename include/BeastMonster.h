#pragma once
#include "Monster.h"
#include<chrono>

class BeastMonster : public Monster
{
public:
	BeastMonster(Toolbar_t symbol, sf::Vector2f position);
	~BeastMonster() {}

	sf::Vector2f directionFollowPrince(const sf::Vector2f& princePos);
	sf::Vector2f getDirection(const sf::Vector2f& princePos);

	virtual void move(sf::Time deltaTime, sf::Vector2f, GameController& game)override ;
	int m_lifeBeast;


private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	std::chrono::time_point<std::chrono::steady_clock> m_startTime2;
	sf::Vector2f m_dir;
	sf::Clock m_changeDircectionAlarm;
	sf::Vector2f m_positionKeyMonster;

};
