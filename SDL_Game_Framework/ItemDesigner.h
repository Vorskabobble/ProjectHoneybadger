#pragma once
#include "Armor.h"
#include "Weapon.h"
#include "Consumable.h"
#include "random.h"
#include <string>
#include <iostream>

using namespace std;

enum QUALITY{WEAK, DULL, PATHETIC, SILLY, BENDY, HEROIC, SWIFT, SHARP, EPIC, GREAT, OLD, POWERFUL, MAJESTIC, UNIQUE, POINTLESS, GODLY, RANDOM, SANTA, DOLEY};
enum POWER{STORM, ZEPHYR, POWER, WINTER, NIGHT, ELEMENTS, ACCURACY, FIRE, ICE, EARTH, LIGHTNING, GODS, UNICORN, MOUNTAIN, STREAM, IMAGINATION, RAIDER, THIEF, MOON, JOKER};
enum WEAPONTYPE{SWORD, MACE, BOW, STAFF, WAND, CROSSBOW, SPEAR, AXE};
enum ARMORTYPE{HANDS, FEET, HEAD, CHEST, LEGS};
enum CONSUMABLETYPE{BREAD, CHEESE, MILK, MANAPOT, HEALTHPOT, CAKE, ORANGE, APPLE, CHERRY, WATER, BEER};

class ItemDesigner{
	string name;
	char* filePath[50];
	int value, stamina, agility,  strength, intellect, luck, reqLvl, rarity;
public:
	ItemDesigner(void);
	~ItemDesigner(void);

	Weapon* createWeapon(int lvl, int quality, int type, int power);
	Armor* createArmor(int lvl, int quality, int type, int power);
	Consumable* createConsumable(int lvl, int quality, int type);

	void setQuality(int quality, int lvl);
	string setPower(int power, int lvl);
};

