#include "Caption.h"


Caption::Caption()
	:m_score(0), m_stageTime(15), m_timelessLevel(false)
{
	startCaptions();
}

void Caption::startCaptions()
{
	m_helpText = drawInCaption(m_helpText, WINDOW_WIDTH * 0.02, WINDOW_HEIGHT * 0.9);
	m_text.push_back(m_helpText);

	m_stageTimeText.setFont(*Textures::instance().getFont());
	m_stageTimeText.setCharacterSize(CAP_CHAR_SIZE);
	m_stageTimeText.setPosition(WINDOW_WIDTH * 0.2, WINDOW_HEIGHT * 0.9);
	m_stageTimeText.setFillColor(sf::Color::White);
}



void Caption::resetartCaptions()
{
	m_score = 0;
	newLevel(2000);
}

void Caption::drawCaptions(sf::RenderWindow& window)
{
	updateTime(0);
	window.draw(m_stageTimeText);

	m_text[0].setString("Score: " + std::to_string(m_score));
	window.draw(m_text[0]);

}

void Caption::increaseScore(const int number)
{
	m_score += number;
}

void Caption::updateTime(float time)
{
	m_stageTime += time;
	m_stageTime -= this->m_Timer.getElapsedTime().asSeconds();

	m_stageTimeText.setString("Time left: " + std::to_string(m_stageTime));
	m_Timer.restart();
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
	m_Timer.restart();
}