#include "dungeon.hpp"

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

//int Room::getDoors()
//{
//	return doors;
//}

//isenemy, hasitem, what item
void Room::populateRoom(Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
	Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE]) {
	setEnemy();
	switch (roomType) {
	case BASIC:
		if (rand() % 20 < 4) {
			hasItem = true;
			//item creation
			item = itemLootpool(Helms, Chest, Weapon, Boots);
		}
		

		break;
	case CHEST:
		hasItem = true;

		//item creation
		item = itemLootpool(Helms, Chest, Weapon, Boots);
		break;		
	}
}



