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
	Accessories Inventory(int pos, int dmgMod, std::string weaponType, Rarity howRare,
		std::string weaponName, Maintain maintain, Accessories(&MySlots)[9]);
	Accessories Helmet;
	Accessories Chestplate;
	Accessories Weapon;
	Accessories Boots;
};

class BigBoss
{
public:
	std::string Name;
	int Health;
	int Atk;
	int Def;
	int SpD;
};

Character Enemy(int enemyType);
BigBoss Boss(int bossType);

void attack(Character attacker, Character defender, int prep);

void heal(Character player, int prep);
void characterEquip();
Character Enemy(int enemyType);

void bossAttack(BigBoss attacker, Character defender);
void attackBoss(BigBoss defender, Character attacker, int prep);