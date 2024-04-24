#include "Guarana.h"


Guarana::Guarana() {
	this->strength = 0;
	this->initiative = 0;
	this->setSign('G');
	this->setWorld(world);
	this->setName("Guarana");
}

Guarana::Guarana(World* world, Position pos) {
	this->strength = 0;
	this->initiative = 0;
	this->setWorld(world);
	this->setSign('G');
	this->setName("Guarana");
	this->setPosition(pos.getX(), pos.getY());
}

bool Guarana::specialAttack(Organism* attack, Organism* defend) {
	if (this == defend) {
		int attackerStrength = attack->getStrength();
		attack->setStrength(attackerStrength + 3);
		world->killOrganism(this, position.getX(), position.getY());
		world->writeText(attack->getName() + "'s strength has been increased by 3!\n");
		return true;
	}

	return false;
}