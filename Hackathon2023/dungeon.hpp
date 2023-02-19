#pragma once
#include "hackathon.hpp"
#include "Accessories.hpp"

typedef enum type {
	ENTRANCE = 1, BASIC, CHEST, EXIT, EMPTY
}Type;

class Room {
public:
	//constructor
	Room();
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


