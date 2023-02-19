#include "dungeon.hpp"

//constructor
Room::Room() {
	roomType = ENTRANCE;
	isOccupied = false;
	isEnemy = false;
	doors = 0;

	north = false;
	south = false;
	east = false;
	west = false;
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

void Room::setDoors(void)
{
	if (roomType == ENTRANCE)
	{
		doors = 1;
	}
	else if (roomType == BASIC || roomType == CHEST)
	{
		doors = ((rand() % 3) + 2);
	}
	else
	{
		doors = 1;
	}
}

void Room::setDirection(int direction) {
	if (direction == 0) {
		north = true;
	}
	if (direction == 1) {
		south = true;
	}
	if (direction == 1) {
		east = true;
	}
	if (direction == 1) {
		west = true;
	}
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

int Room::getDoors()
{
	return doors;
}

bool Room::getDirection(int direction) {
	bool temp = false;
	if (direction == 0) {
		temp = north;
	}
	if (direction == 1) {
		temp = south;
	}
	if (direction == 2) {
		temp = east;
	}
	if (direction == 3) {
		temp = west;
	}
	return temp;
}

