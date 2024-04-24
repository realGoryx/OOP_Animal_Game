#include "SosnowskyHogweed.h"

SosnowskyHogweed::SosnowskyHogweed() {
	this->strength = 10;
	this->initiative = 0;
	this->setSign('+');
	this->setWorld(world);
	this->setName("Sosnowsky Hogweed");
}

SosnowskyHogweed::SosnowskyHogweed(World* world, Position pos) {
	this->strength = 10;
	this->initiative = 0;
	this->setWorld(world);
	this->setSign('+');
	this->setName("Sosnowsky Hogweed");
	this->setPosition(pos.getX(), pos.getY());
}

void SosnowskyHogweed::action(){
	int dy[8] = { 0, 0, -1, 1};
	int dx[8] = { 1, -1, 0, 0 };

	Organism* prey = nullptr;

	char animal[6] = { 'T', 'F', '@', 'W', 'S', 'A' };

	for (int i = 0; i < 4; ++i) {
		char test_sign = world->returnSymbol(position.getX() + dx[i], position.getY() + dy[i]);

		for (int j = 0; j < 6; ++j) {
			if (test_sign == animal[j]) {
				int posX = position.getX() + dx[i];
				int posY = position.getY() + dy[i];

				prey = world->getOrganism(posX, posY);
				world->killOrganism(prey, posX, posY);
				world->writeText("Sosnowsky Hogweed has poisoned and killed " + prey->getName() + "\n");
				break;
			}		
		}
	}

	Plant::action();

}