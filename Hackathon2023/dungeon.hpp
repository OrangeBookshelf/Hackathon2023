#pragma once
#include "hackathon.hpp"

typedef enum type {
	ENTRANCE = 1, BASIC, CHEST, EXIT
}Type;

class Room {
public:
	//mutators
	void setType(int newType);
	void setEnemy(void);
	void setOccupied(int occupied);
	void setDoors(void);

	//accessors
	Type getType();
	bool getOccupied();
	bool getEnemy();


private:
	Type roomType;
	bool isOccupied;
	bool isEnemy;
	int doors;
};

class Floor {
	Room rooms[16];
};

class Dungeon {
	Floor floors[5];
};