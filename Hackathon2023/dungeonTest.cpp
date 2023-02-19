#include "dungeonTest.hpp"

void testSetFloor(void) {
	Dungeon dungeonTest;
	for (int i = 0; i < 5; i++) {
		dungeonTest.floors[i].setFloor(dungeonTest.floors[i]);
		dungeonTest.floors[i].printFloorType(dungeonTest.floors[i]);
	}
}