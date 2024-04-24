#pragma once
#include "Plant.h"
#include <iostream>

class Guarana:public Plant
{
public:
	Guarana();
	Guarana(World* world, Position pos);
	bool specialAttack(Organism* attack, Organism* defend) override;
};

