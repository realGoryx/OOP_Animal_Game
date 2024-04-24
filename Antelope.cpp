#include "Antelope.h"

Antelope::Antelope() {
	this->strength = 4;
	this->initiative = 4;
	this->movementSpeed = 1;
	this->setSign('A');
	this->setName("Antelope");
}

Antelope::Antelope(World* world, Position pos) {
	this->strength = 4;
	this->initiative = 4;
	this->movementSpeed = 1;
	this->setSign('A');
	this->setName("Antelope");
	this->setWorld(world);
	this->setPosition(pos.getX(), pos.getY());
}

bool Antelope::specialAttack(Organism* attack, Organism* defend) {
	
	int dodgeChance = rand() % 4;

	if (dodgeChance < 2) {
		return false;
	}
	else {
		int helping[4] = {0,0,0,0};
		Animal::findSafe(helping);

		int counter = 0;

		for (int i = 0; i < 4; ++i) {
			if (helping[i] == 1)
				counter++;
		}

		if (counter == 0)
			return false;
		else {

			while (true) {
				int randomPosition = rand() % 4;

				if (helping[randomPosition] == 1) {
					this->setMovementSpeed(0);
					Animal::move(randomPosition);
					this->setMovementSpeed(1);
					this->setMoved(true);
					world->writeText("Antelope has escaped from the fight!\n");
					break;
				}
			}

			return true;
		}

	}
	
	return false;
}