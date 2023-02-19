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

void Dungeon::generate(Dungeon& dungeon, Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
	Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier) {
	for (int i = 0; i < 5; i++) {
		dungeon.floors[i].Floor::setFloor(dungeon.floors[i], Helms, Chest, Weapon, Boots, levelTier);
	}
}

Room* Floor::getRooms() {
	return rooms;
}


void Floor::setFloor(Floor& floor, Accessories(&Helms)[ARR_SIZE], Accessories(&Chest)[ARR_SIZE],
	Accessories(&Weapon)[ARR_SIZE], Accessories(&Boots)[ARR_SIZE], int& levelTier) {
	int x = 0;
	int y = 0;

	int roomCount = 0;

	//place entrance
	floor.rooms[roomCount].setType(1);
	floor.rooms[roomCount].populateRoom(Helms, Chest, Weapon, Boots, levelTier);
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
		floor.rooms[roomCount+i].populateRoom(Helms, Chest, Weapon, Boots, levelTier);
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
		floor.rooms[roomCount + i].populateRoom(Helms, Chest, Weapon, Boots, levelTier);

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
		floor.rooms[roomCount + i].populateRoom(Helms, Chest, Weapon, Boots, levelTier);

	}
	floor.rooms[11].setEnd(true);
}
