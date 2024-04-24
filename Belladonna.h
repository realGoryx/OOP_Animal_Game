#pragma once
#include <iostream>
#include "Plant.h"

class Belladonna:public Plant
{
public:
	Belladonna();
	Belladonna(World* world, Position pos);
	bool specialAttack(Organism* attack, Organism* defend) override;
};

