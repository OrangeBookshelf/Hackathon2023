#pragma once
#include "hackathon.hpp"
#include "Accessories.hpp"

typedef enum maintain
{
	VIEW = 0, PICKUP = 1, DROP = 2
}Maintain;

class Character 
{
public:
	std::string Name;
	int Health; //100 
	int Atk; //35
	int Def; //5
	int SpD; //25
	Accessories Inventory(int pos, int dmgMod, std::string weaponType,
		std::string weaponName, Maintain maintain, Accessories(&MySlots)[9]);
	Accessories Helmet;
	Accessories Chestplate;
	Accessories Weapon;
	Accessories Boots;
};

Character Enemy(int enemyType);

void attack(Character attacker, Character defender, int prep);

void heal(Character player, int prep);