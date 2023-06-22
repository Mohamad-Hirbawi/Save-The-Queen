#pragma once
#include "Macros.h"
#include "Menu.h"
#include "Board.h"
#include "Caption.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include "CollisionHandling.h"


class Bullet;
class GameController
{
public:
	GameController();
	void run();
	void increaseScore(const int number);
	void increaseTime();
	void addLife();
	bool ifErased();

	void eraseObject(Object& movingObject, Toolbar_t);
	void dead();

	void increaseBullet();
	void dicreaseCoin();
	bool haveKey();
	bool isLosing();
	bool collide(Object&, Object&);

private:
	void creatObject();
	void setLastDirection(sf::Vector2f direction);
	void creatBullet();
	void updateView();
	void checkCollis();
	void losing();
	bool isStaticObj(const char& c);
	void move(sf::Time deltaTime);

	sf::Vector2f m_lastPrinceDirection;
	sf::RenderWindow window;
	sf::Clock m_timer;

	sf::Sprite m_gameWallp;
	bool m_lose;
	sf::Texture m_pTexture;

	Caption m_caption;
	Menu m_menu;
	Board m_board;
	sf::View m_view;




	/// non private non puplick



};

template <typename FwdIt1, typename FwdIt2, typename Fn>
void for_each_pair(FwdIt1 begin1, FwdIt1 end1, FwdIt2 begin2, FwdIt2 end2,
	GameController& game, Fn fn)
{
	for (; begin1 != end1; ++begin1)
		for (auto second = begin2; second != end2; ++second)
		{
			fn(*begin1, *second);
			if (game.ifErased() || game.isLosing())
				return;
		}
}

template <typename FwdIt1, typename FwdIt2, typename Fn>
void for_one_pair(FwdIt1 begin1, FwdIt1 end1, FwdIt2 second,
	GameController& game, Fn fn)
{
	for (; begin1 != end1; ++begin1)
	{
		fn(*begin1, second);
		if (game.ifErased()||game.isLosing())
			return;
	}
}

template <typename FwdIt1, typename FwdIt2>
void collideAndProcess(FwdIt1 begin1, FwdIt1 end1, FwdIt2 begin2, FwdIt2 end2, GameController& game)
{
	for_each_pair(begin1, end1, begin2, end2,game, [&](auto& a, auto& b) {
		if (game.collide(*a, *b))
		processCollision(*a, *b, game);
		});
}

template <typename FwdIt1, typename FwdIt2>
void collideAndProcessOnePair(FwdIt1 begin1, FwdIt1 end1, FwdIt2* second, GameController& game)
{
	for_one_pair(begin1, end1, second,game, [&](auto& a, auto& b) {
		if (game.collide(*a, *b))
			processCollision(*a, *b, game);

		});
}

template <typename Container1, typename Container2>
void collideAndProcessPairs(Container1& container1, Container2& container2, GameController& game)
{
	collideAndProcess(container1.begin(), container1.end(), container2.begin(), container2.end(), game);
}

template <typename Container, typename T>
void collideAndProcessOnePair(Container& container, T* object , GameController& game)
{
	collideAndProcessOnePair(container.begin(), container.end(), object,game);
}