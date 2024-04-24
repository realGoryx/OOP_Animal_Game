#pragma once
#include <iostream>
#include "Animal.h"


class Sheep: public Animal
{
public:
	Sheep();
	Sheep(World* world, Position pos);
};

