#pragma once
#include <SFML/Graphics.hpp>

#include "Macros.h"
#include <string>


class Menu
{
public:
	Menu();
	void loadBackGroaund(sf::Texture &Texture, sf::Sprite& sprite, const std::string& str);
	//void loadBackGroaund(sf::Texture Texture, sf::Sprite sprite, const std::string& str);
	//void loadBackGroaund(sf::Texture m_pTexture, sf::Sprite, std::string str);
	//void loadBackGroaund(sf::Texture m_pTexture, std::string str);
	void activateMenu(sf::RenderWindow&);


private:
	void infoFunc(sf::RenderWindow& window);

	bool handleClick(const sf::Vector2f&, int& i) const;
	void handleMove(const sf::Vector2f&);
	sf::Text doHandleClick(sf::Text text, const sf::Vector2f& Location);
	sf::Text drawInMenu(sf::Text text, std::string str, const float& x, const float &y);
	sf::Font m_font;

	std::vector<sf::Text> m_text;
	std::vector<sf::Text> m_textHelp;
	sf::Text m_helpText;

	sf::RectangleShape m_background;

	sf::Texture m_pTexture;
	sf::Texture m_infoTexture;

	sf::Sprite m_startWallp;
	sf::Sprite m_infosprite;

	int m_index;

};