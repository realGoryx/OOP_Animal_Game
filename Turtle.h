#pragma once
#include "Animal.h"

class Turtle:public Animal
{
public:
	Turtle();
	Turtle(World* world, Position pos);

	void action() override;
	bool specialAttack(Organism* attack, Organism* defend) override;
};

