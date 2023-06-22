#pragma once
#include <chrono>
#include "MovingObject.h"

class Queen : public MovingObject
{
public:
	Queen(Toolbar_t symbol, sf::Vector2f position);
	virtual void move(sf::Time deltaTime, sf::Vector2f,GameController& game)override ;

	sf::Vector2f getDirection();


private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	sf::Vector2f m_dir;
};
