#pragma once
#include "Organism.h"
#include <iostream>

class Plant:public Organism
{
public:
	Plant() = default;

protected:
	void action() override;
	int collision(Position* attackingPos) override;
	void findSafe(int* helpArray);
	void sowing(int direction);
};

