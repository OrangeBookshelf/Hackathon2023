#include "hackathon.hpp"
#include "Accessories.hpp"
#include "Character.hpp"
#include "dungeon.hpp"
#include "dungeonTest.hpp"

int main(void) 
{
    srand(time(NULL));
    int menuChoice = 0, floor = 1, room = 0;

    std::cout << "GAME NAME" << std::endl;
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
    Accessories invSlots[9] = { {0, "Empty", "Empty"}, {0, "Empty", "Empty"}, {0, "Empty", "Empty"}, {0, "Empty", "Empty"},
    {0, "Empty", "Empty"}, {0, "Empty", "Empty"}, {0, "Empty", "Empty"}, {0, "Empty", "Empty"}, {0, "Empty", "Empty"} };

    Accessories Helmets[6] = { {10, "Cap", "Cap"}, {10, "Chaincap", "Chaincap"}, {15, "Ironhelm", "Ironhelm"},
        {15, "Hood", "Hood"}, {20, "Steelhelm", "Steelhelm"}, {25, "Templarhelm", "Templarhelm"}};
    Accessories ChestPiece[6] = { {2, "Rags", "Rags"}, {3, "Robes", "Robes"}, {5, "Chestplate", "Chestplate"},
        {5, "Chainmail", "Chainmail"}, {7, "Heavyplate", "Heavyplate"}, {10, "Templarplate", "Templarplate"} };
    Accessories Weapons[6] = { {3, "Dagger", "Dagger" }, { 3, "Knife", "Knife" }, {4, "Sword", "Sword"}, 
        {4, "Hatchet", "Hatchet"}, {5, "Longsword", "Longsword"}, {5, "Axe", "Axe"}};
    Accessories Boots[6] = { {5, "Tornboot", "Tornboot"}, {5, "Peasantboots", "Peasantboots"}, {10, "Greaves", "Greaves"},
        {15, "Bootshoe", "Bootshoe"}, {20, "Steeltipped", "Steeltipped"}, {30, "Templarboots", "Templarboots"}};

    Accessories floorItem = { 0, "Empty", "Empty" };
   
    Character player;
    player.Health = 100;
    player.Atk = 35;
    player.Def = 5;
    player.SpD = 25;
    Character enemy;

    floorItem = player.Inventory(1, 5, "Knife", "Long Burger", VIEW, invSlots);
    player.Inventory(1, 5, "Knife", "Long Burger", PICKUP, invSlots);
    player.Inventory(1, 5, "Knife", "Long Burger", VIEW, invSlots);
    floorItem = player.Inventory(1, 5, "Knife", "Long Burger", DROP, invSlots);

    enemy = Enemy(3);
    std::cout << enemy.Name << std::endl;


    return 0;
}