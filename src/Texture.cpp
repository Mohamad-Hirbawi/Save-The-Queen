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
	// PRINCE , WALL, STAIR , COIN, KEYMONSTER , BALLMONSTER , INCREASETIME, ADDLIFE

	newImage.loadFromFile("prince.png");//prince
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("wall.png");// wall
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("Stair.png");//Stair
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("coin.png");//coin 
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("KeyMonster.png");//KeyMonster
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("BallMonster.png");//BallMonster
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("IncreasTime.png");//gift
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("addLife.png");//gift
	m_pTexture.push_back(newImage);
	
	m_font.loadFromFile("SundayMorning.ttf");

}

sf::Font* Textures::getFont()
{
	return &m_font;
}
