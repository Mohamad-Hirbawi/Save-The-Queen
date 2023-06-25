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
	// singelton
}

sf::Texture* Textures::getIcon(const Toolbar_t symbol)
{
	int index = (int)symbol;
	return &this->m_pTexture[index];
}


void Textures::setImagesForObj()
{
	sf::Texture newImage;
	for (const auto& tuxt : strTexture) {
		if (!newImage.loadFromFile(tuxt))
			throw std::runtime_error("Failed to load texture");
		m_pTexture.emplace_back(newImage);
	}
	system("cls");
	m_font.loadFromFile("SundayMorning.ttf");

}

sf::Font* Textures::getFont()
{
	return &m_font;
}
