#include "Belladonna.h"



Belladonna::Belladonna() {
	this->strength = 99;
	this->initiative = 0;
	this->setSign('b');
	this->setWorld(world);
	this->setName("Belladonna");
}

Belladonna::Belladonna(World* world, Position pos) {
	this->strength = 99;
	this->initiative = 0;
	this->setWorld(world);
	this->setSign('b');
	this->setName("Belladonna");
	this->setPosition(pos.getX(), pos.getY());
}

bool Belladonna::specialAttack(Organism* attack, Organism* defend) {
	if (this == defend) {
		world->killOrganism(attack, attack->getPosition()->getX(),
			attack->getPosition()->getY());

		world->writeText("Belladonna has poisoned and killed " + attack->getName() + "!\n");
		return true;
	}

	return false;
}