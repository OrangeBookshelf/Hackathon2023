#pragma once
#include "hackathon.hpp"

typedef enum rarity
{
	NONE = 0, COMMON = 1, RARE = 2, EPIC = 3, LEGENDARY = 4
}Rarity;

class Accessories
{
public:
	int attributeMod;
	Rarity itemRarity;
	std::string weaponType;
	std::string weaponName;
};