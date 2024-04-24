#include "Wolf.h"

Wolf::Wolf() {
	this->strength = 9;
	this->initiative = 5;
	this->setSign('W');
	this->setName("Wolf");
	this->setWorld(world);
}

Wolf::Wolf(World* world, Position pos) {
	this->strength = 9;
	this->initiative = 5;
	this->setSign('W');
	this->setName("Wolf");
	this->setWorld(world);
	this->setPosition(pos.getX(), pos.getY());
}