#pragma once
#include "AWSprite.h"
#include <iostream>

class Item: public AWSprite{
	int m_value, m_stamina, m_agility, m_strength, m_intellect, m_luck, m_reqLvl, m_rarity;
	string m_name;

public:
	Item(char* filePath, string name, int value, int reqLvl, int rarity);
	Item(char* filePath, string name, int value, int stamina, int agility, int strength, int intellect, int luck, int reqLvl, int rarity);
	~Item(void);

	string getName();
	int getValue();
	int getStamina();
	int getAgility();
	int getStrength();
	int getIntellect();
	int getReqLvl();
	int getRarity();
};

