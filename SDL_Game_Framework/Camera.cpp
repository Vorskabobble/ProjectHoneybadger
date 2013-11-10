#include "Camera.h"


Camera::Camera(int x, int y, int w, int h, int accel){
	m_camera.x = x;
	m_camera.y = y;
	m_camera.w = w;
	m_camera.h = h;
	m_accel = accel;
}

Camera::~Camera(void){
}

int Camera::x(){
	return m_camera.x;
}

int Camera::y(){
	return m_camera.y;
}

int Camera::w(){
	return m_camera.w;
}
int Camera::h(){
	return m_camera.h;
}

void Camera::x(int x){
	m_camera.x = x;
}

void Camera::y(int y){
	m_camera.y = y;
}

void Camera::w(int w){
	m_camera.w = w;
}

void Camera::h(int h){
	m_camera.h = h;
}

void Camera::moveX(int speed){
	m_camera.x += speed;
}

void Camera::moveY(int speed){
	m_camera.y += speed;
}