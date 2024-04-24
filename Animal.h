#pragma once
#include <iostream>
#include "Organism.h"

class Animal:public Organism
{
public:
	Animal() = default;

protected:
	void action() override;
	int collision(Position* attackingPos) override;
	
	void findSafe(int *helpArray);
	void move(int direction);
	
	void breed(int direction, Position pos, char sign);
	
	void findSafeTwo(int* helpArray, Position* attackingPos);


};

