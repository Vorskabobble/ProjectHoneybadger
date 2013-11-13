#include "Item.h"

Item::Item(char* filePath, string name, int value, int reqLvl, int rarity) : AWSprite(filePath, 1, true){
	m_name = name;
	m_value = value;
	m_stamina = 0;
	m_agility = 0;
	m_strength = 0;
	m_intellect = 0;
	m_luck = 0;
	m_reqLvl = reqLvl;
	m_rarity = rarity;
}

Item::Item(char* filePath, string name, int value, int stamina, int agility, int strength, int intellect, int luck, int reqLvl, int rarity) : AWSprite(filePath, 1, true){
	m_name = name;
	m_value = value;
	m_stamina = stamina;
	m_agility = agility;
	m_strength = strength;
	m_intellect = intellect;
	m_luck = luck;
	m_reqLvl = reqLvl;
	m_rarity = rarity;
}

Item::~Item(void){
}

string Item::getName(){
	return m_name;
}

int Item::getValue(){
	return m_value;
}

int Item::getStamina(){
	return m_stamina;
}

int Item::getAgility(){
	return m_agility;
}

int Item::getStrength(){
	return m_strength;
}

int Item::getIntellect(){
	return m_intellect;
}

int Item::getReqLvl(){
	return m_reqLvl;
}

int Item::getRarity(){
	return m_rarity;
}
