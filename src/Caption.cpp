#include "Caption.h"

Caption::Caption()
{
	resetartCaptions();
	startCaptions();
}

void Caption::startCaptions()
{
	sf::Text m_helpText;
	for (int i = 1; i <= NUMCAPTIONS; i++)
	{
		m_helpText = drawInCaption(m_helpText, WINDOW_WIDTH * 0.85, WINDOW_HEIGHT * 0.1 *i);
		m_text.emplace_back(m_helpText);
	}
}

void Caption::resetartCaptions()
{
	intCaption [Keys] = 0;
	intCaption [SCORE] = 0;
	intCaption[LIFE] = 3;
	intCaption[BULLETS]= 0;
	intCaption[NUMCOIN]= 0;
	newLevel(TIMEOFGAME);
}

void Caption::drawCaptions(sf::RenderWindow& window)
{
	updateTime(0); 
	for(int index =0 ; index < NUMCAPTIONS; index++)
	{ 
		m_text[index].setString(STRCAPTIONARR[index] + std::to_string(intCaption[index]));
		window.draw(m_text[index]);
	}
}

void Caption::increaseScore(const int number)
{
	intCaption [SCORE]+= number;
}

void Caption::UpdateNumCoin(const int& number)
{
	intCaption[NUMCOIN]+= number;
}

void Caption::updateTime(float time)
{
	std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now(); 
	std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_startTime);
	
	if (elapsedTime >= std::chrono::seconds(1)) 
	{
		m_startTime = currentTime; 
		intCaption[TIME]--;
	}

	intCaption[TIME]+= int(time);
}

void Caption::dicreaseLife()
{
	intCaption [LIFE]--;
}

void Caption::dicreaseBullet()
{
	intCaption [BULLETS]--;
}

void Caption::increaseLife()
{
	intCaption [LIFE]++;
}


void Caption::increaseBullet()
{
	intCaption [BULLETS] += ADDBULEET;
}

int Caption::getBullet() const
{return intCaption[BULLETS];}


bool Caption::haveKey()
{
	if (intCaption[Keys] > 0)
	{
		dicreaseKey();
		return true;
	}
	return false;
}

int Caption::getLife()const
{
	return intCaption [LIFE];
}

int Caption::getTime() const
{
	return intCaption[TIME];
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
	intCaption[Keys]--;
}

void Caption::increaseKey()
{
	intCaption[Keys]++;
}

bool Caption::checkEmptyCoin()
{
	if (intCaption[NUMCOIN] == 0)
		return true;
	return false;
}

void Caption::newLevel(const int time)
{
	intCaption[TIME] = time;
	m_startTime = std::chrono::steady_clock::now();
}