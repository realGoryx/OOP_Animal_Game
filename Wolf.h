#pragma once

#include "Animal.h"

class Wolf:public Animal
{
public:
	Wolf();
	Wolf(World* world, Position pos);
};

