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
	Room rooms[16];
};

class Dungeon {
	Floor floors[5];
};