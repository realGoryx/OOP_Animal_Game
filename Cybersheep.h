#pragma once
#include <iostream>
#include "Animal.h"

class Cybersheep:public Animal
{
public:
	Cybersheep();
	Cybersheep(World* world, Position pos);

	void action() override;

protected:
	bool normalSheep;
};

