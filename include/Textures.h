#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Macros.h"

using std::vector;

// icon names
//enum  Toolbar_t
//{
//	PACMAN = 1, WALL , KEY, CAKE, GATE,GIFT,
//	GATEOPEN ,SHADOW,SUPERPACMAN, NONE
//};
//  DWARFS_C 
//const char PACMAN_C = 'a', WALL_C = '#', EMPTY_C = ' ', 
//CAKE_C = '*', GIFT_C = '$', GATE_C = 'D',
//KEY_C = '%',/* DWARFS_C = '^',*/ SHADOW_C = '&', SUPERPACMAN_C ='@';

const int NUM_OF_ICONS = 9; // number of icons

enum class Audioo
{
	start,  losing , click , win
};


class Textures
{
public:
	~Textures();

	static Textures& instance();
	sf::Texture* getIcon(const Toolbar_t);;
	sf::SoundBuffer* getSound(Audioo);
	sf::Font* getFont();


private:
	Textures();
	Textures(const Textures&) = default;
	Textures& operator=(const Textures&) = default;

	void setImagesForObj();
	void setSounds();
	sf::Font m_font;


	vector < sf::Texture > m_pTexture;
	std::vector<sf::SoundBuffer> m_sound;
};

 