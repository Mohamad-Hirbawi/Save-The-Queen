#pragma once

#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Macros.h"


class Caption
{
public:
	Caption();


	void resetartCaptions();

	void drawCaptions(sf::RenderWindow& window);
	void increaseScore(const int number);

	void updateTime(float time);
	void newLevel(const int time);


private:
	void startCaptions();
	sf::Text drawInCaption(sf::Text text, const float x, const float y);


	int m_score;
	int m_stageTime;
	bool m_timelessLevel;

	sf::Text m_textScore;
	sf::Text m_stageTimeText;
	sf::Clock m_Timer;
	sf::Text m_helpText;
	std::vector<sf::Text> m_text;

};
