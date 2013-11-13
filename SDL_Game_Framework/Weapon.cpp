#include "Weapon.h"


Weapon::Weapon(char* filePath, string name, int value, int stamina, int agility, int strength, int intellect, int luck, int reqLvl, int rarity, int minDamage, int maxDamage, int speed, int range, bool fire, bool ice, bool earth, bool lightning)
			   : Item(filePath, name, value, stamina, agility, strength, intellect, luck, reqLvl, rarity){
	m_minDamage = minDamage;
	m_maxDamage = maxDamage;
	m_speed = speed;
	m_range = range;
	m_fire = fire;
	m_ice = ice;
	m_earth = earth;
	m_lightning = lightning;
}

Weapon::~Weapon(void){
}

int Weapon::getMinDamage(){
	return m_minDamage;
}

int Weapon::getMaxDamage(){
	return m_maxDamage;
}

int Weapon::getSpeed(){
	return m_speed;
}

int Weapon::getRange(){
	return m_range;
}


bool Weapon::getFire(){
	return m_fire;
}

bool Weapon::getIce(){
	return m_ice;
}

bool Weapon::getEarth(){
	return m_earth;
}

bool Weapon::getLightning(){
	return m_lightning;
}
