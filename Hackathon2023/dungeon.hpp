#pragma once
#include "hackathon.hpp"

typedef enum type {
	ENTRANCE = 1, BASIC, CHEST, EXIT
}Type;

class Room {
public:
	//constructor
	Room();
	//mutators
	void setType(int newType);
	void setEnemy(void);
	void setOccupied(int occupied);
	void setDoors(void);
	void setDirection(int direction);

	//accessors
	Type getType();
	bool getOccupied();
	bool getEnemy();
	int getDoors();
	bool getDirection(int direction);


private:
	Type roomType;
	bool isOccupied;
	bool isEnemy;
	int doors;

	bool north;
	bool south;
	bool east;
	bool west;
};

class Floor {
public:
	//constructor
	Floor();

	void setFloor(Floor floor);
private:
	Room grid[7][7];
	Room rooms[16];

};

class Dungeon {
public:
	void generate();

	Floor floors[5];
};

