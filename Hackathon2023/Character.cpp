#include "Character.hpp"

void Character::Inventory(int pos, int dmgMod, std::string weaponType, std::string weaponName, Maintain maintain)
{
	Accessories invSlots[9] = { {0, "", ""}, {0, "", ""}, {0, "", ""}, {0, "", ""}, 
		{0, "", ""}, {0, "", ""}, {0, "", ""}, {0, "", ""}, {0, "", ""} };
	invSlots[pos].weaponName = weaponName;
	invSlots[pos].weaponType = weaponType;
	std::cout << invSlots[pos].weaponType << " \"" << invSlots[pos].weaponName << "\"" << std::endl;
}

Character Enemy(int enemyType)
{
    Character thisEnemy;
    if (enemyType == 1)
    {
        thisEnemy.Name = "Slime";
        thisEnemy.Health = 50;
        thisEnemy.Atk = 15;
        thisEnemy.Def = 2;
        thisEnemy.SpD = 20;
    }
    else if (enemyType == 2)
    {
        thisEnemy.Name = "Goblin";
        thisEnemy.Health = 65;
        thisEnemy.Atk = 10;
        thisEnemy.Def = 1;
        thisEnemy.SpD = 40;
    }
    else if (enemyType == 3)
    {
        thisEnemy.Name = "Giant Frog";
        thisEnemy.Health = 85;
        thisEnemy.Atk = 20;
        thisEnemy.Def = 4;
        thisEnemy.SpD = 30;
    }
    else
    {
        thisEnemy.Name = "None";
        thisEnemy.Health = 0;
        thisEnemy.Atk = 0;
        thisEnemy.Def = 0;
        thisEnemy.SpD = 0;
    }
    return thisEnemy;
}