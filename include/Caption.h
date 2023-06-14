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

private:
	void startCaptions();

	int m_score;

	sf::Text m_textScore;

};
