#include "hackathon.hpp"
#include "Accessories.hpp"
#include "Character.hpp"
#include "dungeon.hpp"
#include "dungeonTest.hpp"
#include "traverse.hpp"



int main(void) 
{
    srand(time(NULL));
    int levelTier = 1;
    int menuChoice = 0, floor = 1, room = 0;

    //inventory
    Accessories invSlots[9] = { {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"},
{0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"}, {0, NONE, "Empty", "Empty"} };
    
    //item lists
    //modifies health
    Accessories Helmets[ARR_SIZE] = { {10, COMMON, "Helmet", "Cap"}, {10, COMMON, "Helmet", "Chaincap"}, {15, RARE, "Helmet", "Ironhelm"},
        {15, RARE, "Helmet", "Hood"}, {20, EPIC, "Helmet", "Steelhelm"}, {25, LEGENDARY, "Helmet", "Templarhelm"} };
    //modifies defense
    Accessories ChestPiece[ARR_SIZE] = { {2, COMMON, "ChestPiece", "Rags"}, {3, COMMON, "ChestPiece", "Robes"}, {5, RARE, "ChestPiece", "Chestplate"},
        {5, RARE, "ChestPiece", "Chainmail"}, {7, EPIC, "ChestPiece", "Heavyplate"}, {10, LEGENDARY, "ChestPiece", "Templarplate"} };
    //modifies attack
    Accessories Weapons[ARR_SIZE] = { {3, COMMON, "Weapons", "Dagger" }, { 3, COMMON, "Weapons", "Knife" }, {4, RARE, "Weapons", "Sword"},
        {4, RARE, "Weapons", "Hatchet"}, {5, EPIC, "Weapons", "Axe"}, {6, LEGENDARY, "Weapons", "Longsword"} };
    //modifies speed
    Accessories Boots[ARR_SIZE] = { {5, COMMON, "Boots", "Tornboot"}, {5, COMMON, "Boots", "Peasantboots"}, {10, RARE, "Boots", "Greaves"},
        {15, RARE, "Boots", "Bootshoe"}, {20, EPIC, "Boots", "Steeltipped"}, {30, LEGENDARY, "Boots", "Templarboots"} };

    Accessories floorItem = { 0, NONE, "Empty", "Empty" };

    Accessories lootItem = { 0, NONE, "Empty", "Empty" };

    Character player;
    player.Health = 100;
    player.Atk = 35;
    player.Def = 5;
    player.SpD = 25;
    Character enemy;

    Room* currentLocation = NULL;
    int floorNumber = 0;
    int roomNumber = 0;
    int movement = 0;

    Dungeon dungeon;

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
        //this is where the entire program goes

        dungeon.Dungeon::generate(dungeon, Helmets, ChestPiece, Weapons, Boots, levelTier);
        placeAtStart(player, dungeon, &currentLocation);
        findPlayer(&floorNumber, &roomNumber, dungeon, &currentLocation);

        while (levelTier != 4 && player.Health > 0)
        {
            //this where game go
            currentLocation->printRoom();
            if (currentLocation->getEnemy() == true)
            {
                int en = (rand() % 3) + 1;
                enemy = Enemy(en, levelTier);
            }
            movement = currentLocation->roomInteract(player, enemy, Helmets, ChestPiece, Weapons, Boots, levelTier, &floorNumber, invSlots);
            
            if (movement == 1)
            {
                //next room
                moveRight(&floorNumber, &roomNumber, dungeon, &currentLocation);
            }
            else if (movement == 2)
            {
                //new floor
                descend(&floorNumber, &roomNumber, dungeon, &currentLocation);

            }
            else
            {
                //go back
                moveLeft(&floorNumber, &roomNumber, dungeon, &currentLocation);

            }
            //print room

            //give/get options

            //move if needed
        }

        if (levelTier == 4)
        {
            std::cout << "You win!" << std::endl;
        }
        else
        {
            std::cout << "Game over" << std::endl;
        }

        system("pause");
        system("cls");
        
    }
    return 0;
}