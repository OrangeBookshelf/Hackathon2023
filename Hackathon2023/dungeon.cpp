#include "dungeon.hpp"


void Floor::printFloorType(Floor floor) {
	for (int i = 0; i < 12; i++) {
		std::cout << floor.rooms[i].getType()<<"->";
	}
	std::cout << std::endl;
}

//Floor constructor
Floor::Floor() {
	for (int i = 0; i < 12; i++) {
		Room holder;
		rooms[i] = holder;
	}
}

//Dungeon constructor
Dungeon::Dungeon() {
	for (int i = 0; i < 5; i++) {
		Floor holder;
		floors[i] = holder;
	}
}

void Dungeon::generate(Dungeon& dungeon) {
	for (int i = 0; i < 5; i++) {
		dungeon.floors[i].Floor::setFloor(dungeon.floors[i]);
	}
}

void Floor::setFloor(Floor& floor) {
	int x = 0;
	int y = 0;

	int roomCount = 0;

	//place entrance
	floor.rooms[roomCount].setType(1);
	floor.rooms[roomCount].populateRoom();
	roomCount++;
	//place next 3
	int chest = rand() % 3;
	for (int i = 0; i < 3; i++) {
		if (i == chest) {
			floor.rooms[roomCount + i].setType(3);
		}
		else {
			floor.rooms[roomCount + i].setType(2);
		}
		floor.rooms[roomCount+i].populateRoom();
	}
	roomCount = 4;
	//place next 4
	chest = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (i == chest) {
			floor.rooms[roomCount + i].setType(3);
		}
		else {
			floor.rooms[roomCount + i].setType(2);
		}
		floor.rooms[roomCount + i].populateRoom();

	}
	roomCount = 8;
	//place last 4
	int exit = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (i == exit) {
			floor.rooms[roomCount + i].setType(4);
		}
		else {
			floor.rooms[roomCount + i].setType(2);
		}
		floor.rooms[roomCount + i].populateRoom();

	}
	floor.rooms[11].setEnd(true);
}
