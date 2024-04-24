#include "Human.h"
#include <conio.h>

Human::Human(World* world, Position pos) {
	this->strength = 5;
	this->initiative = 4;
	this->setName("Human");
	this->setWorld(world);
	this->setPosition(pos.getX(), pos.getY());
	this->setSign('@');
}

void Human::action() {

	int posX = position.getX();
	int posY = position.getY();
	Organism* kk = world->getOrganism(posX, posY);
	Organism* pp = world->getOrganism(posY, posX);


	while (true) {
		char arrow = _getch();
		int checkCollision = 99;

		switch (arrow) {
			case 72: // Up
				if(world->returnSymbol(this->getPosition()->getX() - 1, this->getPosition()->getY()) == '?')
					break;
				else if (world->returnSymbol(this->getPosition()->getX() - 1, this->getPosition()->getY()) == '*') {
					countSpecial();
					eraseTraces(this->getPosition()->getX() - 1, this->getPosition()->getY());
					return;
				}
				else {
					checkCollision = Animal::collision(world->getOrganism(this->position.getX() - 1, this->position.getY())->getPosition());

					if (checkCollision == 6) {
						eraseTraces(this->getPosition()->getX() - 1, this->getPosition()->getY());
					}
					return;
				}
				return;
			case 80: // Down
				if (world->returnSymbol(this->getPosition()->getX() + 1, this->getPosition()->getY()) == '?')
					break;
				else if (world->returnSymbol(this->getPosition()->getX() + 1, this->getPosition()->getY()) == '*') {
					countSpecial();
					eraseTraces(this->getPosition()->getX() + 1, this->getPosition()->getY());
					return;
				}
				else {
					checkCollision = Animal::collision(world->getOrganism(this->position.getX() + 1, this->position.getY())->getPosition());

					if (checkCollision == 6) {
						eraseTraces(this->getPosition()->getX() + 1, this->getPosition()->getY());
					}
					return;
				}
				return;
			case 75: // Left
				if (world->returnSymbol(this->getPosition()->getX(), this->getPosition()->getY() - 1) == '?')
					break;
				else if (world->returnSymbol(this->getPosition()->getX(), this->getPosition()->getY() - 1) == '*') {
					countSpecial();
					eraseTraces(this->getPosition()->getX(), this->getPosition()->getY() - 1);
					return;
				}
				else {
					checkCollision = Animal::collision(world->getOrganism(this->position.getX(), this->position.getY() - 1)->getPosition());

					if (checkCollision == 6) {
						eraseTraces(this->getPosition()->getX(), this->getPosition()->getY() - 1);
					}
					return;
				}
				return;
			case 77: //Right
				if (world->returnSymbol(this->getPosition()->getX(), this->getPosition()->getY() + 1) == '?')
					break;
				else if (world->returnSymbol(this->getPosition()->getX(), this->getPosition()->getY() + 1) == '*') {
					countSpecial();
					eraseTraces(this->getPosition()->getX(), this->getPosition()->getY() + 1);
					return;
				}
				else {
					checkCollision = Animal::collision(world->getOrganism(this->position.getX(), this->position.getY() + 1)->getPosition());

					if (checkCollision == 6) {
						eraseTraces(this->getPosition()->getX(), this->getPosition()->getY() + 1);
					}
					return;
				}
				return;
			case 'e':
				if(!this->usedSpecial)
					specialAbility(this->getPosition()->getX(), this->getPosition()->getY());
				return;
			case 's':
				world->setSaved(true);
				return;
			case 'l':
				world->loadGameStatus();
				return;
			default:
				break;
		}

	}

}


void Human::countSpecial() {
	if (this->usedSpecial) {
		this->roundsAfterSpecial++;
		if(this->roundsAfterSpecial < 5)
			world->writeText(to_string(5 - roundsAfterSpecial) + " more rounds for Human's special ability to regenerate\n");

		if (this->roundsAfterSpecial == 5) {
			world->writeText("Human special ability is ready to be used!\n");
			this->roundsAfterSpecial = -1;
			this->usedSpecial = false;
		}

	}
}


void Human::eraseTraces(int h, int w) {
	world->eraseOrganism(this->getPosition()->getX(), this->getPosition()->getY());
	world->helpAnimalMove(this, h, w);
	this->position.setX(h);
	this->position.setY(w);
	world->writeText("Human has moved to " + to_string(this->position.getX()) + ", " + to_string(this->position.getY()) + "\n");
}


void Human::specialAbility(int h, int w) {

	int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
	int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

	world->writeText("Special ability has been used!\n");

	for (int i = 0; i < 8; ++i) {
		char symbol = world->returnSymbol(h + dx[i], w + dy[i]);
		Organism* org = nullptr;
		if (symbol != '?')
			org = world->getOrganism(h + dx[i], w + dy[i]);
		if (org != nullptr) {
			world->killOrganism(org, h + dx[i], w + dy[i]);
			world->writeText(org->getName() + " has been killed by Human's special ability!\n");
		}
	}

	this->usedSpecial = true;
}


int Human::getRoundsSpecial() {
	return roundsAfterSpecial;
}

void Human::setRoundsSpecial(int rounds) {
	this->roundsAfterSpecial = rounds;
}

bool Human::getUsedSpecial() {
	return usedSpecial;
}

void Human::setUsedSpecial(bool used) {
	this->usedSpecial = used;
}

