#include "traverse.hpp"

void placeAtStart(Character player, Dungeon& dungeon, Room** currentLocation){
	dungeon.floors[0].getRooms()[0].setOccupied(1);
	*currentLocation = &dungeon.floors[0].getRooms()[0];
}

void findPlayer(int* floorNumber, int* roomNumber, Dungeon& dungeon, Room** currentLocation) {
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 12; i++) {
			if (dungeon.floors[j].getRooms()[i].getOccupied()) {
				*roomNumber = i;
				*floorNumber = j;
				j = 5;
				break;
			}
		}
	}
	*currentLocation = &dungeon.floors[*floorNumber].getRooms()[*roomNumber];
}

bool moveRight(int* floorNumber, int* roomNumber, Dungeon& dungeon, Room** currentLocation) {
	bool success = false;
	if (*roomNumber != 12) {
		(*currentLocation)->setOccupied(0);
		(*roomNumber)++;
		dungeon.floors[*floorNumber].getRooms()[*roomNumber].setOccupied(1);
		success = true;
	}
	*currentLocation = &dungeon.floors[*floorNumber].getRooms()[*roomNumber];
	return success;
}

bool moveLeft(int* floorNumber, int* roomNumber, Dungeon& dungeon, Room** currentLocation) {
	bool success = false;
	if (*roomNumber != 0) {
		(*currentLocation)->setOccupied(0);
		(*roomNumber)--;
		dungeon.floors[*floorNumber].getRooms()[*roomNumber].setOccupied(1);
		success = true;
	}
	*currentLocation = &dungeon.floors[*floorNumber].getRooms()[*roomNumber];
	return success;

}

void descend(int* floorNumber, int* roomNumber, Dungeon& dungeon, Room** currentLocation) {
	(*floorNumber)++;
	*roomNumber = 0;
	*currentLocation = &dungeon.floors[*floorNumber].getRooms()[*roomNumber];
}