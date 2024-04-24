#pragma once
#include <iostream>
#include "Animal.h"

class World;
class Human:public Animal
{
public:
	Human(World* world, Position pos);
	void action() override;
	void specialAbility(int h, int w);
	void eraseTraces(int h, int w);
	void countSpecial();

	int getRoundsSpecial();
	void setRoundsSpecial(int rounds);

	bool getUsedSpecial();
	void setUsedSpecial(bool used);

	void checkUltimate();


protected:
	int roundsAfterSpecial = 0;
	bool usedSpecial = false;
};

