#include "traverse.hpp"

void placeAtStart(Dungeon dungeon, Room* currentLocation) {
	dungeon.floors[0].getRooms()[0].setOccupied(1);
}