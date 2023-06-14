#pragma once
#include <SFML/Graphics.hpp>


const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 1000;



// for start screen
//const sf::Vector2f HEADER_POS = { WINDOW_WIDTH / 2 - 330, 10 };
const sf::Vector2f CENTER = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
//const sf::Vector2f RECT_SIZE = { 140.0, 60.0 };
const int REG_CHAR_SIZE = 100;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;
const std::string INFOSTR = "This game was done by Mohammad Hirbawi and Mustafa fachori.";
const float  MOVEMENTSPEED = 170.0;//3

const int CAP_CHAR_SIZE = 30;
const float CAP_OUTLINE_THICKNESS = 3.0;
const int BUFF_DISTANCE = 10;
const int MUSIC_ICON_POS = 40;

const char PRINCE_C = 'a', WALL_C = '#', STAIR_C = '^',COIN_C = '*', EMPTY_C = ' ',
CAKE_C = '*', GIFT_C = '$', GATE_C = 'D',
KEY_C = '%', SHADOW_C = '&', SUPERPACMAN_C = '@';


enum  Toolbar_t
{
	PRINCE = 1, WALL, STAIR , COIN ,KEY, CAKE, GATE, GIFT,
	GATEOPEN, SHADOW, NONE
};

// for caption
const int EATCOIN = 1;