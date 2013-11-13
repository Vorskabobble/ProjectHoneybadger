#include "Consumable.h"


Consumable::Consumable(char* filePath, string name, int value, int reqLvl, int rarity, int health, int mana): Item(filePath, name, value, reqLvl, rarity){
	m_health = health;
	m_mana = mana;
}


Consumable::~Consumable(void){
}

int Consumable::getHealth(){
	return m_health;
}

int Consumable::getMana(){
	return m_mana;
}