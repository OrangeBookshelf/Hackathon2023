#include "hackathon.hpp"
#include "Accessories.hpp"
#include "Character.hpp"

int main(void) {
    
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