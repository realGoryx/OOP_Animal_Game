#include "Plant.h"

void Plant::action() {
	this->yearsOld += 1;

	if (this->yearsOld < 3)
		return;

	int helping[4] = { 0,0,0,0 };
	int count = 0;

	findSafe(helping);

	for (int i = 0; i < 4; ++i) {
		if (helping[i] == 1)
			count++;
	}

	if (count == 0)
		return;

	int chance = rand() % 100;

	if (chance < 80) {
		return;
	}
	else {
		while (true) {
			int randomPosition = rand() % 4;

			if (helping[randomPosition] == 1) {
				sowing(randomPosition);
				return;
			}

		}
	}


}


void Plant::findSafe(int* helpArray) {
	int dx[4] = { 0, 0, 1, -1};
	int dy[4] = { 1, -1, 0, 0 };

	int posX = position.getX();
	int posY = position.getY();

	for (int i = 0; i < 4; ++i) {
		if (this->world->returnSymbol(posX + dx[i], posY + dy[i]) == '*')
			helpArray[i] = 1;
		else if (this->world->returnSymbol(posX + dx[i], posY + dy[i]) == '?')
			helpArray[i] = 2;
	}

}


void Plant::sowing(int direction) {
	int posX = this->position.getX();
	int posY = this->position.getY();

	int direct = direction;
	// 0 - down, 1 - up, 2 - right, 3 - left

	int dx[4] = { 0, 0, 1, -1};
	int dy[4] = { 1, -1, 0, 0 };

	int newPosX = posX + dx[direct];
	int newPosY = posY + dy[direct];

	if (newPosX >= world->getHeight() || newPosX < 0 || newPosY >= world->getWidth() || newPosY < 0)
		return;
	else if (world->returnSymbol(newPosX, newPosY) != '*')
		return;


	world->addOrganismToBoard(newPosX, newPosY, this->getSign());
	world->writeText(this->getName() + " has been sowed!" + "\n");
}



int Plant::collision(Position* attacking) {
	return 99;
}