#pragma once
#include <SFML/Graphics.hpp>


const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 1000;



// for start screen
const int REG_CHAR_SIZE = 100;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;
const std::string INFOSTR = "This game was done by Mohammad Hirbawi and Mustafa fachori.";
const float  MOVEMENTSPEED = 170.0;//3

enum Menus_t
{
	NEW, INFO, EXIT, BACK
};

const int CAP_CHAR_SIZE = 20;
const float CAP_OUTLINE_THICKNESS = 3.0;

const char PRINCE_C = 'a', WALL_C = '#', STAIR_C = '^', COIN_C = '*',
			KEYMONSTER_C = 'k', BALLMONSTER_C = 'b', GIFT_C = '$', EMPTY_C = ' ';



enum  Toolbar_t
{
	PRINCE , WALL, STAIR , COIN, KEYMONSTER , BALLMONSTER , GIFT,NONE
};



// for caption
const int EATCOIN = 1;
const int TIMEOFGAME = 60;
const int BOUNUSTIME = 20;

enum Captions
{
	SCORE, TIME
};