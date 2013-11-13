#include "ItemDesigner.h"

ItemDesigner::ItemDesigner(void){
	value = stamina = agility = strength = intellect = luck = reqLvl = rarity = 0;
}

ItemDesigner::~ItemDesigner(void){
}

Weapon* ItemDesigner::createWeapon(int lvl, int quality, int type, int power){
	string midName, endName;

	int  minDamage = 0, maxDamage = 0, speed = 0, range = 0, rndNum;
	bool fire = false, ice = false, earth = false, lightning = false;
	
	rndNum = rand() % 3;

	*filePath = "images/game_btn.png";

	if(rand() % 2 < 1){
		reqLvl = lvl-rndNum;
	}else{
		reqLvl = lvl+rndNum;
	}

	setQuality(quality, lvl);

	switch(quality){
		case WEAK:
			minDamage = lvl*3; maxDamage = minDamage+10; speed = 1;
		break;
		case DULL: 
			minDamage = lvl*2.8; maxDamage = minDamage+10; speed = 1.5;
		break;
		case PATHETIC:
			minDamage = lvl*1.5; maxDamage = minDamage+5; speed = 1;
		break;
		case SILLY:
			minDamage = lvl*1; maxDamage = minDamage+15; speed = 1.5;
		break;
		case BENDY: 
			minDamage = lvl*1.4; maxDamage = minDamage+10; speed = 0.5;
		break;
		case HEROIC: 
			minDamage = lvl*10; maxDamage = minDamage+20; speed = 1;
		break;
		case SWIFT: 
			minDamage = lvl*5; maxDamage = minDamage+5; speed = 0.3;
		break;
		case SHARP:
			minDamage = lvl*8; maxDamage = minDamage+15; speed = 1;
		break;
		case EPIC: 
			minDamage = lvl*15; maxDamage = minDamage+40; speed = 1.5;
		break;
		case GREAT: 
			minDamage = lvl*5; maxDamage = minDamage+10; speed = 1;
		break;
		case OLD: 
			minDamage = lvl*1; maxDamage = minDamage+5; speed = 1.5;
		break;
		case POWERFUL: 
			minDamage = lvl*20; maxDamage = minDamage+40; speed = 2;
		break;
		case MAJESTIC: 
			minDamage = lvl*15; maxDamage = minDamage+15; speed = 0.5;
		break;
		case UNIQUE: 
			minDamage = lvl*25; maxDamage = minDamage+5; speed = 1.5;
		break;
		case POINTLESS: 
			minDamage = lvl*0.5; maxDamage = minDamage+2; speed = 1;
		break;
		case GODLY: 
			minDamage = lvl*40; maxDamage = minDamage+20; speed = 1.5;
		break;
		case RANDOM: 
			minDamage = lvl*rarity*10; maxDamage = minDamage+(10*rarity); speed = 1.5;
		break;
		case SANTA:
			minDamage = lvl*50; maxDamage = minDamage+50; speed = 2;
		break;
		case DOLEY:
			fire = true; ice = true; earth = true; lightning = true; speed = 2;
		break;
	}

	switch(type){
		case SWORD:
			midName = "sword ";
			range = 0; strength += lvl*7; stamina += lvl*2; speed += 0.3;
		break;
		case MACE:
			midName = "mace ";
			range = 0; intellect += lvl*5; stamina += 2; speed += 0.6;
		break;
		case BOW: 
			midName = "bow ";
			range = 2000; agility += lvl*7; luck += lvl*5;
		break;
		case STAFF: 
			midName = "staff ";
			range = 0; intellect += lvl*10; minDamage+= lvl*2; maxDamage += lvl*2; speed += 1;
		break;
		case WAND: 
			midName = "wand ";
			range = 600; intellect += lvl*5;
		break;
		case CROSSBOW: 
			midName = "crossbow ";
			range = 2000; agility += lvl*5; stamina += lvl*1; minDamage+= lvl*1; maxDamage += lvl*1; speed += 0.5;
		break;
		case SPEAR:
			midName = "spear ";
			range = 0; strength += lvl*5; stamina += lvl*4; speed += 0.3;
		break;
		case AXE:
			midName = "axe ";
			range = 0; strength += lvl*10; speed += 0.4;
		break;
	}

	switch(power){
		case STORM: 
			endName = "of the storm";
			agility += lvl*3; strength += lvl*2; luck = lvl*0.6; lightning = true;
		break;
		case ZEPHYR: 
			endName = "of the zephyr";
			agility += lvl*4; luck += lvl*1.1;speed -= 0.5;
		break;
		case POWER: 
			endName = "of power";
			intellect += lvl*3; stamina += lvl*2; lightning = true;
		break;
		case WINTER: 
			endName = "of winter";
			strength += lvl*4; ice = true;
		break;
		case NIGHT: 
			endName = "of night";
			agility += 4; stamina += 1;
		break;
		case ELEMENTS:
			endName = "of the elements";
			earth = true; fire = true;
		break;
		case ACCURACY:
			endName = "of accuracy";
			luck += lvl*1.5; minDamage += lvl*3; maxDamage = minDamage+3;
		break;
		case FIRE: 
			endName = "of fire";
			fire = true;
		break;
		case ICE: 
			endName = "of ice";
			ice = true;
		break;
		case EARTH: 
			endName = "of the earth";
			earth = true;
		break;
		case LIGHTNING:
			endName = "of lightning";
			lightning = true;
		break;
		case GODS:
			endName = "of the gods";
			stamina += lvl*6; lightning = true;
		break;
		case UNICORN: 
			endName = "of the unicorn";
			strength += lvl*2; agility += lvl*2; intellect += lvl*2; luck += lvl*7;
		break;
		case MOUNTAIN: 
			endName = "of the mountain";
			strength += lvl*4; stamina += lvl*2; earth =true;
		break;
		case STREAM: 
			endName = "of the stream";
			intellect += lvl*5; speed -= 0.3;
		break;
		case IMAGINATION: 
			endName = "of imaginaton";
			agility += lvl*4; intellect += lvl*2; luck += lvl*2; ice = true; lightning = true;
		break;
		case RAIDER: 
			endName = "of the raider";
			strength += lvl*2; stamina += lvl*4;
		break;
		case THIEF: 
			endName = "of the thief";
			agility += lvl*7; luck += lvl*3; speed -= 0.2;
		break;
		case MOON:
			endName = "of the moon";
			intellect += lvl*6; strength += lvl*3;
		break;
		case JOKER:
			endName = "of the joker";
			intellect += lvl*1; strength += lvl*1; agility += lvl*1;
		break;
	}

	name += midName + endName;

	return new Weapon(*filePath, name, value, stamina, agility, strength, intellect, luck, reqLvl, rarity, minDamage, maxDamage, speed, range, fire, ice, earth, lightning);
}

Armor* ItemDesigner::createArmor(int lvl, int quality, int type, int power){
	string midName, endName;
	int defense = 0, magicResist = 0, armorSlot = 0, rndNum, rndLvl;

	*filePath = "images/game_btn.png";

	rndLvl = rand() % 3;

	if(rand() % 2 < 1){
		reqLvl = lvl-rndLvl;
	}else{
		reqLvl = lvl+rndLvl;
	}

	setQuality(quality, lvl);

	switch(quality){
		case WEAK:
			defense = lvl*1; magicResist = lvl*1;
		break;
		case DULL: 
			defense = lvl*0.5; magicResist = lvl*1;
		break;
		case PATHETIC:
			defense = lvl*0.5; magicResist = lvl*0.5;
		break;
		case SILLY:
			defense = lvl*1; magicResist = lvl*2;
		break;
		case BENDY: 
			defense = lvl*2; magicResist = lvl*1;
		break;
		case HEROIC: 
			defense = lvl*4; magicResist = lvl*1;
		break;
		case SWIFT: 
			defense = lvl*1; magicResist = lvl*4;
		break;
		case SHARP:
			defense = lvl*5;
		break;
		case EPIC: 
			defense = lvl*5; magicResist = lvl*5;
		break;
		case GREAT: 
			defense = lvl*3; magicResist = lvl*6;
		break;
		case OLD: 
			magicResist = lvl*10;
		break;
		case POWERFUL: 
			defense = lvl*10;
		break;
		case MAJESTIC: 
			magicResist = lvl*15;
		break;
		case UNIQUE: 
			defense = lvl*10; magicResist = lvl*7;
		break;
		case POINTLESS: 
			defense = lvl*0.1; magicResist = lvl*1;
		break;
		case GODLY: 
			defense = lvl*15; magicResist = lvl*15;
		break;
		case RANDOM: 
			defense = lvl*rarity*5; magicResist = lvl*rarity*5;
		break;
		case SANTA:
			defense = lvl*10; magicResist = lvl*20;
		break;
		case DOLEY:
			defense = lvl*0.2; magicResist = lvl*0.4;
		break;
	}

	rndNum = rand() % 3;

	if(rndNum < 1){
		rndNum = 1;
	}

	switch(type){
	case HANDS: 
		midName = "gauntlets ";
		armorSlot = 3;
		stamina += lvl*2;
		if(rndNum == 1){ strength += lvl*2; }else if(rndNum == 2){ agility += lvl*2; }else if(rndNum == 3){ intellect += lvl*2; }
	break;
	case FEET:
		midName = "boots ";
		armorSlot = 1;
		stamina += lvl*2;
		if(rndNum == 1){ strength += lvl*2; }else if(rndNum == 2){ agility += lvl*2; }else if(rndNum == 3){ intellect += lvl*2; }
	break;
	case HEAD: 
		midName = "helm ";
		armorSlot = 5;
		stamina += lvl*4;
		if(rndNum == 1){ strength += lvl*4; }else if(rndNum == 2){ agility += lvl*4; }else if(rndNum == 3){ intellect += lvl*4; }
	break;
	case CHEST: 
		midName = "breastplate ";
		armorSlot = 4;
		stamina += lvl*10;
		if(rndNum == 1){ strength += lvl*10; }else if(rndNum == 2){ agility += lvl*10; }else if(rndNum == 3){ intellect += lvl*10; }
	break;
	case LEGS:
		midName = "leggings ";
		armorSlot = 2;
		stamina += lvl*7;
		if(rndNum == 1){ strength += lvl*7; }else if(rndNum == 2){ agility += lvl*7; }else if(rndNum == 3){ intellect += lvl*7; }
	break;
	}

	endName = setPower(power, lvl);

	name += midName + endName;

	return new Armor(*filePath, name, value, stamina, agility, strength, intellect, luck, reqLvl, rarity, defense, magicResist, armorSlot);
}

Consumable* ItemDesigner::createConsumable(int lvl, int quality, int type){
	int health, mana;
	string endName;

	*filePath = "images/game_btn.png";

	setQuality(quality, lvl);

	stamina = agility = strength = intellect = luck = rarity = health = mana = 0;
	reqLvl = lvl;

	value = lvl* 50;
	
	switch(type){
	case BREAD: 
		endName = "bread";
		health = lvl*100; rarity = 1;
	break;
	case CHEESE:
		endName = "cheese";
		health = lvl*115; rarity = 1;
	break;
	case MILK: 
		endName = "milk";
		mana = lvl*100; rarity = 1;
	break;
	case MANAPOT: 
		endName = "mana potion";
		mana = lvl*250; rarity = 2;
	break;
	case HEALTHPOT:
		endName = "health potion";
		health = lvl*250; rarity =2;
	break;
	case CAKE: 
		endName = "cake";
		health = lvl*100; mana = lvl*100; rarity = 2;
	break;
	case ORANGE: 
		endName = "orange";
		health = lvl*100; mana = lvl*50; rarity = 1;
	break;
	case APPLE: 
		endName = "apple";
		health = lvl*50; mana = lvl*100; rarity = 1;
	break;
	case CHERRY:  
		endName = "cherry";
		health = lvl*25; health = lvl*25; rarity = 1;
	break;
	case WATER:  
		endName = "water"; rarity = 1;
		mana = lvl*200;
	break;
	case BEER: 
		endName = "beer";
		health = -lvl*25; mana = lvl*50; rarity = 2;
	break;
	}

	name += endName;

	return new Consumable(*filePath, name, value, reqLvl, rarity, health, mana);
}

void ItemDesigner::setQuality(int quality, int lvl){
	switch(quality){
		case WEAK:
			name = "Weak ";
			value = lvl*100; stamina = lvl*1; rarity = 1;
		break;
		case DULL: 
			name = "Dull ";
			value = lvl*95; agility = lvl*1;rarity = 1;
		break;
		case PATHETIC:
			name = "Pathetic ";
			value = lvl*90; strength = lvl*0.5; rarity = 1;
		break;
		case SILLY:
			name = "Silly ";
			value = lvl*100; intellect = lvl*0.8; rarity = 1;
		break;
		case BENDY: 
			name = "Bendy ";
			value = lvl*150; stamina = lvl*0.2; agility = lvl*2; rarity = 2;
		break;
		case HEROIC: 
			name = "Heroic ";
			value = lvl*300; stamina = lvl*4; strength = lvl*5; rarity = 4;
		break;
		case SWIFT: 
			name = "Swift ";
			value = lvl*200; stamina = lvl*2; agility = lvl*5; rarity = 3;
		break;
		case SHARP:
			name = "Sharp ";
			value = lvl*250; strength = lvl*3; stamina = lvl*2; rarity = 1;
		break;
		case EPIC: 
			name = "Epic ";
			value = lvl*500; strength = lvl*10; stamina = lvl*8; agility = lvl*5; intellect = lvl*4; rarity = 5;
		break;
		case GREAT: 
			name = "Great ";
			value = lvl*300; strength = lvl*5; stamina = lvl*5; agility = lvl*5; intellect = lvl*3; rarity = 3;
		break;
		case OLD: 
			name = "Old ";
			value = lvl*100; strength = lvl*1; intellect = lvl*5; rarity = 2;
		break;
		case POWERFUL: 
			name = "Powerful ";
			value = lvl*500; stamina = lvl*10; intellect = lvl*15; rarity = 5;
		break;
		case MAJESTIC: 
			name = "Majestic ";
			value = lvl*500; stamina = lvl*5; agility = lvl*20; luck = lvl*2; rarity = 5;
		break;
		case UNIQUE: 
			name = "Unique ";
			value = lvl*500; stamina = lvl*40; rarity = 5;
		break;
		case POINTLESS: 
			name = "Pointless ";
			value = lvl*90; strength = lvl*1; stamina = lvl*0.3; rarity = 1;
		break;
		case GODLY: 
			name = "Godly ";
			value = lvl*1000; strength = lvl*25; stamina = lvl*25; agility = lvl*25; intellect = lvl*25; rarity = 6;
		break;
		case RANDOM: 
			name = "Random ";
			int tempRnd;
			tempRnd = rand() % 6;

			if(tempRnd < 1){
				tempRnd = 1;
			}

			value = lvl*tempRnd*100; strength = lvl*tempRnd*5; stamina = lvl*tempRnd*5; agility = lvl*tempRnd*5; intellect = lvl*tempRnd*5; rarity = tempRnd;
		break;
		case SANTA:
			name = "Santa's ";
			value = lvl*1000; stamina = lvl*30; intellect = lvl*25; luck = lvl*25; rarity = 6;
		break;
		case DOLEY:
			name = "Doley ";
			value = lvl*200; rarity = 2;
		break;
	}
}

string ItemDesigner::setPower(int power, int lvl){
	switch(power){
		case STORM: 
			agility += lvl*3; strength += lvl*2; luck = lvl*0.6;
			return "of the storm";
		break;
		case ZEPHYR: 
			agility += lvl*4; luck += lvl*1.1;
			return "of the zephyr";
		break;
		case POWER: 
			intellect += lvl*3; stamina += lvl*2;
			return "of power";
		break;
		case WINTER: 
			return "of winter";
		break;
		case NIGHT: 
			agility += 4; stamina += 1;
			return "of night";
		break;
		case ELEMENTS:
			return "of the elements";
		break;
		case ACCURACY:
			luck += lvl*1.5;
			return "of accuracy";
		break;
		case FIRE: 
			return "of fire";
		break;
		case ICE: 
			return "of ice";
		break;
		case EARTH: 
			return "of the earth";
		break;
		case LIGHTNING:
			return "of lightning";
		break;
		case GODS:
			stamina += lvl*6;
			return "of the gods";
		break;
		case UNICORN: 
			strength += lvl*2; agility += lvl*2; intellect += lvl*2; luck += lvl*7;
			return "of the unicorn";
		break;
		case MOUNTAIN: 
			strength += lvl*4; stamina += lvl*2;
			return "of the mountain";
		break;
		case STREAM: 
			intellect += lvl*5;
			return "of the stream";
		break;
		case IMAGINATION: 
			agility += lvl*4; intellect += lvl*2; luck += lvl*2;
			return "of imaginaton";
		break;
		case RAIDER: 
			strength += lvl*2; stamina += lvl*4;
			return "of the raider";
		break;
		case THIEF: 
			agility += lvl*7; luck += lvl*3;
			return "of the thief";
		break;
		case MOON:
			intellect += lvl*6; strength += lvl*3;
			return"of the moon";
		break;
		case JOKER:
			intellect += lvl*1; strength += lvl*1; agility += lvl*1;
			return "of the joker";
		break;
	}
}