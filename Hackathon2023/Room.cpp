#include "dungeon.hpp"
#include "traverse.hpp"

// Room constructor
Room::Room() {
	roomType = EMPTY;
	isOccupied = false;
	isEnemy = false;
	isEnd = false;
	hasItem = false;
	item.attributeMod = 0;
	item.itemRarity = NONE;
	item.weaponType = "Empty";
	item.weaponName = "Empty";
	description = "description";
}

void Room::printRoom()
{
	std::cout << description << std::endl;
	if (roomType == CHEST)
	{
		std::cout << "There is a chest in this room" << std::endl;
	}
	if (hasItem == true)
	{
		std::cout << "On the ground, you see an item that could be of use" << std::endl;
	}
	if (isEnemy == true)
	{
		std::cout << "There is an enemy at the far end of the room" << std::endl;
	}
	if (roomType == EXIT)
	{
		std::cout << "You can see the exit to the floor in this room" << std::endl;
	}
	if (isEnd == true && roomType != EXIT)
	{
		std::cout << "There are no other doors in this room than the one you came in" << std::endl;
	}
}


int Room::roomInteract(Character& player, Character& foe, Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
	Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier, int*floorNum,
	Accessories(&MySlots)[9])
{
	int index = 1, chest = 0, loot = 0, enemy = 0, sneak = 0, floor = 0, exit = 0, choice = 0;
	int lootedChest = 0, lootedLoot = 0, enemyStatus = 0, leave = 0, lootChoice = 0, equip = 0, nextRoom = 0;
	Accessories enemyLoot;
	Accessories droppedItem;
	if ((*floorNum == 0 || *floorNum == 2 || *floorNum == 4) && roomType == EXIT)
	{
		system("pause");
		system("cls");
		BigBoss boss;
		if (*floorNum == 0)
		{
			//centaur
			boss = Boss(3);
			std::cout << "You see a centaur, ready to attack you. They look tough" << std::endl;
			system("pause");
			system("cls");
			std::cout << R"(
                00000
               0000000
              000000000  0
              000000000  000
              000000000  000
              000000000  0 00
              000000000  0 00
               0000000   0  0
                0000     0  0
                 0000    0  0
               00000000000000
              000000000000000
              00000000   0  0
              00 00000   0  0
              00 00000   0  0
                 00000   0 00
     0000000000000000   0 00
   000000000000000000   000
  0000000000000000000   000
 000 000000000000000    0
 00  00000000000000
 00  00  00  00  00
000  00  00  00  00
000  00  00  00  00
     00  00  00  00
     00  00  00  00
)" << std::endl;
			startBossFight(player, boss, levelTier);
			if (player.Health > 0)
			{
				enemyLoot = bossLootpool(Helms, Chest, Weapon, Boots, levelTier);
				std::cout << "You have picked up a " << enemyLoot.weaponName << "!" << std::endl;
				do
				{
					std::cout << "Select where to put it in your inventory." << std::endl;
					printInventory(MySlots, player);
					std::cin >> lootChoice;
				} while (lootChoice < 1 || lootChoice > 9);
				droppedItem = player.Inventory(lootChoice-1, enemyLoot.attributeMod, enemyLoot.weaponType, enemyLoot.itemRarity,
					enemyLoot.weaponName, PICKUP, MySlots);
				do
				{
					std::cout << "Would you like to equip it?\n[1] Y\n[2] N" << std::endl;
					std::cin >> equip;
				} while (equip < 1 || equip > 2);

				if (equip == 1)
				{
					characterEquip(lootChoice, MySlots, player);
				}
			}
		}
		else if (*floorNum == 2)
		{
			boss = Boss(2);
			std::cout << "You see a Direwolf, eyeing you hungrily" << std::endl;
			system("pause");
			system("cls");
			std::cout << R"(
   0     0
   00   0 0
   0 0  0 0
   0 0000 00
   0       0
   0       0
  00        00
  0   00     000000000
  0   0     0        0000
 00         0             0
 0       000               0
000                        0
00  000        0            0
 000  0         0       0   0
       0        0       00   0
       0  000  0000 00  00   0
       0  0 0  0 00 000 0 0  0
       0 0  0  0  000 00   0 0
      0 00  0 0   00  000   0
     000  00 0  0000 0000
          000   000  000
)" << std::endl;
			startBossFight(player, boss, levelTier);
			if (player.Health > 0)
			{
				enemyLoot = bossLootpool(Helms, Chest, Weapon, Boots, levelTier);
				std::cout << "You have picked up a " << enemyLoot.weaponName << "!" << std::endl;
				do
				{
					std::cout << "Select where to put it in your inventory." << std::endl;
					printInventory(MySlots, player);
					std::cin >> lootChoice;
				} while (lootChoice < 1 || lootChoice > 9);
				droppedItem = player.Inventory(lootChoice - 1, enemyLoot.attributeMod, enemyLoot.weaponType, enemyLoot.itemRarity,
					enemyLoot.weaponName, PICKUP, MySlots);
				std::cout << "You have dropped " << droppedItem.weaponName << "." << std::endl;
				do
				{
					std::cout << "Would you like to equip it?\n[1] Y\n[2] N" << std::endl;
					std::cin >> equip;
				} while (equip < 1 || equip > 2);

				if (equip == 1)
				{
					characterEquip(lootChoice, MySlots, player);
				}
			}
		}
		else
		{
			boss = Boss(1);
			std::cout << "You see a Paladin, this is not going to be an easy fight" << std::endl;
			system("pause");
			system("cls");
			std::cout << R"(
         0  00000
        0 00     0
        0       0
        0     00 00
        0          0
         0000    00
     0   00   000
    0 0 00       0000
    0 0 0       00   0
   0   00      0      0
   0   00   000 0      0
   0   0 000  0  0     0
  0    0      0  0      0
  0     0      0  0     0
  0     0    00 0  00 000
  0     00000    0       0
 0      0    0000 00   00
0       00 00   0   000
 0   00000000000 0     0
  0  0-------0  00  0000
  0  0-------0   000   0
  0   0-----0   00     0
  0   0-----00 0  00  0  00
   0 00-------00    00000--0
   00----------0      0-----0
   0 00-------000    0000--0
    0 0-----000000000    00
    0 0-----0   0
     0-------0   0
     0-------0   0
     000000000   0
     0000000000000
)" << std::endl;
			startBossFight(player, boss, levelTier);
			if (player.Health > 0)
			{
				enemyLoot = bossLootpool(Helms, Chest, Weapon, Boots, levelTier);
				std::cout << "You have picked up a " << enemyLoot.weaponName << "!" << std::endl;
				do
				{
					std::cout << "Select where to put it in your inventory." << std::endl;
					printInventory(MySlots, player);
					std::cin >> lootChoice;
				} while (lootChoice < 1 || lootChoice > 9);
				droppedItem = player.Inventory(lootChoice - 1, enemyLoot.attributeMod, enemyLoot.weaponType, enemyLoot.itemRarity,
					enemyLoot.weaponName, PICKUP, MySlots);
				do
				{
					std::cout << "Would you like to equip it?\n[1] Y\n[2] N" << std::endl;
					std::cin >> equip;
				} while (equip < 1 || equip > 2);

				if (equip == 1)
				{
					characterEquip(lootChoice, MySlots, player);
				}
			}
		}
		return 2;
		levelTier++;
	}
	else
	{
		while (leave == 0)
		{
			index = 1;
			if (roomType == CHEST && lootedChest != 1)
			{
				std::cout << index << ": Loot the chest" << std::endl;
				chest = index;
				index++;
			}
			if (hasItem == true && lootedLoot != 1)
			{
				std::cout << index << ": Take the item off the ground" << std::endl;
				loot = index;
				index++;
			}
			if (isEnemy == true && enemyStatus != 1)
			{
				std::cout << index << ": Attack the enemy" << std::endl;
				enemy = index;
				index++;
				std::cout << index << ": Try to sneak past the enemy" << std::endl;
				sneak = index;
				index++;
			}
			if (roomType != ENTRANCE)
			{
				std::cout << index << ": Go back the way you came" << std::endl;
				exit = index;
				index++;
			}
			if (roomType == EXIT)
			{
				std::cout << index << ": Head to the next level in the dungeon" << std::endl;
				floor = index;
				index++;
			}
			if (roomType != EXIT && isEnemy == false)
			{
				std::cout << index << ": Head further in the dungeon" << std::endl;
				nextRoom = index;
				index++;
			}

			do
			{
				std::cin >> choice;
			} while (choice < 0 || choice >(index - 1));
			system("pause");
			system("cls");

			if (choice == chest && lootedChest != 1)
			{
				//looting
				enemyLoot = itemLootpool(Helms, Chest, Weapon, Boots, levelTier);
				std::cout << "You have picked up a " << enemyLoot.weaponName << "!" << std::endl;
				do
				{
					std::cout << "Select where to put it in your inventory." << std::endl;
					printInventory(MySlots, player);
					std::cin >> lootChoice;
				} while (lootChoice < 1 || lootChoice > 9);
				droppedItem = player.Inventory(lootChoice - 1, enemyLoot.attributeMod, enemyLoot.weaponType, enemyLoot.itemRarity,
					enemyLoot.weaponName, PICKUP, MySlots);
				do
				{
					std::cout << "Would you like to equip it?\n[1] Y\n[2] N" << std::endl;
					std::cin >> equip;
				} while (equip < 1 || equip > 2);

				if (equip == 1)
				{
					characterEquip(lootChoice, MySlots, player);
				}

				lootedChest = 1;
			}
			else if (choice == loot && lootedLoot != 1)
			{
				//looting
				enemyLoot = itemLootpool(Helms, Chest, Weapon, Boots, levelTier);
				std::cout << "You have picked up a " << enemyLoot.weaponName << "!" << std::endl;
				do
				{
					std::cout << "Select where to put it in your inventory." << std::endl;
					printInventory(MySlots, player);
					std::cin >> lootChoice;
				} while (lootChoice < 1 || lootChoice > 9);
				droppedItem = player.Inventory(lootChoice - 1, enemyLoot.attributeMod, enemyLoot.weaponType, enemyLoot.itemRarity,
					enemyLoot.weaponName, PICKUP, MySlots);
				do
				{
					std::cout << "Would you like to equip it?\n[1] Y\n[2] N" << std::endl;
					std::cin >> equip;
				} while (equip < 1 || equip > 2);

				if (equip == 1)
				{
					characterEquip(lootChoice, MySlots, player);
				}
				lootedLoot = 1;
			}
			else if (choice == enemy && enemyStatus != 1)
			{
				startFight(player, foe);
				if (player.Health > 0)
				{
					enemyLoot = itemLootpool(Helms, Chest, Weapon, Boots, levelTier);
					std::cout << "You have picked up a " << enemyLoot.weaponName << "!" << std::endl;
					do
					{
						std::cout << "Select where to put it in your inventory." << std::endl;
						printInventory(MySlots, player);
						std::cin >> lootChoice;
					} while (lootChoice < 1 || lootChoice > 9);
					droppedItem = player.Inventory(lootChoice - 1, enemyLoot.attributeMod, enemyLoot.weaponType, enemyLoot.itemRarity,
						enemyLoot.weaponName, PICKUP, MySlots);
					do
					{
						std::cout << "Would you like to equip it?\n[1] Y\n[2] N" << std::endl;
						std::cin >> equip;
					} while (equip < 1 || equip > 2);

					if (equip == 1)
					{
						characterEquip(lootChoice, MySlots, player);
					}
				}
				isEnemy = false;
				enemyStatus = 1;
			}
			else if (choice == sneak)
			{
				//sneak
				int evade = 25 + player.SpD;
				int goal = (rand() % 100) + 1;
				if (goal > evade)
				{
					startFight(player, foe);
					if (player.Health > 0)
					{
						enemyLoot = itemLootpool(Helms, Chest, Weapon, Boots, levelTier);
						std::cout << "You have picked up a " << enemyLoot.weaponName << "!" << std::endl;
						do
						{
							std::cout << "Select where to put it in your inventory." << std::endl;
							printInventory(MySlots, player);
							std::cin >> lootChoice;
						} while (lootChoice < 1 || lootChoice > 9);
						droppedItem = player.Inventory(lootChoice - 1, enemyLoot.attributeMod, enemyLoot.weaponType, enemyLoot.itemRarity,
							enemyLoot.weaponName, PICKUP, MySlots);
						std::cout << "You have dropped " << droppedItem.weaponName << "." << std::endl;
						do
						{
							std::cout << "Would you like to equip it?\n[1] Y\n[2] N" << std::endl;
							std::cin >> equip;
						} while (equip < 1 || equip > 2);

						if (equip == 1)
						{
							characterEquip(lootChoice, MySlots, player);
						}
					}
					isEnemy = false;
					enemyStatus = 1;
				}
				else
				{
					//next room (1)
					return 1;
					leave = 1;
				}
			}
			else if (choice == nextRoom)
			{
				return 1;
			}
			else if (choice == floor)
			{
				//new floor (2)
				return 2;
				leave = 1;
			}
			else if (choice == exit)
			{
				//go back (3)
				return 3;
				leave = 1;
			}
			system("pause");
			system("cls");
		}
	}
}

void Room::setType(int newType)
{
	if (newType == 1)
	{
		roomType = ENTRANCE;
	}
	else if (newType == 2)
	{
		roomType = BASIC;
	}
	else if (newType == 3)
	{
		roomType = CHEST;
	}
	else
	{
		roomType = EXIT;
	}
}


void Room::setEnemy(void)
{
	if (roomType == ENTRANCE)
	{
		isEnemy = false;
	}
	else if (roomType == BASIC)
	{
		int random = (rand() % 5) + 1;
		if (random == 1 || random == 2)
		{
			isEnemy = true;
		}
		else
		{
			isEnemy = false;
		}
	}
	else if (roomType == CHEST)
	{
		isEnemy = true;
	}
	else
	{
		isEnemy = false;
	}
}

void Room::setOccupied(int occupied)
{
	//0 is unoccupied, 1 is occupied
	if (occupied == 0)
	{
		isOccupied = false;
	}
	else
	{
		isOccupied = true;
	}
}

//void Room::setDoors(void)
//{
//	if (roomType == ENTRANCE)
//	{
//		doors = 1;
//	}
//	else if (roomType == BASIC || roomType == CHEST)
//	{
//		doors = ((rand() % 3) + 2);
//	}
//	else
//	{
//		doors = 1;
//	}
//}

void Room::setEnd(bool end) {
	isEnd = end;
}




Type Room::getType()
{
	return roomType;
}

bool Room::getOccupied()
{
	return isOccupied;
}

bool Room::getEnemy()
{
	return isEnemy;
}

bool Room::getItem()
{
	return hasItem;
}

bool Room::getEnd()
{
	return isEnd;
}

//int Room::getDoors()
//{
//	return doors;
//}

//isenemy, hasitem, what item
void Room::populateRoom(Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
	Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier) {
	setEnemy();
	switch (roomType) {
	case ENTRANCE:
		description = "You are in the entrance.";
		break;
	case BASIC:
		if (rand() % 20 < 4) {
			hasItem = true;
			//item creation
			item = itemLootpool(Helms, Chest, Weapon, Boots, levelTier);
		}
		description = "You walk into another room.";

		break;
	case CHEST:
		hasItem = true;

		//item creation
		item = itemLootpool(Helms, Chest, Weapon, Boots, levelTier);

	description: "This room has a chest.";
		break;		
	case EXIT:
		description = "You walk into a room that seems to have an exit further down";
		break;
	}
}



