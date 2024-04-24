#pragma once
#include "Plant.h"
#include <iostream>

class SosnowskyHogweed:public Plant
{
public:
	SosnowskyHogweed();
	SosnowskyHogweed(World* world, Position pos);

	void action() override;
};

