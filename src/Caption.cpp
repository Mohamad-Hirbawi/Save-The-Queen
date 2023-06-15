#include "Caption.h"

Caption::Caption()
	:m_score(0)
{
	startCaptions();
}

void Caption::startCaptions()
{
	m_helpText = drawInCaption(m_helpText, WINDOW_WIDTH * 0.85, WINDOW_HEIGHT * 0.1);
	m_text.push_back(m_helpText);// Score

	m_helpText = drawInCaption(m_helpText, WINDOW_WIDTH * 0.85, WINDOW_HEIGHT * 0.2);
	m_text.push_back(m_helpText);// Time
}

void Caption::resetartCaptions()
{
	m_score = 0;
	newLevel(TIMEOFGAME);
}

void Caption::drawCaptions(sf::RenderWindow& window)
{
	updateTime(0); 
	window.draw(m_text[TIME]);

	m_text[SCORE].setString("Score: " + std::to_string(m_score));
	window.draw(m_text[SCORE]);


}

void Caption::increaseScore(const int number)
{
	m_score += number;
}

void Caption::updateTime(float time)
{
	std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now(); 
	std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime);
	
	if (elapsedTime >= std::chrono::seconds(1)) 
	{
		m_startTime = currentTime; 
		m_stageTime--; 
	}

	m_stageTime += time;
	m_text[1].setString("Time left: " + std::to_string(m_stageTime));
}

sf::Text Caption::drawInCaption(sf::Text text, const float x, const float y)
{
	text.setFont(*Textures::instance().getFont());
	text.setCharacterSize(CAP_CHAR_SIZE);
	text.setPosition(x, y);
	text.setFillColor(sf::Color::White);

	return text;
}

void Caption::newLevel(const int time)
{
	m_stageTime = time;
	m_startTime = std::chrono::steady_clock::now();
}