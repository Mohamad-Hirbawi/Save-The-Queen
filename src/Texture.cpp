#include "Textures.h"
#include <SFML/Audio.hpp>

// toolbar c-tor
Textures::Textures()
{
	setImagesForObj();
	setSounds();
}

// toolber d-tor
Textures::~Textures()
{
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

	//	Pacman,WALL, KEY, Cake, GATE, BOUNUS, NONE

	newImage.loadFromFile("wall.png");
	m_pTexture.push_back(newImage);
	
	newImage.loadFromFile("prince.png");//prince
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("wall.png");// wall
	m_pTexture.push_back(newImage);

	newImage.loadFromFile("Stair.png");//Stair
	m_pTexture.push_back(newImage);
	newImage.loadFromFile("coin.png");//prince
	m_pTexture.push_back(newImage);
	newImage.loadFromFile("KeyMonster.jpg");//prince
	m_pTexture.push_back(newImage);
	newImage.loadFromFile("BallMonster.png");//prince
	m_pTexture.push_back(newImage);

	
	
	//newImage.loadFromFile("key.png");
	//m_pTexture.push_back(newImage);


	//newImage.loadFromFile("cake.png");
	//m_pTexture.push_back(newImage);

	//newImage.loadFromFile("gate.png");
	//m_pTexture.push_back(newImage);

	//newImage.loadFromFile("gift.png");
	//m_pTexture.push_back(newImage);

	//newImage.loadFromFile("gate2.png");
	//m_pTexture.push_back(newImage);


	//newImage.loadFromFile("shadow.png");
	//m_pTexture.push_back(newImage);

	m_font.loadFromFile("SundayMorning.ttf");

}

sf::Font* Textures::getFont()
{
	return &m_font;
}

void Textures::setSounds()
{
	//sf::SoundBuffer newSound;

	//newSound.loadFromFile("start.wav");
	//m_sound.push_back(newSound);

	//newSound.loadFromFile("losing.wav");
	//m_sound.push_back(newSound);

	//newSound.loadFromFile("Click.wav");
	//m_sound.push_back(newSound);

	//newSound.loadFromFile("win.wav");
	//m_sound.push_back(newSound);

}

sf::SoundBuffer* Textures::getSound(Audioo audio)
{
	int index = (int)audio;
	return &this->m_sound[index];
}