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

    Player.Health = 100;
    Player.Atk = 35;
    Player.Def = 5;
    Player.SpD = 25;

    Accessories tempItem;
    tempItem.attributeMod = 0;
    tempItem.itemRarity = NONE;
    tempItem.weaponName = "Empty";
    tempItem.weaponType = "Empty";

    if (whichType == "Helmet")
    {
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
//Determines which enemy is encounted or if none
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
//Determines which boss is going to be fought or none at all
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