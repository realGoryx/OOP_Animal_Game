#pragma once
#include "Plant.h"
#include <iostream>

class Grass:public Plant
{
public:
	Grass();
	Grass(World* world, Position pos);
};

