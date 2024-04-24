#pragma once
#include "Plant.h"
#include <iostream>

class SowThistle:public Plant
{
public:
	SowThistle();
	SowThistle(World* world, Position pos);
	void action() override;
};

