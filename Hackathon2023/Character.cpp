#include "Character.hpp"

Accessories Character::Inventory(int pos, int dmgMod, std::string weaponType, Rarity howRare,
    std::string weaponName, Maintain maintain, Accessories (&MySlots)[9])
{
    Accessories tempItem;
    tempItem.attributeMod = 0;
    tempItem.itemRarity = NONE;
    tempItem.weaponName = "Empty";
    tempItem.weaponType = "Empty";

    //Reading Stats of Weapon
    if (maintain == VIEW)
    {
        std::cout << MySlots[pos].weaponType << " - - - \"" << MySlots[pos].weaponName << "\"\nDamage Modifier: "
            << MySlots[pos].attributeMod << std::endl;
    }    
    //Picking up a weapon
    else if (maintain == PICKUP)
    {
        MySlots[pos].attributeMod = dmgMod;
        MySlots[pos].itemRarity = howRare;
        MySlots[pos].weaponName = weaponName;
        MySlots[pos].weaponType = weaponType;
        std::cout << MySlots[pos].weaponType << " - - - \"" << MySlots[pos].weaponName << "\"\nDamage Modifier: "
            << MySlots[pos].attributeMod << std::endl;
    }
    //Dropping a weapon
    else if (maintain == DROP)
    {
        tempItem.attributeMod = MySlots[pos].attributeMod;
        tempItem.itemRarity = MySlots[pos].itemRarity;
        tempItem.weaponName = MySlots[pos].weaponName;
        tempItem.weaponType = MySlots[pos].weaponType;
        MySlots[pos].attributeMod = 0;
        MySlots[pos].itemRarity = NONE;
        MySlots[pos].weaponName = "Empty";
        MySlots[pos].weaponType = "Empty";
    }
    return tempItem;
}

void characterEquip()
{
    
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

BigBoss Boss(int bossType)
{
    BigBoss thisBoss;
    if (bossType == 1)
    {
        thisBoss.Name = "Paladin";
        thisBoss.Health = 250;
        thisBoss.Atk = 50;
        thisBoss.Def = 15;
        thisBoss.SpD = 15;
    }
    else if (bossType == 2)
    {
        thisBoss.Name = "Direwolf";
        thisBoss.Health = 500;
        thisBoss.Atk = 45;
        thisBoss.Def = 7;
        thisBoss.SpD = 50;
    }
    else if (bossType == 3)
    {
        thisBoss.Name = "Centaur";
        thisBoss.Health = 300;
        thisBoss.Atk = 55;
        thisBoss.Def = 5;
        thisBoss.SpD = 50;
    }
    else
    {
        thisBoss.Name = "None";
        thisBoss.Health = 0;
        thisBoss.Atk = 0;
        thisBoss.Def = 0;
        thisBoss.SpD = 0;
    }
    return thisBoss;
}