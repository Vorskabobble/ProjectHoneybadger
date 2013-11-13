#include "Player.h"

Player::Player(void){
	m_right = m_left = m_up = m_down = false;
	setImage("images/wizard.png");
	set_auto_move(10);
	m_cam.w = 1280;
	m_cam.h = 720;
	m_cam.x = 0;
	m_cam.y = 0;
	m_speed = 4;
}

Player::~Player(void){
}

void Player::setRight(bool right){
	m_right = right;
}

void Player::setLeft(bool left){
	m_left = left;
}

void Player::setUp(bool up){
	m_up = up;
}

void Player::setDown(bool down){
	m_down = down;
}

SDL_Rect Player::getCam(){
	return m_cam;
}

void Player::update(){
	if(m_right){
		XslowRate = m_speed;
		if(get_x()+get_width() < m_cam.x+m_cam.w){
			set_x_velocity(m_speed);
		}else{
			set_x_velocity(0);
		}

		if(get_x() > m_cam.w/2-get_width()/2 && m_cam.x+m_cam.w < 5000){
			m_cam.x = get_x()-m_cam.w/2+get_width()/2;
		}else if(m_cam.x > m_cam.w){
			m_cam.x = 5000-m_cam.w;
		}
	}

	if(m_left){
		XslowRate = m_speed;
		if(get_x() > 0){
			set_x_velocity(-m_speed);
		}else{
			set_x_velocity(0);
		}

		if(m_cam.x > 0 && get_x() < 5000-m_cam.w/2-get_width()/2){
			m_cam.x = get_x()-m_cam.w/2+get_width()/2;
		}else if(m_cam.x < m_cam.w){
			m_cam.x = 0;
		}
	}

	if(m_up){
		YslowRate = m_speed;
		if(get_y() > 0){
			set_y_velocity(-m_speed);
		}else{
			set_y_velocity(0);
		}

		if(m_cam.y > 0 && get_y() < 5000-m_cam.h/2-get_height()/2){
			m_cam.y = get_y()-m_cam.h/2+get_height()/2;
		}else if(m_cam.y < m_cam.h){
			m_cam.y = 0;
		}
	}

	if(m_down){
		YslowRate = m_speed;
		if(get_y()+get_height() < m_cam.y+m_cam.h){
			set_y_velocity(m_speed);
		}else{
			set_y_velocity(0);
		}

		if(get_y() > m_cam.h/2-get_height()/2 && m_cam.y+m_cam.h < 5000){
			m_cam.y = get_y()-m_cam.h/2+get_height()/2;
		}else if(m_cam.y > m_cam.h){
			m_cam.y = 5000-m_cam.h;
		}
	}

	if(!m_left && !m_right){
		if(get_x_velocity() > 0){
			set_x_velocity(XslowRate);
			XslowRate -= m_speed/2;
		}else if(get_x_velocity() < 0){
			set_x_velocity(-XslowRate);
			XslowRate -= m_speed/2;
		}

		if((get_x() > m_cam.w/2+get_width()/2 && m_cam.x+m_cam.w < 5000) || (m_cam.x > 0 && get_x() < 5000-m_cam.w/2)){
			m_cam.x = get_x()-m_cam.w/2+get_width()/2;
		}

	}

	if(!m_up && !m_down){
		if(get_y_velocity() > 0){
			set_y_velocity(YslowRate);
			YslowRate -= m_speed/2;
		}else if(get_y_velocity() < 0){
			set_y_velocity(-YslowRate);
			YslowRate -= m_speed/2;
		}

		if((get_y() > m_cam.h/2 && m_cam.y+m_cam.h < 5000) || (m_cam.y > 0 && get_y() < 5000-m_cam.h/2-get_height()/2)){
			m_cam.y = get_y()-m_cam.h/2+get_height()/2;
		}
	}
}