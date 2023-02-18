#pragma once
#include "hackathon.hpp"
#include "Accessories.hpp"

typedef enum maintain
{
	NONE = 0, PICKUP = 1, DROP = 2
}Maintain;

class Character {
public:
	std::string Name;
	int Health; //100 
	int Atk; //35
	int Def; //5
	int SpD; //25
	void Inventory(int pos, int dmgMod, std::string weaponType, std::string weaponName, Maintain maintain);
	Accessories Helmet;
	Accessories Chestplate;
	Accessories Weapon;
	Accessories Boots;
};

Character Enemy(int enemyType);