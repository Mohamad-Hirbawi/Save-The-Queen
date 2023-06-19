#pragma once
#include "Menu.h"

Menu::Menu() :m_index(0)
{
	m_font.loadFromFile("PLAYBILL.TTF");

	// intialize start button
	int i = 1;
	for (const auto text : strMenu)
	{
		m_helpText = drawInMenu(m_helpText, text, WINDOW_WIDTH * 0.48, WINDOW_HEIGHT * i/ NUMMENU);
		m_text.emplace_back(m_helpText);
		i++;
	}
	m_helpText = drawInMenu(m_helpText, "Back", WINDOW_WIDTH * 0.10, WINDOW_HEIGHT * 0.85);
	m_text.emplace_back(m_helpText);

	loadBackGroaund(m_infoTexture, m_infosprite, "conan.jpg");
	loadBackGroaund(m_pTexture, m_startWallp, "Background.jpg");
}
void Menu::loadBackGroaund(sf::Texture& Texture, sf::Sprite &sprite ,const std::string &str) {
	Texture.loadFromFile(str);
	sprite.setTexture(Texture);
	sprite.setScale(0.5, 0.5);
}

sf::Text Menu::drawInMenu(sf::Text text, std::string str, const float x, const float y)
{
	text.setFont(m_font);
	text.setFillColor(sf::Color::Cyan);
	text.setCharacterSize(REG_CHAR_SIZE);
	text.setPosition({ x,y });
	text.setString(str);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(OUTLINE_THICKNESS);

	return text;
}

void Menu::activateMenu(sf::RenderWindow& window)
{
	m_index = 0;
	while (window.isOpen())
	{
		if (m_index == 0)// Menu 
		{
			window.clear();
			window.draw(m_startWallp);
			window.draw(m_text[NEW]);
			window.draw(m_text[INFO]);
			window.draw(m_text[EXIT]);
		}
		if (m_index == 2){	infoFunc(window);}

		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			sf::Vector2f Location;
			switch (event.type)
			{
			case sf::Event::Closed:		window.close();		break;
			
			case sf::Event::MouseButtonReleased:
				window.clear();
				Location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (handleClick(Location, window, m_index)) {
					if (m_index == 1)		return; //start
				}		 
				else		window.close();					break;
			
			case sf::Event::MouseMoved:		Location = (sf::Vector2f)sf::Mouse::getPosition(window);
				handleMove(Location);						break;
			}
		}
	}
}

void Menu::infoFunc(sf::RenderWindow& window) {

	window.clear(sf::Color::White);
	window.draw(m_infosprite);
	window.draw(m_text[BACK]);
	sf::Text text;
	text.setFont(m_font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(REG_CHAR_SIZE * 0.5);
	text.setPosition({ WINDOW_WIDTH * 0.1, WINDOW_HEIGHT * 0.1 });
	text.setString(INFOSTR);
	window.draw(text);
}

bool Menu::handleClick(const sf::Vector2f& Location, sf::RenderWindow& window, int& i) const
{

	if (m_text[EXIT].getGlobalBounds().contains(Location))// pressed exit
		return false;


	if (m_text[BACK].getGlobalBounds().contains(Location)) { // pressed back
		i = 0;
		return true;
	}

	if (m_text[NEW].getGlobalBounds().contains(Location)) { // pressed New
		i = 1;
		return true;
	}
	if (m_text[INFO].getGlobalBounds().contains(Location)) { // pressed info
		i = 2;
		return true;
	}
	return true;

}

sf::Text Menu::doHandleClick(sf::Text text, const sf::Vector2f& Location)
{
	if (text.getGlobalBounds().contains(Location))
	{
		text.setOutlineColor(sf::Color::Red);
		text.setOutlineThickness(BOLD_OUTLINE);
	}
	else
	{
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(OUTLINE_THICKNESS);
	}

	return text;
}

void Menu::handleMove(const sf::Vector2f& Location)
{

	m_textHelp = m_text;
	m_text.clear();
	// mark/unmark button
	m_text.emplace_back(doHandleClick(m_textHelp[NEW], Location));
	m_text.emplace_back(doHandleClick(m_textHelp[INFO], Location));
	m_text.emplace_back(doHandleClick(m_textHelp[EXIT], Location));
	m_text.emplace_back(doHandleClick(m_textHelp[BACK], Location));
}
