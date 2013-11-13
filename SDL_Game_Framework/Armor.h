#pragma once
#include "item.h"
class Armor :public Item{
	int m_defense, m_magicResist, m_armorSlot;
public:
	Armor(char* filePath, string name, int value, int stamina, int agility, int strength, int intellect, int luck, int reqLvl, int rarity, int defense, int magicResist, int armorSlot);
	~Armor(void);

	int getDefense();
	int getMagicResist();
	int getArmorSlot();
};

