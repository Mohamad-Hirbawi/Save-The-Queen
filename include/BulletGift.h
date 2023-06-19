#pragma once
#include"Gift.h"


class BulletGift : public Gift
{
public:
	BulletGift(Toolbar_t symbol, sf::Vector2f position);
	virtual void handleCollision(Prince&, GameController&) override;

private:

	int m_numBallGift = 0;

};