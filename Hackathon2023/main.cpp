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
    
    Accessories Helmets[6] = { {10, COMMON, "Cap", "Cap"}, {10, COMMON, "Chaincap", "Chaincap"}, {15, RARE, "Ironhelm", "Ironhelm"},
        {15, RARE, "Hood", "Hood"}, {20, EPIC, "Steelhelm", "Steelhelm"}, {25, LEGENDARY, "Templarhelm", "Templarhelm"}};
    
    Accessories ChestPiece[6] = { {2, COMMON, "Rags", "Rags"}, {3, COMMON, "Robes", "Robes"}, {5, RARE, "Chestplate", "Chestplate"},
        {5, RARE, "Chainmail", "Chainmail"}, {7, EPIC, "Heavyplate", "Heavyplate"}, {10, LEGENDARY, "Templarplate", "Templarplate"} };

    Accessories Weapons[6] = { {3, COMMON, "Dagger", "Dagger" }, { 3, COMMON, "Knife", "Knife" }, {4, RARE, "Sword", "Sword"}, 
        {4, RARE, "Hatchet", "Hatchet"}, {5, EPIC, "Axe", "Axe"}, {6, LEGENDARY, "Longsword", "Longsword"} };

    Accessories Boots[6] = { {5, COMMON, "Tornboot", "Tornboot"}, {5, COMMON, "Peasantboots", "Peasantboots"}, {10, RARE, "Greaves", "Greaves"},
        {15, RARE, "Bootshoe", "Bootshoe"}, {20, EPIC, "Steeltipped", "Steeltipped"}, {30, LEGENDARY, "Templarboots", "Templarboots"}};

    Accessories floorItem = { 0, NONE, "Empty", "Empty" };
   
    Character player;
    player.Health = 100;
    player.Atk = 35;
    player.Def = 5;
    player.SpD = 25;
    Character enemy;
    BigBoss boss;

    floorItem = player.Inventory(1, 5, "Knife", LEGENDARY, "Long Burger", VIEW, invSlots);
    player.Inventory(1, 5, "Knife", LEGENDARY, "Long Burger",PICKUP, invSlots);
    player.Inventory(1, 5, "Knife", LEGENDARY, "Long Burger", VIEW, invSlots);
    floorItem = player.Inventory(1, 5, "Knife", LEGENDARY, "Long Burger", DROP, invSlots);

    enemy = Enemy(3);
    std::cout << enemy.Name << std::endl;

    player.Helmet.attributeMod = 0;

    attack(enemy, player, 0);
    heal(player, 3);


    return 0;
}