#pragma once
#include "item.h"

class Consumable :public Item{
	int m_health, m_mana;
public:
	Consumable(char* filePath, string name, int value, int reqLvl, int rarity, int health, int mana);
	~Consumable(void);

	int getHealth();
	int getMana();
};

