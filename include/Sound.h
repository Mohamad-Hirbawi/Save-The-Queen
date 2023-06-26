#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Macros.h"
//#include "Buffers.h"

/* The Sound class is in charge of the sounds and musics of the game.
 * It also holds control of the volume. */
class Sound
{
public:
	/* Ctor. */
	Sound();

	/* Functions to play/stop music/sound. */
	void playSound(const int &place);
	void playMusic(const std::string fileName);
	void stopMusic();
	void setSound(const std::string fileName, const int& place);
	void loadGameBuffer(const std::string fileName);
	sf::SoundBuffer* getGameBuffer(const int& place);
private:
	std::vector<sf::Sound> m_sounds; // Stores the sounds of the game.
	sf::Music m_music; // Used to stream music.
	unsigned int m_volume; // For volume control.
	unsigned int m_prevVolume; // For volume control.
	std::vector<sf::SoundBuffer> m_gameBuffers;
};