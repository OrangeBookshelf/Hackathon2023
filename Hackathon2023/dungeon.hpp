#pragma once
#include "hackathon.hpp"

typedef enum type {
	ENTRANCE = 1, BASIC, CHEST, EXIT
}Type;

class Room {
	Type roomType;
	bool isOccupied;
};

class Floor {
public:
	void setFloor(Floor floor);
	void setGrid();
private:
	Room grid[7][7];
	Room rooms[16];

};

class Dungeon {
public:
	void generate();

	Floor floors[5];
};

