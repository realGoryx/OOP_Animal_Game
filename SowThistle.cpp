#include "SowThistle.h"


SowThistle::SowThistle() {
	this->strength = 0;
	this->initiative = 0;
	this->setSign('s');
	this->setWorld(world);
	this->setName("Sow Thistle");
}

SowThistle::SowThistle(World* world, Position pos) {
	this->strength = 0;
	this->initiative = 0;
	this->setWorld(world);
	this->setSign('s');
	this->setName("Sow Thistle");
	this->setPosition(pos.getX(), pos.getY());
}

void SowThistle::action() {
	this->yearsOld -= 2;

	for (int i = 0; i < 3; ++i) {
		Plant::action();
	}
}