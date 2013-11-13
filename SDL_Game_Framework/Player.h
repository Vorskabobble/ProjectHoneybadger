#pragma once
#include "awsprite.h"

class Player: public AWSprite{
	bool m_right, m_left, m_up, m_down;
	int m_speed;
	SDL_Rect m_cam;
	float XslowRate, YslowRate;
public:
	Player(void);
	~Player(void);

	void setRight(bool right);
	void setLeft(bool left);
	void setUp(bool up);
	void setDown(bool down);
	SDL_Rect getCam();
	void update();
};

