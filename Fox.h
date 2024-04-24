#pragma once
#include "Animal.h"

class Fox:public Animal
{
public:
	Fox();
	Fox(World* world, Position pos);
	void action() override;
};

