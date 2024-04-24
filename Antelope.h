#pragma once

#include "Animal.h"

class Antelope:public Animal
{
public:
	Antelope();
	Antelope(World* world, Position pos);
	bool specialAttack(Organism* attack, Organism* defend) override;
};

