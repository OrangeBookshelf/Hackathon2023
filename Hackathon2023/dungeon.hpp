#pragma once
#include "hackathon.hpp"
#include "Accessories.hpp"
#include "Character.hpp"

typedef enum type {
	ENTRANCE = 1, BASIC, CHEST, EXIT, EMPTY
}Type;

class Room {
public:
	//constructor
	Room();

	//print the room
	void printRoom();
	int roomInteract(Character& player, Character& foe, Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
		Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier, int* floorNum,
		Accessories(&MySlots)[9]);

	//mutators
	void setType(int newType);
	void setEnemy(void);
	void setOccupied(int occupied);
	void setEnd(bool end);
	//void setDoors(void);

	//accessors
	Type getType();
	bool getOccupied();
	bool getEnemy();
	bool getItem();
	bool getEnd();
	//int getDoors();

	//

	void populateRoom(Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
		Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier);


private:
	Type roomType;
	bool isOccupied;
	bool isEnemy;
	bool isEnd;
	bool hasItem;
	Accessories item;

	std::string description;

};

class Floor {
public:
	//constructor
	Floor();

	Room* getRooms();

	void setFloor(Floor& floor, Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
		Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier);

	void printFloorType(Floor floor);

private:
	Room rooms[12];

};

class Dungeon {
public:
	//constructor
	Dungeon();

	void generate(Dungeon& dungeon, Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
		Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier);

	Floor floors[5];
};


