#pragma once
#include "Menu.h"

Menu::Menu() :m_index(0)
{
	this->m_font.loadFromFile("PLAYBILL.TTF");


	// intialize start button
	m_helpText = drawInMenu(m_helpText, "New", WINDOW_WIDTH*0.48, WINDOW_HEIGHT*0.25);
	m_text.push_back(m_helpText);


	// intialize info button
	m_helpText = drawInMenu(m_helpText, "Info", WINDOW_WIDTH * 0.48, WINDOW_HEIGHT * 0.50);
	m_text.push_back(m_helpText);

	// intialize exit button
	m_helpText = drawInMenu(m_helpText, "Exit", WINDOW_WIDTH * 0.48, WINDOW_HEIGHT * 0.75);
	m_text.push_back(m_helpText);

	// intialize back button 6
	m_helpText = drawInMenu(m_helpText, "Back", WINDOW_WIDTH * 0.10, WINDOW_HEIGHT * 0.85);
	m_text.push_back(m_helpText);



	this->m_pTexture.loadFromFile("Background.jpg");
	this->m_startWallp.setTexture(m_pTexture);
	this->m_startWallp.setScale(0.5, 0.5);

	this->m_infoTexture.loadFromFile("conan.jpg");
	this->m_infosprite.setTexture(m_infoTexture);
	this->m_infosprite.setScale(0.5, 0.5);

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

	while (window.isOpen())
	{
		if (m_index == 0)// Menu 
		{
			window.clear();
			window.draw(m_startWallp);
			window.draw(m_text[0]);
			window.draw(m_text[1]);
			window.draw(m_text[2]);
		}
		if (m_index == 2){	infoFunc(window);}

		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			sf::Vector2f Location;
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				window.clear();
				Location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (handleClick(Location, window, m_index)) {
					if (m_index == 1) //start
						return;
					
				}
				else
					window.close();
				break;
			case sf::Event::MouseMoved:
				Location = (sf::Vector2f)sf::Mouse::getPosition(window);
				handleMove(Location);
				break;
			}
		}
	}
}
void Menu::infoFunc(sf::RenderWindow& window) {
	window.clear(sf::Color::White);
	window.draw(m_infosprite);
	window.draw(m_text[3]);

	sf::Text text;
	text.setFont(m_font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(REG_CHAR_SIZE * 0.5);
	text.setPosition({ WINDOW_WIDTH * 0.1, WINDOW_HEIGHT * 0.1 });
	text.setString(INFOSTR);
	//text.setOutlineColor(sf::Color::White);
	//text.setOutlineThickness(OUTLINE_THICKNESS/10);
	window.draw(text);
}

bool Menu::handleClick(const sf::Vector2f& Location, sf::RenderWindow& window, int& i) const
{

	if (m_text[2].getGlobalBounds().contains(Location))// pressed exit
		return false;


	if (m_text[3].getGlobalBounds().contains(Location)) { // pressed back
		i = 0;
		return true;
	}

	if (m_text[0].getGlobalBounds().contains(Location)) { // pressed New
		i = 1;
		return true;
	}
	if (m_text[1].getGlobalBounds().contains(Location)) { // pressed info
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
	// mark/unmark start button
	m_text.push_back(doHandleClick(m_textHelp[0], Location));
	//m_text(0) = doHandleClick(m_text(0), Location);

	//mark/unmark info button
	m_text.push_back(doHandleClick(m_textHelp[1], Location));

	//mark/unmark exit button
	m_text.push_back(doHandleClick(m_textHelp[2], Location));

	m_text.push_back(doHandleClick(m_textHelp[3], Location));
}
