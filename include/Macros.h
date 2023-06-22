#pragma once
#include <SFML/Graphics.hpp>
#include <string>

const float WINDOW_WIDTH =1000,//1500
	 WINDOW_HEIGHT = 800,//1000
	 VIEWSIZE = 700;//1000

// for start screen(menu)
const int REG_CHAR_SIZE = 100;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;
const std::string INFOSTR = "This game was done by Mohammad Hirbawi and Mustafa fachori.";
const float  MOVEMENTSPEED = 170.0;//3
const float  MONSTERSPEED= 80.0;//3
const float  BULEETSPEED = 300.0;//3
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
KEYMONSTER_C = 'k', BALLMONSTER_C = 'm', ADDTIME_C = '$',
ADDLIFE_C = '&', GIFTBULLET_C = 'g', DDOR_C = 'd', 
BULLET_C = 'b', BEASTMONSTER_C = 'B', QUEEN_C = 'q', KEY_C = 'K', GATE_C = 'G', EMPTY_C = ' ';
enum  Toolbar_t
{
	PRINCE , WALL, STAIR , COIN, KEYMONSTER , BALLMONSTER , INCREASETIME ,ADDLIFE ,DOOR,
	OPENDOOR, GIFTBULLET ,BULLET, BEASTMONSTER ,QUEEN, KEY, GATE ,STATICS  ,NONE

};

// for loadFromFile and emplace_back Texture
const std::string strTexture[] = { "prince.png", "wall.png","Stair.png","coin.png","KeyMonster.png",
"BallMonster.png" ,"IncreasTime.png" ,"addLife.png","door.png","openDoor.png",
"giftBullet.png", "buleet.jpg", "beastMonster.png","Queen.png","key.png", "gate.png"};

const std::string strBackground[] = { "conan.jpg" ,"Background.jpg" };
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

const std::string STRCAPTIONARR[] = { "Score: ","Time left: " ,"Life: ","Key: ","Bullets: ", "Coin: "};





