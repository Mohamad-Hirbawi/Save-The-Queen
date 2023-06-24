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
	void UpdateNumCoin(const int& number);
	void updateTime(float time);
	void dicreaseLife();
	void dicreaseBullet();
	void increaseLife();
	void newLevel(const int time);
	void increaseKey();
	bool checkEmptyCoin();

	void increaseBullet();
	int getBullet()const;
	bool haveKey();
	int getLife()const;
	int getTime()const;
	void restartLifeAndScore();


private:
	void startCaptions();
	sf::Text drawInCaption(sf::Text text, const float x, const float y);
	void dicreaseKey();
	std::vector<sf::Text> m_text;
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;
	int intCaption[NUMCAPTIONS];
	
	
};
