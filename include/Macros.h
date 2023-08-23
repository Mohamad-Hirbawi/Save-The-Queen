#pragma once
#include <SFML/Graphics.hpp>
#include <string>

const int WINDOW_WIDTH = 1500,
WINDOW_HEIGHT = 1000;

// for start screen(menu)
const int REG_CHAR_SIZE = 100;
const int REG_CHAR_SIZE_INFO = 100;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;
const std::string INFOSTR = "\n\
				This game was created by Mohammad Hirbawi and Mustafa Fakhouri.\n\
				In this game, there are static and moving objects. The player can control the prince.\n\
				The objective is for the prince to collect all the coins and reach the final door\n\
				to progress to the next level.\n\
				If the prince collects a life gift, an additional life will be granted.\n\
				Collecting a time gift adds extra time, while collecting a bullet gift provides\n\
				additional bullets.\n\
				If the prince comes into contact with a monster, he will lose a life and respawn at the\n\
				starting point.\n\
				If a monster throws a bullet at the prince and it hits him, he will also lose a life.\n\
				However, if the prince throws a bullet at a monster, the monster will die, \n\
				except for the beast monster which requires 8 bullets to be defeated.\n\
				The game utilizes the up, down, right, and left arrow buttons for movement,\n\
				while the 'X' button is used to fire projectiles.\n";
const float  MOVEMENTSPEED = 150.0;//3
const float  MONSTERSPEED= 50.0;//3
const float  BULEETSPEED = 170.0;//3
const int NUMMENU = 4;

enum Menus_t
{
	NEW, INFO, EXIT, BACK
};

//directions
const sf::Vector2f RIGHT = sf::Vector2f(1, 0);
const sf::Vector2f LEFT = sf::Vector2f(-1, 0);
const sf::Vector2f UP = sf::Vector2f(0, -1);
const sf::Vector2f DOWN = sf::Vector2f(0,1);
const sf::Vector2f UPRIGHT= sf::Vector2f(1,-1);
const sf::Vector2f UPLEFT= sf::Vector2f(-1,-1);
const sf::Vector2f DOWNLEFT = sf::Vector2f(-1,1);
const sf::Vector2f DOWNRIGHT = sf::Vector2f(1,1);
const sf::Vector2f STANDIGSTIL= sf::Vector2f(0,0);

//characters for textures
const char PRINCE_C = 'a', WALL_C = '#', STAIR_C = '^', COIN_C = '*',
KEYMONSTER_C = 'k', BALLMONSTER_C = 'm', ADDTIME_C = 't',
ADDLIFE_C = '&', GIFTBULLET_C = 'g', DDOR_C = 'd', 
BULLET_C = 'b', BEASTMONSTER_C = 'B', QUEEN_C = 'q', KEY_C = 'K', GATE_C = 'G', EMPTY_C = ' ';
enum  Toolbar_t
{
	PRINCE , WALL, STAIR , COIN, KEYMONSTER , BALLMONSTER , INCREASETIME ,ADDLIFE ,DOOR,
	OPENDOOR, GIFTBULLET ,BULLET, BEASTMONSTER ,QUEEN, KEY, GATE ,STATICS  ,NONE

};

enum Sounds_t
{
	GameWin , TC ,GiftSound, keyDrop, gateOpen, BeastMonsterDead, fireTouch, winGameSound
};

const std::vector<std::string> soundVec = {
	"GameWin.ogg", "TC.ogg","GiftSound.ogg","keyDrop.ogg","gateOpen.ogg","BeastMonsterDead.ogg"
	"fireTouch.ogg","winGameSound.ogg"

};
// for loadFromFile and emplace_back Texture
const std::vector<std::string> strTexture = { "prince.png", "wall.png","Stair.png","coin.png","KeyMonster.png",
"BallMonster.png" ,"IncreasTime.png" ,"addLife.png","door.png","openDoor.png",
"giftBullet.png", "buleet.png", "beastMonster.png","Queen.png","key.png", "gate.png"};

const std::string strBackground[] = { "Bakground.jpg" ,"Background.jpg" };
const std::string strMenu[] = { "New" ,"Info" ,"Exit"};

// for caption
const int EATCOIN = 2;
const int TIMEOFGAME = 60;
const int BOUNUSTIME = 20;
const int CAP_CHAR_SIZE = 20;
const int ADDBULEET = 5;
const int NUMCAPTIONS = 6;

enum Captions
{

	SCORE, TIME, LIFE, Keys, BULLETS, NUMCOIN
};
const std::vector<std::string> STRCAPTIONARR = { "Score: ", "Time left: ", "Life: ", "Key: ", "Bullets: ", "Coin: " };






