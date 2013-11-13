#pragma once
#include "item.h"

class Weapon :public Item{
	int m_minDamage, m_maxDamage, m_speed, m_range;
	bool m_fire, m_ice, m_earth, m_lightning;
public:
	Weapon(char* filePath, string name, int value, int stamina, int agility, int strength, int intellect, int luck, int reqLvl, int rarity, int minDamage, int maxDamage, int speed, int range, bool fire, bool ice, bool earth, bool lightning);
	~Weapon(void);

	int getMinDamage();
	int getMaxDamage();
	int getSpeed();
	int getRange();

	bool getFire();
	bool getIce();
	bool getEarth();
	bool getLightning();
};

