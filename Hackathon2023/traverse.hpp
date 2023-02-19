#pragma once
#include "hackathon.hpp"
#include "dungeon.hpp"
#include "Character.hpp"

void placeAtStart(Character player, Dungeon& dungeon, Room** currentLocation);

void findPlayer(int* floorNumber, int* roomNumber,Dungeon& dungeon, Room ** currentLocation);

bool moveRight(int* floorNumber, int* roomNumber, Dungeon& dungeon, Room ** currentLocation);

bool moveLeft(int* floorNumber, int* roomNumber, Dungeon& dungeon, Room** currentLocation);

void descend(int* floorNumber, int* roomNumber, Dungeon& dungeon, Room** currentLocation);