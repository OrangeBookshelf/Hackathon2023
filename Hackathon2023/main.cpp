#include "hackathon.hpp"
#include "Accessories.hpp"
#include "Character.hpp"
#include "dungeon.hpp"

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
        system("pause");
        system("cls");

        //this is where the entire program goes
         
        while (floor != 5)
        {
            




            floor++;
        }

    }
    
    Character player;
    player.Health = 100;
    player.Atk = 35;
    player.Def = 5;
    player.SpD = 25;
    Character enemy;

    player.Inventory(1, 5, "Knife", "Long Burger", NONE);

    enemy = Enemy(3);
    std::cout << enemy.Name << std::endl;


    return 0;
}