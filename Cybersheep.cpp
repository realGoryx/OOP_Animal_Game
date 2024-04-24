#include "Cybersheep.h"
#include <cmath>

Cybersheep::Cybersheep() {
	this->strength = 11;
	this->initiative = 4;
	this->setSign('C');
	this->setWorld(world);
	this->setName("Cybersheep");
}

Cybersheep::Cybersheep(World* world, Position pos) {
	this->strength = 11;
	this->initiative = 4;
	this->setSign('C');
	this->setName("Cybersheep");
	this->setWorld(world);
	this->setPosition(pos.getX(), pos.getY());
}

void Cybersheep::action() {
	vector<Position> sosnowskyPos;
	int sosCount = 0;

	Position* cyberPos = getPosition();
	int cyberX = cyberPos->getX();
	int cyberY = cyberPos->getY();

	sosCount = world->countSos();
	world->getSosnowskysPosition(&sosnowskyPos);

	int minDistance = 999;
	int closestX;
	int closestY;

	for (int i = 0; i < sosnowskyPos.size(); ++i) {
		double distance = sqrt(pow(cyberX - sosnowskyPos[i].getX(), 2) + pow(cyberY - sosnowskyPos[i].getY(), 2));
		if (double(distance) < double(minDistance)) {
			minDistance = distance;
			closestX = sosnowskyPos[i].getX();
			closestY = sosnowskyPos[i].getY();
		}
	}

	int outcome;

	if (sosCount > 0) {
		if (cyberX != closestX) {
			if (cyberX > closestX) {
				if (world->returnSymbol(cyberX - 1, cyberY) == '*')
					Animal::move(1);
				else {
					Position* attacking = new Position(cyberX - 1, cyberY);
					outcome = Animal::collision(attacking);

					if (outcome == 6)
						Animal::move(1);
				}
			}
			if (cyberX < closestX) {
				if (world->returnSymbol(cyberX + 1, cyberY) == '*')
					Animal::move(0);
				else {
					Position* attacking = new Position(cyberX + 1, cyberY);
					outcome = Animal::collision(attacking);

					if (outcome == 6)
						Animal::move(0);
				}
			}
		}
		else if (cyberY != closestY) {
			if (cyberY > closestY) {
				if (world->returnSymbol(cyberX, cyberY - 1) == '*')
					Animal::move(3);
				else {
					Position* attacking = new Position(cyberX, cyberY - 1);
					outcome = Animal::collision(attacking);

					if (outcome == 6)
						Animal::move(3);
				}
			}
			if (cyberY < closestY) {
				if (world->returnSymbol(cyberX, cyberY + 1) == '*')
					Animal::move(2);
				else {
					Position* attacking = new Position(cyberX, cyberY + 1);
					outcome = Animal::collision(attacking);

					if (outcome == 6)
						Animal::move(2);
				}
			}
		}
	}
	else {
		Animal::action();
	}



}