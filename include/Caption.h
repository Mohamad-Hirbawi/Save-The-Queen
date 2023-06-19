#pragma once

#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Macros.h"
#include <chrono>


class Caption
{
public:
	Caption();
	void resetartCaptions();
	void drawCaptions(sf::RenderWindow& window);
	void increaseScore(const int number);
	void updateTime(float time);
	void dicreaseLife();
	void increaseLife();
	void increaseBullet();
	int getBullet()const;


private:
	void startCaptions();
	void newLevel(const int time);
	sf::Text drawInCaption(sf::Text text, const float x, const float y);


	int m_score;
	int m_life;
	int m_stageTime;
	int m_bullets;
	std::vector<sf::Text> m_text;
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;

};
