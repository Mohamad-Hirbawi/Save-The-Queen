#include "Sound.h"

Sound::Sound()
{

	//setAndLoadSound();
	for (int index = 0; index < soundVec.size(); index++)
	{
		loadGameBuffer(soundVec[index]);
	
	}
	for (int index = 0; index < soundVec.size(); index++)
		setSound(soundVec[index], index);

}

void Sound::playSound(const int &place)
{
	m_sounds[place].play();
}

/* Plays the music in a loop. */
void Sound::playMusic(const std::string fileName)
{
	if(!m_music.openFromFile(fileName))
		throw std::runtime_error("failed to open file for sound");
	this->m_music.setLoop(true);
	this->m_music.play();
}

void Sound::stopMusic()
{
}

void Sound::setSound(const std::string fileName,const int &place)
{
	sf::Sound tempSound;
	sf::SoundBuffer* tempBuffer = getGameBuffer(place);
	tempSound.setBuffer(*tempBuffer);
	this->m_sounds.push_back(tempSound);
}

sf::SoundBuffer* Sound::getGameBuffer(const int& place )
{
	return &(m_gameBuffers[place]);
}

void Sound::loadGameBuffer(const std::string fileName)
{
	sf::SoundBuffer temp;
	temp.loadFromFile(fileName);
	m_gameBuffers.push_back(temp);
}
