#include "Fox.h"
#include <windows.h>

Fox::Fox() {
	this->strength = 3;
	this->initiative = 7;
	this->setSign('F');
	this->setWorld(world);
	this->setName("Fox");
}

Fox::Fox(World* world, Position pos) {
	this->strength = 3;
	this->initiative = 7;
	this->setSign('F');
	this->setName("Fox");
	this->setWorld(world);
}

void Fox::action() {
	this->yearsOld += 1;

	int helping[4] = { 0,0,0,0 };
	findSafe(helping);
	bool quit = false;

	while (!quit) {
		int randomPosition = rand() % 4;

		if (helping[randomPosition] == 1) {
			move(randomPosition);
			quit = true;
		}
		else if (helping[randomPosition] == 2) {
			;
		}
		else {
			int dy[4] = { 0, 0, 1, -1 };
			int dx[4] = { 1, -1, 0, 0 };

			if (world->getOrganism(this->position.getX() + dx[randomPosition],
				this->position.getY() + dy[randomPosition])->getStrength() > this->getStrength()) {
				world->writeText("Fox has sensed the danger and stayed in place!\n");
				return;
			}

			int outcome = collision(world->getOrganism(this->position.getX() + dx[randomPosition], this->position.getY() + dy[randomPosition])->getPosition());
			if (outcome == 6) {
				move(randomPosition);
				break;
			}
		}
	}

}