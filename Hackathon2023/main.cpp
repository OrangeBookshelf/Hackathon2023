#include "hackathon.hpp"
#include "Accessories.hpp"
#include "Character.hpp"
#include "dungeon.hpp"
#include "dungeonTest.hpp"

int main(void) 
{
    srand(time(NULL));
    int menuChoice = 0, floor = 1, room = 0;

    std::cout << R"(
000   0  0  0  0   00   0000   00   0  0     000   000  0   0  0000  000   000
0  0  0  0  00 0  0     0     0  0  00 0     0  0   0   0   0  0     0  0  0
0  0  0  0  0 00  0 00  000   0  0  0 00     0  0   0    0 0   000   000   000
0  0  0  0  0  0  0  0  0     0  0  0  0     0  0   0    0 0   0     0 0     0
000    00   0  0   00   0000   00   0  0     000   000    0    0000  0  0  000
)" << std::endl;

    do
    {
        std::cout << "1: Play\n2: Quit" << std::endl;
        std::cin >> menuChoice;
    } while(menuChoice < 1 || menuChoice > 2);

    if (menuChoice == 1)
    {
        testSetFloor();
        system("pause");
        system("cls");

        //this is where the entire program goes
         
        while (floor != 5)
        {
            




            floor++;
        }


    }
    Accessories invSlots[9] = { {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"},
    {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"} };
    //modifies health
    Accessories Helmets[6] = { {10, COMMON, "Helmet", "Cap"}, {10, COMMON, "Helmet", "Chaincap"}, {15, RARE, "Helmet", "Ironhelm"},
        {15, RARE, "Helmet", "Hood"}, {20, EPIC, "Helmet", "Steelhelm"}, {25, LEGENDARY, "Helmet", "Templarhelm"}};
    //modifies defense
    Accessories ChestPiece[6] = { {2, COMMON, "ChestPiece", "Rags"}, {3, COMMON, "ChestPiece", "Robes"}, {5, RARE, "ChestPiece", "Chestplate"},
        {5, RARE, "ChestPiece", "Chainmail"}, {7, EPIC, "ChestPiece", "Heavyplate"}, {10, LEGENDARY, "ChestPiece", "Templarplate"} };
    //modifies attack
    Accessories Weapons[6] = { {3, COMMON, "Weapons", "Dagger" }, { 3, COMMON, "Weapons", "Knife" }, {4, RARE, "Weapons", "Sword"}, 
        {4, RARE, "Weapons", "Hatchet"}, {5, EPIC, "Weapons", "Axe"}, {6, LEGENDARY, "Weapons", "Longsword"} };
    //modifies speed
    Accessories Boots[6] = { {5, COMMON, "Boots", "Tornboot"}, {5, COMMON, "Boots", "Peasantboots"}, {10, RARE, "Boots", "Greaves"},
        {15, RARE, "Boots", "Bootshoe"}, {20, EPIC, "Boots", "Steeltipped"}, {30, LEGENDARY, "Boots", "Templarboots"}};

    Accessories floorItem = { 0, NONE, "Empty", "Empty" };
   
    Character player;
    player.Health = 100;
    player.Atk = 35;
    player.Def = 5;
    player.SpD = 25;

    Character enemy;
    BigBoss boss;

    floorItem = player.Inventory(1, 5, "Weapons", LEGENDARY, "Long Burger", VIEW, invSlots);
    player.Inventory(1, 5, "Weapons", LEGENDARY, "Long Burger",PICKUP, invSlots);
    player.Inventory(1, 5, "Weapons", LEGENDARY, "Long Burger", VIEW, invSlots);
   // floorItem = player.Inventory(1, 5, "Weapons", LEGENDARY, "Long Burger", DROP, invSlots);

    std::cout << invSlots[1].weaponName << std::endl;

    characterEquip(1, invSlots, player);
    std::cout << player.Atk << std::endl;

    player.Inventory(1, 3, "Weapons", LEGENDARY, "Small Burger", PICKUP, invSlots);
    characterEquip(1, invSlots, player);
    std::cout << player.Atk << std::endl;
    std::cout << invSlots[1].weaponName << std::endl;

    enemy = Enemy(3);
    std::cout << enemy.Name << std::endl;

    player.Helmet.attributeMod = 0;

    attack(enemy, player, 0);
    heal(player, 3);


    return 0;
}