#pragma once
#include "SDL.h"

class Camera
{
private:
	SDL_Rect m_camera;
	int m_accel;
public:
	Camera(int x, int y, int w, int h, int accel);
	~Camera(void);

	int x();
	int y();
	int w();
	int h();
	int accel();

	void x(int x);
	void y(int y);
	void w(int w);
	void h(int h);
	void accel(int accel);

	void moveX(int speed);
	void moveY(int speed);
};

