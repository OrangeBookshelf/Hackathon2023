#pragma once
#include "hackathon.hpp"

class Accessories
{
public:
	int attributeMod;
	std::string weaponType;
	std::string weaponName;
};

class Node
{
public:
	Accessories thisAccessory;
	Node* pNext;
};