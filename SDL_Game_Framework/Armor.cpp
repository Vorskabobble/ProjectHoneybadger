#include "Armor.h"


Armor::Armor(char* filePath, string name, int value, int stamina, int agility, int strength, int intellect, int luck, int reqLvl, int rarity, int defense, int magicResist, int armorSlot)
	: Item(filePath, name, value, stamina, agility, strength, intellect, luck, reqLvl, rarity){
	m_defense = defense;
	m_magicResist = magicResist;
	m_armorSlot = armorSlot;
}


Armor::~Armor(void){
}

int Armor::getDefense(){
	return m_defense;
}

int Armor::getMagicResist(){
	return m_magicResist;
}

int Armor::getArmorSlot(){
	return m_armorSlot;
}