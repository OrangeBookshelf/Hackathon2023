#include "dungeon.hpp"

//constructor
Room::Room() {
	roomType = EMPTY;
	isOccupied = false;
	isEnemy = false;
	isEnd = false;
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



