#include "Caption.h"


Caption::Caption()
	:m_score(0)
{
	startCaptions();
}

void Caption::startCaptions()
{
	m_textScore.setFont(*Textures::instance().getFont());
	m_textScore.setCharacterSize(CAP_CHAR_SIZE);
	m_textScore.setPosition(WINDOW_WIDTH * 0.02, WINDOW_HEIGHT * 0.9);//(BUFF_DISTANCE + WINDOW_WIDTH / 5, WINDOW_HEIGHT + BUFF_DISTANCE)
	m_textScore.setFillColor(sf::Color::Blue);
	m_textScore.setOutlineColor(sf::Color::Black);
	m_textScore.setOutlineThickness(CAP_OUTLINE_THICKNESS);

	this->m_stageTimeText.setFont(*Textures::instance().getFont());
	this->m_stageTimeText.setCharacterSize(CAP_CHAR_SIZE);
	this->m_stageTimeText.setPosition(BUFF_DISTANCE + WINDOW_WIDTH / 4 * 3, WINDOW_HEIGHT + BUFF_DISTANCE);
	this->m_stageTimeText.setFillColor(sf::Color::Blue);
	this->m_stageTimeText.setOutlineColor(sf::Color::Black);
	this->m_stageTimeText.setOutlineThickness(CAP_OUTLINE_THICKNESS);
}

void Caption::resetartCaptions()
{
	m_score = 0;
}

void Caption::drawCaptions(sf::RenderWindow& window)
{
	m_textScore.setString("Sc " + std::to_string(m_score));
	window.draw(m_textScore);
}

void Caption::increaseScore(const int number)
{
	m_score += number;
}
