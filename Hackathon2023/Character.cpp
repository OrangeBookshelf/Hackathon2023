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
        tempItem.attributeMod = MySlots[pos].attributeMod;
        tempItem.itemRarity = MySlots[pos].itemRarity;
        tempItem.weaponName = MySlots[pos].weaponName;
        tempItem.weaponType = MySlots[pos].weaponType;
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
//Equips accessory in a specific position
void characterEquip(int pos, Accessories(&MySlots)[9], Character& Player)
{
    std::string whichType = MySlots[pos].weaponType;

    Accessories tempItem;
    tempItem.attributeMod = 0;
    tempItem.itemRarity = NONE;
    tempItem.weaponName = "Empty";
    tempItem.weaponType = "Empty";

    if (whichType == "Helmet")
    {
        Player.Health = 100;
        tempItem.attributeMod = Player.Helmet.attributeMod;
        tempItem.itemRarity = Player.Helmet.itemRarity;
        tempItem.weaponName = Player.Helmet.weaponName;
        tempItem.weaponType = Player.Helmet.weaponType;
        Player.Helmet.attributeMod = MySlots[pos].attributeMod;
        Player.Helmet.itemRarity = MySlots[pos].itemRarity;
        Player.Helmet.weaponName = MySlots[pos].weaponName;
        Player.Helmet.weaponType = MySlots[pos].weaponType;
        MySlots[pos].attributeMod = tempItem.attributeMod;
        MySlots[pos].itemRarity = tempItem.itemRarity;
        MySlots[pos].weaponName = tempItem.weaponName;
        MySlots[pos].weaponType = tempItem.weaponType;

        Player.Health += Player.Helmet.attributeMod;
    }
    else if (whichType == "ChestPiece")
    {
        Player.Def = 5;

        tempItem.attributeMod = Player.Chestplate.attributeMod;
        tempItem.itemRarity = Player.Chestplate.itemRarity;
        tempItem.weaponName = Player.Chestplate.weaponName;
        tempItem.weaponType = Player.Chestplate.weaponType;
        Player.Chestplate.attributeMod = MySlots[pos].attributeMod;
        Player.Chestplate.itemRarity = MySlots[pos].itemRarity;
        Player.Chestplate.weaponName = MySlots[pos].weaponName;
        Player.Chestplate.weaponType = MySlots[pos].weaponType;
        MySlots[pos].attributeMod = tempItem.attributeMod;
        MySlots[pos].itemRarity = tempItem.itemRarity;
        MySlots[pos].weaponName = tempItem.weaponName;
        MySlots[pos].weaponType = tempItem.weaponType;

        Player.Def += Player.Chestplate.attributeMod;
    }
    else if (whichType == "Weapons")
    {
        Player.Atk = 35;
        tempItem.attributeMod = Player.Weapon.attributeMod;
        tempItem.itemRarity = Player.Weapon.itemRarity;
        tempItem.weaponName = Player.Weapon.weaponName;
        tempItem.weaponType = Player.Weapon.weaponType;
        Player.Weapon.attributeMod = MySlots[pos].attributeMod;
        Player.Weapon.itemRarity = MySlots[pos].itemRarity;
        Player.Weapon.weaponName = MySlots[pos].weaponName;
        Player.Weapon.weaponType = MySlots[pos].weaponType;
        MySlots[pos].attributeMod = tempItem.attributeMod;
        MySlots[pos].itemRarity = tempItem.itemRarity;
        MySlots[pos].weaponName = tempItem.weaponName;
        MySlots[pos].weaponType = tempItem.weaponType;

        Player.Atk += Player.Weapon.attributeMod;
    }
    else if (whichType == "Boots")
    {
        Player.SpD = 25;

        tempItem.attributeMod = Player.Boots.attributeMod;
        tempItem.itemRarity = Player.Boots.itemRarity;
        tempItem.weaponName = Player.Boots.weaponName;
        tempItem.weaponType = Player.Boots.weaponType;
        Player.Boots.attributeMod = MySlots[pos].attributeMod;
        Player.Boots.itemRarity = MySlots[pos].itemRarity;
        Player.Boots.weaponName = MySlots[pos].weaponName;
        Player.Boots.weaponType = MySlots[pos].weaponType;
        MySlots[pos].attributeMod = tempItem.attributeMod;
        MySlots[pos].itemRarity = tempItem.itemRarity;
        MySlots[pos].weaponName = tempItem.weaponName;
        MySlots[pos].weaponType = tempItem.weaponType;

        Player.SpD += Player.Boots.attributeMod;
    }
}

void printInventory(Accessories(&MySlots)[9], Character& Player)
{
    int i = 0;
    std::string temp = "Helmet";
    std::string piecePrint = Player.Helmet.weaponName;
    int attributeChange = Player.Helmet.attributeMod;
    for (i = 0; i < 4; i++)
    {
        if (i == 1)
        {
            temp = "Chestpiece";
            piecePrint = Player.Chestplate.weaponName;
            attributeChange = Player.Chestplate.attributeMod;
        }
        else if (i == 2)
        {
            temp = "Weapon";
            piecePrint = Player.Weapon.weaponName;
            attributeChange = Player.Weapon.attributeMod;
        }
        else
        {
            temp = "Boots";
            piecePrint = Player.Boots.weaponName;
            attributeChange = Player.Boots.attributeMod;
        }
        std::cout << temp << " " << piecePrint << " - +" << attributeChange << "modifier" << std::endl;
    }
    std::cout << "\n";
    for (i = 0; i < 9; i++)
    {
        std::cout << "[" << i+1 << "] " << MySlots[i].weaponType << " " << MySlots[i].weaponName << " - +" << MySlots[i].attributeMod << " modifier\n";
    }
}

//Determines which enemy is encounted or if none
Character Enemy(int enemyType, int& levelTier)
{
    Character thisEnemy;
    if (levelTier == 1)
    {
       if (enemyType == 1)
       {
            thisEnemy.Name = "Slime";
            thisEnemy.Health = 50;
            thisEnemy.Atk = 15;
            thisEnemy.Def = 2;
            thisEnemy.SpD = 20;
            thisEnemy.tier = 1;
       }
       else if (enemyType == 2)
       {
            thisEnemy.Name = "Goblin";
            thisEnemy.Health = 65;
            thisEnemy.Atk = 10;
            thisEnemy.Def = 1;
            thisEnemy.SpD = 40;
            thisEnemy.tier = 1;
       }
        else if (enemyType == 3)
        {
            thisEnemy.Name = "Giant Frog";
            thisEnemy.Health = 85;
            thisEnemy.Atk = 20;
            thisEnemy.Def = 4;
            thisEnemy.SpD = 30;
            thisEnemy.tier = 1;
        }
        else
        {
            thisEnemy.Name = "None";
            thisEnemy.Health = 0;
            thisEnemy.Atk = 0;
            thisEnemy.Def = 0;
            thisEnemy.SpD = 0;
        }
    }
    else if (levelTier == 2)
    {
        if (enemyType == 1)
        {
            thisEnemy.Name = "Slime LVL 2";
            thisEnemy.Health = 60;
            thisEnemy.Atk = 25;
            thisEnemy.Def = 4;
            thisEnemy.SpD = 30;
            thisEnemy.tier = 2;
        }
        else if (enemyType == 2)
        {
            thisEnemy.Name = "Goblin LVL2";
            thisEnemy.Health = 75;
            thisEnemy.Atk = 20;
            thisEnemy.Def = 2;
            thisEnemy.SpD = 50;
            thisEnemy.tier = 2;
        }
        else if (enemyType == 3)
        {
            thisEnemy.Name = "Giant Frog LVL2";
            thisEnemy.Health = 95;
            thisEnemy.Atk = 30;
            thisEnemy.Def = 6;
            thisEnemy.SpD = 40;
            thisEnemy.tier = 2;
        }
        else
        {
            thisEnemy.Name = "None";
            thisEnemy.Health = 0;
            thisEnemy.Atk = 0;
            thisEnemy.Def = 0;
            thisEnemy.SpD = 0;
        }
    }
    else if (levelTier == 3)
    {
        if (enemyType == 1)
        {
            thisEnemy.Name = "Slime LVL 3";
            thisEnemy.Health = 70;
            thisEnemy.Atk = 35;
            thisEnemy.Def = 6;
            thisEnemy.SpD = 40;
            thisEnemy.tier = 3;
        }
        else if (enemyType == 2)
        {
            thisEnemy.Name = "Goblin LVL3";
            thisEnemy.Health = 85;
            thisEnemy.Atk = 30;
            thisEnemy.Def = 5;
            thisEnemy.SpD = 60;
            thisEnemy.tier = 3;
        }
        else if (enemyType == 3)
        {
            thisEnemy.Name = "Giant Frog LVL3";
            thisEnemy.Health = 105;
            thisEnemy.Atk = 40;
            thisEnemy.Def = 8;
            thisEnemy.SpD = 50;
            thisEnemy.tier = 3;
        }
        else
        {
            thisEnemy.Name = "None";
            thisEnemy.Health = 0;
            thisEnemy.Atk = 0;
            thisEnemy.Def = 0;
            thisEnemy.SpD = 0;
        }
    }

    return thisEnemy;
}
//Determines loot pools for enemies
Accessories itemLootpool(Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
    Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier)
{
    Accessories tempLoot;
    tempLoot.attributeMod = 0;
    tempLoot.itemRarity = NONE;
    tempLoot.weaponName = "Empty";
    tempLoot.weaponType = "Empty";
    
    int oddsIncrease = levelTier - 1;

    int random = rand() % 20 + 1;
    if (random <= 10 - oddsIncrease)
    {
        tempLoot.itemRarity = COMMON;
    }
    else if (random > 11 - oddsIncrease && random <= 15)
    {
        tempLoot.itemRarity = RARE;
    }
    else if (random > 15 - oddsIncrease && random <= 19)
    {
        tempLoot.itemRarity = EPIC;
    }
    else
    {
        tempLoot.itemRarity = LEGENDARY;
    }

    int piece = rand() % 4 + 1;
    int findWhichItem = rand() % 2;
    switch (piece)
    {
    //helmet
    case 1:
        tempLoot.weaponType = "Helmet";
        if (tempLoot.itemRarity == COMMON)
        {
            tempLoot.weaponName = Helms[findWhichItem].weaponName;
            tempLoot.attributeMod = Helms[findWhichItem].attributeMod;
        }
        else if (tempLoot.itemRarity == RARE)
        {
            tempLoot.weaponName = Helms[findWhichItem + 2].weaponName;
            tempLoot.attributeMod = Helms[findWhichItem + 2].attributeMod;
        }
        else if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.weaponName = Helms[4].weaponName;
            tempLoot.attributeMod = Helms[4].attributeMod;
        }
        else
        {
            tempLoot.weaponName = Helms[5].weaponName;
            tempLoot.attributeMod = Helms[5].attributeMod;
        }
        break;
    //chestpiece
    case 2:
        tempLoot.weaponType = "ChestPiece";
        if (tempLoot.itemRarity == COMMON)
        {
            tempLoot.weaponName = Chest[findWhichItem].weaponName;
            tempLoot.attributeMod = Chest[findWhichItem].attributeMod;
        }
        else if (tempLoot.itemRarity == RARE)
        {
            tempLoot.weaponName = Chest[findWhichItem + 2].weaponName;
            tempLoot.attributeMod = Chest[findWhichItem + 2].attributeMod;
        }
        else if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.weaponName = Chest[4].weaponName;
            tempLoot.attributeMod = Chest[4].attributeMod;
        }
        else
        {
            tempLoot.weaponName = Chest[5].weaponName;
            tempLoot.attributeMod = Chest[5].attributeMod;
        }
        break;
    //weapon
    case 3:
        tempLoot.weaponType = "Weapons";
        if (tempLoot.itemRarity == COMMON)
        {
            tempLoot.weaponName = Weapon[findWhichItem].weaponName;
            tempLoot.attributeMod = Weapon[findWhichItem].attributeMod;
        }
        else if (tempLoot.itemRarity == RARE)
        {
            tempLoot.weaponName = Weapon[findWhichItem + 2].weaponName;
            tempLoot.attributeMod = Weapon[findWhichItem + 2].attributeMod;
        }
        else if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.weaponName = Weapon[4].weaponName;
            tempLoot.attributeMod = Weapon[4].attributeMod;
        }
        else
        {
            tempLoot.weaponName = Weapon[5].weaponName;
            tempLoot.attributeMod = Weapon[5].attributeMod;
        }
        break;
    //boots
    case 4:
        tempLoot.weaponType = "Boots";
        if (tempLoot.itemRarity == COMMON)
        {
            tempLoot.weaponName = Boots[findWhichItem].weaponName;
            tempLoot.attributeMod = Boots[findWhichItem].attributeMod;
        }
        else if (tempLoot.itemRarity == RARE)
        {
            tempLoot.weaponName = Boots[findWhichItem + 2].weaponName;
            tempLoot.attributeMod = Boots[findWhichItem + 2].attributeMod;
        }
        else if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.weaponName = Boots[4].weaponName;
            tempLoot.attributeMod = Boots[4].attributeMod;
        }
        else
        {
            tempLoot.weaponName = Boots[5].weaponName;
            tempLoot.attributeMod = Boots[5].attributeMod;
        }
        break;
    }
    return tempLoot;
}

Accessories bossLootpool(Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
    Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier)
{
    Accessories tempLoot;
    tempLoot.attributeMod = 0;
    tempLoot.itemRarity = NONE;
    tempLoot.weaponName = "Empty";
    tempLoot.weaponType = "Empty";

    int findRarity = rand() % 4 + 1;

    int findType = rand() % 4 + 1;

    if (findRarity != 4)
    {
        tempLoot.itemRarity = EPIC;
    }
    else
    {
        tempLoot.itemRarity = LEGENDARY;
    }

    switch (findType)
    {
    //helmet
    case 1:
        if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.attributeMod = Helms[4].attributeMod;
            tempLoot.weaponName = Helms[4].weaponName;
            tempLoot.weaponType = Helms[4].weaponType;
        }
        else
        {
            tempLoot.attributeMod = Helms[5].attributeMod;
            tempLoot.weaponName = Helms[5].weaponName;
            tempLoot.weaponType = Helms[5].weaponType;
        }
        break;
    //chest
    case 2:
        if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.attributeMod = Chest[4].attributeMod;
            tempLoot.weaponName = Chest[4].weaponName;
            tempLoot.weaponType = Chest[4].weaponType;
        }
        else
        {
            tempLoot.attributeMod = Chest[5].attributeMod;
            tempLoot.weaponName = Chest[5].weaponName;
            tempLoot.weaponType = Chest[5].weaponType;
        }
        break;
    //weapon
    case 3:
        if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.attributeMod = Weapon[4].attributeMod;
            tempLoot.weaponName = Weapon[4].weaponName;
            tempLoot.weaponType = Weapon[4].weaponType;
        }
        else
        {
            tempLoot.attributeMod = Weapon[5].attributeMod;
            tempLoot.weaponName = Weapon[5].weaponName;
            tempLoot.weaponType = Weapon[5].weaponType;
        }
        break;
    //boots
    case 4:
        if (tempLoot.itemRarity == EPIC)
        {
            tempLoot.attributeMod = Boots[4].attributeMod;
            tempLoot.weaponName = Boots[4].weaponName;
            tempLoot.weaponType = Boots[4].weaponType;
        }
        else
        {
            tempLoot.attributeMod = Boots[5].attributeMod;
            tempLoot.weaponName = Boots[5].weaponName;
            tempLoot.weaponType = Boots[5].weaponType;
        }
        break;
    }
    return tempLoot;
}

//Determines which boss is going to be fought or none at all
BigBoss Boss(int bossType)
{
    BigBoss thisBoss;
    if (bossType == 1)
    {
        thisBoss.Name = "Paladin";
        thisBoss.Health = 100;
        thisBoss.Atk = 40;
        thisBoss.Def = 15;
        thisBoss.SpD = 15;
    }
    else if (bossType == 2)
    {
        thisBoss.Name = "Direwolf";
        thisBoss.Health = 225;
        thisBoss.Atk = 40;
        thisBoss.Def = 7;
        thisBoss.SpD = 50;
    }
    else if (bossType == 3)
    {
        thisBoss.Name = "Centaur";
        thisBoss.Health = 125;
        thisBoss.Atk = 45;
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