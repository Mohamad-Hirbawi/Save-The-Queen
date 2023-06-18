#include "Textures.h"

// toolbar c-tor
Textures::Textures()
{
	setImagesForObj();
}

Textures& Textures::instance()
{
	static Textures inst;
	return inst;
	// TODO: insert return statement here
}

sf::Texture* Textures::getIcon(const Toolbar_t symbol)
{
	int index = (int)symbol;
	return &this->m_pTexture[index];
}


void Textures::setImagesForObj()
{
	sf::Texture newImage;
	// PRINCE , WALL, STAIR , COIN, KEYMONSTER , BALLMONSTER , INCREASETIME, ADDLIFE,DOOR
	for (const auto& tuxt : strTexture){
		newImage.loadFromFile(tuxt);
		m_pTexture.emplace_back(newImage);
	}
	m_font.loadFromFile("SundayMorning.ttf");

}

sf::Font* Textures::getFont()
{return &m_font;}
