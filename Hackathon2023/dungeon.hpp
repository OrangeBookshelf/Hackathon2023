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
	void roomInteract(Character player, Character enemy);

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

	void populateRoom();


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

	void setFloor(Floor& floor);

	void printFloorType(Floor floor);

private:
	Room rooms[12];

};

class Dungeon {
public:
	//constructor
	Dungeon();

	void generate(Dungeon& dungeon);

	Floor floors[5];
};


