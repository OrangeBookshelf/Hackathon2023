#include "dungeon.hpp"

Floor::Floor() {
	//grid
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			Room holder;
			grid[i][j] = holder;
		}
	}
	//rooms
	for (int i = 0; i < 16; i++) {
		Room holder;
		rooms[i] = holder;
	}
}

void Dungeon::generate() {
	//floor by floor
	//create array of 16 rooms
	//
}

void Floor::setFloor(Floor floor) {
	int x = 0;
	int y = 0;

	int roomCount = 0;
	//initialize floor array
	

	//place entrance
	x = rand() % 7;
	y = rand() % 7;

	grid[y][x].setType(1);
	grid[y][x].setDoors();

	roomCount += grid[y][x].getDoors();


	//set direction
	for (int i = 0; i < grid[y][x].getDoors(); i++) {
		int random = rand() % 4;
		if (!grid[y][x].getDirection(random)) {
			grid[y][x].setDirection(random);
		}
	}

}
