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

private:
	void startCaptions();
	void newLevel(const int time);
	void updateTime(float time);
	sf::Text drawInCaption(sf::Text text, const float x, const float y);


	int m_score;
	int m_stageTime;

	sf::Text m_helpText;
	std::vector<sf::Text> m_text;
	std::chrono::time_point<std::chrono::steady_clock> m_startTime;

};
