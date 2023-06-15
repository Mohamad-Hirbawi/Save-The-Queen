#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"

using std::vector;

class Textures
{
public:

	static Textures& instance();
	sf::Texture* getIcon(const Toolbar_t);
	sf::Font* getFont();


private:
	Textures();
	Textures(const Textures&) = default;
	Textures& operator=(const Textures&) = default;

	void setImagesForObj();
	sf::Font m_font;

	vector < sf::Texture > m_pTexture;
};

 