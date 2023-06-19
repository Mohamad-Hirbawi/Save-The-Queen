#include "Caption.h"

Caption::Caption()
{
	resetartCaptions();
	startCaptions();
}

void Caption::startCaptions()
{
	sf::Text m_helpText;
	for (int i = 1; i <= NUMCAPTIONS-1; i++)
	{
		m_helpText = drawInCaption(m_helpText, WINDOW_WIDTH * 0.85, WINDOW_HEIGHT * 0.1 *i);
		m_text.emplace_back(m_helpText);
	}
}

void Caption::resetartCaptions()
{
	m_keys = 3;
	m_score = 0;
	m_life = 3;
	m_bullets = 0;
	newLevel(TIMEOFGAME);
}

void Caption::drawCaptions(sf::RenderWindow& window)
{
	updateTime(0); 

	m_text[TIME].setString("Time left: " + std::to_string(m_stageTime));
	m_text[SCORE].setString("Score: " + std::to_string(m_score));
	m_text[LIFE].setString("Life: " + std::to_string(m_life));
	m_text[Key].setString("Key: " + std::to_string(m_keys));

	for (int index = 0; index < NUMCAPTIONS; index++)
		window.draw(m_text[index]);

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

	m_stageTime += int(time);
}

void Caption::dicreaseLife()
{
	m_life--;
}

void Caption::increaseLife()
{
	m_life++;
}


void Caption::increaseBullet()
{
	m_bullets += ADDBULEET;
}

int Caption::getBullet() const

{return m_bullets;}


bool Caption::haveKey()
{
	if (m_keys > 0)
	{
		dicreaseKey();
		return true;
	}
	return false;
}

int Caption::getLife()const
{
	return m_life;
}

int Caption::getTime() const
{
	return m_stageTime;
}

sf::Text Caption::drawInCaption(sf::Text text, const float x, const float y)
{
	text.setFont(*Textures::instance().getFont());
	text.setCharacterSize(CAP_CHAR_SIZE);
	text.setPosition(x, y);
	text.setFillColor(sf::Color::White);

	return text;
}

void Caption::dicreaseKey()
{
	m_keys--;
}

void Caption::newLevel(const int time)
{
	m_stageTime = time;
	m_startTime = std::chrono::steady_clock::now();
}