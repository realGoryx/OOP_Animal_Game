#include "Animal.h"
#include <iostream>


void Animal::action() {
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
		else if (helping[randomPosition] == 2){
			//cout << "Out of map!";
			//quit = true;
		}
		else {
			int dy[4] = { 0, 0, 1 + this->movementSpeed, -1 + this->movementSpeed };
			int dx[4] = { 1 + this->movementSpeed, -1 + this->movementSpeed, 0, 0 };

			int outcome = collision(world->getOrganism(this->position.getX() + dx[randomPosition], this->position.getY() + dy[randomPosition])->getPosition());

			if (outcome == 6) {
				move(randomPosition);
				break;
			}
			else {
				break;
			}

		}
	}

}


void Animal::findSafe(int *helpArray) {
	int dy[4] = { 0, 0, 1 + this->movementSpeed, -1 - this->movementSpeed };
	int dx[4] = { 1 + this->movementSpeed, -1 - this->movementSpeed, 0, 0 };

	int posX = position.getX();
	int posY = position.getY();

	for (int i = 0; i < 4; ++i) {
		if (this->world->returnSymbol(posX + dx[i], posY + dy[i]) == '*')
			helpArray[i] = 1;
		else if (this->world->returnSymbol(posX + dx[i], posY + dy[i]) == '?')
			helpArray[i] = 2;
	}

}

void Animal::move(int direction) {
	int posX = this->position.getX();
	int posY = this->position.getY();

	int movementSpeed = this->movementSpeed;


	int direct = direction;
	// 0 - down, 1 - up, 2 - right, 3 - left

	int dy[4] = { 0, 0, 1 + this->movementSpeed, -1 - this->movementSpeed };
	int dx[4] = { 1 + this->movementSpeed, -1 - this->movementSpeed, 0, 0 };

	this->position.setX(posX + dx[direct]);
	this->position.setY(posY + dy[direct]);
	
	world->helpAnimalMove(this, posX + dx[direct], posY + dy[direct]);
	world->eraseOrganism(posX, posY);


	world->writeText(this->getName() + " has moved to " + to_string(this->position.getX()) + ", " + to_string(this->position.getY()) + "\n");
}


int Animal::collision(Position* attackingPos) {
	Organism* defender = world->getOrganism(attackingPos->getX(), attackingPos->getY());
	
	if (defender != nullptr) {
		if (defender->getSign() == this->getSign() && (this->getYears() > 3) && (defender->getYears() > 3)){
			int helping[8] = {0,0,0,0,0,0,0,0};
			findSafe(helping);
			findSafeTwo(helping + 4, attackingPos);
			int counter = 0;
			
			for (int i = 0; i < 8; ++i) {
				if (helping[i] == 1)
					counter++;
			}
			
			if (counter == 0) {
				return 99;
			}

			while (true) {
				int randomPosition = rand() % 8;

				if (helping[randomPosition] == 1) {

					if (randomPosition < 4) {
						breed(randomPosition, *getPosition(), this->getSign());
						return 99;
					}
					else {
						randomPosition -= 4;
						breed(randomPosition, *attackingPos, this->getSign());
						return 99;
					}
				}
			}
		}
		else if (defender->getSign() != this->getSign()) {
			if (defender->getSign() == '+' && this->getSign() == 'C') {
				world->killOrganism(defender, attackingPos->getX(), attackingPos->getY());
				world->writeText(this->getName() + " has killed " + defender->getName() + "\n");
				return 6;
			}

			if (defender->specialAttack(this, defender)) {

				if (defender->getSign() == 'G')
					return 6;
				if (defender->getSign() == 'A')
					return 6;

				return 5;
			}
			if (this->specialAttack(this, defender)) {
				return 4;
			}
			if (defender->getStrength() > getStrength()) {
				world->killOrganism(this, position.getX(), position.getY());
				world->writeText(defender->getName() + " has killed " + this->getName() + "\n");
				return 1;
			}
			else if (defender->getStrength() <= getStrength()) {
				world->killOrganism(defender, attackingPos->getX(), attackingPos->getY());
				world->writeText(this->getName() + " has killed " + defender->getName() + "\n");
				return 6;
			}
		}

	}


	
	return 0;
}


void Animal::breed(int direction, Position pos, char sign) {
	int posX = this->position.getX();
	int posY = this->position.getY();

	int direct = direction;
	// 0 - down, 1 - up, 2 - right, 3 - left

	int dy[4] = { 0, 0, 1, -1 };
	int dx[4] = { 1, -1, 0, 0 };

	int newPosX = posX + dx[direct];
	int newPosY = posY + dy[direct];

	if (newPosX >= world->getHeight() || newPosX < 0 || newPosY >= world->getWidth() || newPosY < 0)
		return;
	else if (world->returnSymbol(newPosX, newPosY) != '*')
		return;


	world->addOrganismToBoard(newPosY, newPosX, sign);
	world->writeText(this->getName() + " has been bred!\n");
}


void Animal::findSafeTwo(int* helpArray, Position* attackingPos) {
	int dy[4] = { 0, 0, 1, -1};
	int dx[4] = { 1 , -1, 0, 0 };

	int posX = attackingPos->getX();
	int posY = attackingPos->getY();

	for (int i = 0; i < 4; ++i) {
		if (world->returnSymbol(posX + dx[i], posY + dy[i]) == '*')
			helpArray[i] = 1;
		else if (world->returnSymbol(posX + dx[i], posY + dy[i]) == '?')
			helpArray[i] = 2;
	}

}