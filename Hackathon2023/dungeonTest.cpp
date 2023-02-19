#include "dungeonTest.hpp"

void testSetFloor(void) {
	Dungeon dungeonTest;
//	dungeonTest.Dungeon::generate(dungeonTest);
	for (int i = 0; i < 5; i++) {
		dungeonTest.floors[i].printFloorType(dungeonTest.floors[i]);
	}
}