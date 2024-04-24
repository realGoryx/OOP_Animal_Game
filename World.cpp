#include "World.h"
#include <iostream>
#include "Organism.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Position.h"
#include "Human.h"
#include "Plant.h"
#include "Belladonna.h"
#include "Fox.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "SosnowskyHogweed.h"
#include "Cybersheep.h"
#include <cstring>
#include <string>

using namespace std;

#define DEFAULT_HEIGHT 20
#define DEFAULT_WIDTH 20

World::World() {
	this->height = DEFAULT_HEIGHT;
	this->width = DEFAULT_WIDTH;
}

World::World(int height, int width) {
	this->height = height;
	this->width = width;
	this->board.resize(height, vector<Organism*>(width, nullptr));
}

void World::drawWorld() {
	//cout << "\033[2J\033";
	system("CLS");

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (board[i][j] == nullptr)
				cout << ". ";
			else
				cout << board[i][j]->getSign() << " ";
		}
		cout << "\n";
	}

	readText();
}


World::~World() {

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			delete board[i][j];
		}
	}
}


int World::countSos() {
	int counter = 0;
	char sign;
	for (int i = 0; i < this->height; ++i) {
		for (int j = 0; j < this->width; ++j) {
			sign = returnSymbol(i, j);
			if (sign == '+')
				counter++;
		}
	}

	return counter;
}


void World::getSosnowskysPosition(vector<Position>* posVec){
	for (int i = 0; i < this->height; ++i) {
		for (int j = 0; j < this->width; ++j) {
			if (returnSymbol(i,j) == '+') {
				Position *pos;
				pos = board[i][j]->getPosition();

				int posX = pos->getX();
				int posY = pos->getY();

				posVec->push_back(Position(posX, posY));
			}
		}
	}
}



void World::placeRandomly(Organism* organism) {
	Position pos = checkFreePosition();

	if (board[pos.getX()][pos.getY()] == nullptr) {
		organism->setWorld(this);
		organism->setPosition(pos.getX(), pos.getY());
		board[pos.getX()][pos.getY()] = organism;
		aliveOrganisms.push_back(organism);
	}

}


Position World::checkFreePosition() {
	int i = height * width;

	while (i--) {
		int posX = rand() % height;
		int posY = rand() % width;

		if (board[posX][posY] == nullptr) {
			return Position(posX, posY);
		}
	}

	return { 1,1 };
}



void World::startGame(World* world) {
	Organism* sheep = new Sheep();
	Organism* sheep2 = new Sheep();

	Organism* wolf = new Wolf();
	Organism* wolf2 = new Wolf();
	Organism* wolf3 = new Wolf();
	Organism* wolf4 = new Wolf();

	Organism* turtle = new Turtle();
	Organism* turtle2 = new Turtle();

	Organism* antelope = new Antelope();

	Organism* human = new Human(this, {3,3});

	Organism* fox = new Fox();
	Organism* fox2 = new Fox();

	Organism* bella = new Belladonna();

	Organism* grass = new Grass();
	Organism* grass2 = new Grass();

	Organism* sow = new SowThistle();

	Organism* guarana = new Guarana();
	Organism* guarana2 = new Guarana();

	Organism* sos = new SosnowskyHogweed();
	Organism* sos2 = new SosnowskyHogweed();
	Organism* sos3 = new SosnowskyHogweed();

	Organism* cybersheep = new Cybersheep();
	Organism* cybersheep2 = new Cybersheep();


	placeRandomly(human);

	placeRandomly(cybersheep);
	placeRandomly(cybersheep2);

	placeRandomly(sheep);
	placeRandomly(sheep2);

	placeRandomly(wolf);
	placeRandomly(wolf2);
	placeRandomly(wolf3);
	placeRandomly(wolf4);

	placeRandomly(turtle);
	placeRandomly(turtle2);

	placeRandomly(antelope);

	placeRandomly(fox);
	placeRandomly(fox2);

	placeRandomly(bella);

	placeRandomly(grass);
	placeRandomly(grass2);

	placeRandomly(sow);

	placeRandomly(guarana);
	placeRandomly(guarana2);

	placeRandomly(sos);
	placeRandomly(sos2);
	placeRandomly(sos3);
	
}






void World::addOrganismToBoard(int posX, int posY, char sign) {
	Organism* organism = nullptr;

	if (sign == 'W') {
		Organism* wolf = new Wolf();
		organism = wolf;
	}
	else if (sign == 'A') {
		Organism* antelope = new Antelope();
		organism = antelope;
	}
	else if (sign == 'T') {
		Organism* turtle = new Turtle();
		organism = turtle;
	}
	else if (sign == 'S') {
		Organism* sheep = new Sheep();
		organism = sheep;
	}
	else if (sign == 'g') {
		Organism* grass = new Grass();
		organism = grass;
	}
	else if (sign == 's') {
		Organism* sow = new SowThistle();
		organism = sow;
	}
	else if (sign == '+') {
		Organism* sosnowsky = new SosnowskyHogweed();
		organism = sosnowsky;
	}
	else if (sign == 'G') {
		Organism* guarana = new Guarana();
		organism = guarana;
	}
	else if (sign == 'b') {
		Organism* belladonna = new Belladonna();
		organism = belladonna;
	}
	else if (sign == 'C') {
		Organism* cybersheep = new Cybersheep();
		organism = cybersheep;
	}

	organism->setWorld(this);
	organism->setPosition(posX, posY);
	board[posX][posY] = organism;
	aliveOrganisms.push_back(organism);
}


void World::helpAnimalMove(Organism* organism, int h, int w) {
	organism->setWorld(this);
	organism->setPosition(h, w);
	board[h][w] = organism;
}


void World::makeTurn() {

	if (checkEndGame())
		endGame();

	for (int i = 0; i < aliveOrganisms.size(); ++i) {
		Organism* org = aliveOrganisms[i];

		if (org->getMoved()) {
			continue;
		}

		int maxIndex = i;

		for (int j = i + 1; j < aliveOrganisms.size(); ++j) {
			Organism* currentOrg = aliveOrganisms[j];

			if (currentOrg->getMoved()) {
				continue;
			}

			if (currentOrg->getInitiative() > aliveOrganisms[maxIndex]->getInitiative() ||
				(currentOrg->getInitiative() == aliveOrganisms[maxIndex]->getInitiative() &&
					currentOrg->getYears() > aliveOrganisms[maxIndex]->getYears())) {
				maxIndex = j;
			}
		}

		if (maxIndex != i) {
			std::swap(aliveOrganisms[i], aliveOrganisms[maxIndex]);
		}

		org->action();
		org->setMoved(true);
	}

	for (int i = 0; i < aliveOrganisms.size(); ++i) {
		aliveOrganisms[i]->setMoved(false);
	}

	if (this->saved) {
		saveGameStatus();
		this->saved = false;
		this->writeText("Game state saved!\n");
	}

}


void World::setSaved(bool save) {
	this->saved = save;
}

bool World::returnSaved() {
	return saved;
}


void World::eraseOrganism(int posX, int posY) {
	board[posX][posY] = nullptr;
}


int World::getWidth() const {
	return width;
}

int World::getHeight() const {
	return height;
}


char World::returnSymbol(int h, int w) {
	if ((h >= 0 && h < (this->height)) && (w >= 0 && w < (this->width))) {
		if (board[h][w] == nullptr)
			return '*';
		else
			return board[h][w]->getSign();
	}
	else
		return '?';
}




Organism* World::getOrganism(int h, int w) const {
	return board[h][w];
}


void World::killOrganism(Organism* organism, int h, int w) {
	eraseOrganism(h, w);
	aliveOrganisms.erase(std::find(aliveOrganisms.begin(), aliveOrganisms.end(), organism));
}


void World::writeText(const string& text) {
	FILE* file;
	if (fopen_s(&file, "Log.txt", "a") == 0) {
		fprintf(file, "%s", text.c_str());
		fclose(file);
	}
	else {
		return;
	}
}

void World::readText() {
	FILE* file;
	fopen_s(&file, "Log.txt", "r");
	if (file != nullptr) {
		char line[256];
		while (fgets(line, sizeof(line), file) != nullptr) {
			cout << line;
		}
		fclose(file);
	}
	else {
		return;
	}

	resetText();
}

void World::resetText() {
	FILE* file;
	fopen_s(&file, "Log.txt", "w");
	fclose(file);
}


void World::endGame() {
	endText();
	exit(0);
}


void World::endText() {
	resetText();
	writeText("Game Over - Human died!\n");
	readText();
}


bool World::checkEndGame() {

	int capacity = aliveOrganisms.size();

	for (int i = 0; i < capacity; ++i) {
		if (aliveOrganisms[i]->getName() == "Human")
			return false;
		else if (i == capacity - 1)
			return true;
	}

	return false;
}

void World::saveGameStatus() {
	FILE* file;
	errno_t err;

	err = fopen_s(&file, "game.txt", "w");
	if (err == 0 && file != nullptr) {
		fprintf(file, "%d ", getHeight());
		fprintf(file, "%d ", getWidth());
		fprintf(file, "%d\n", static_cast<int>(aliveOrganisms.size()));

		for (auto& i : aliveOrganisms) {
			Position p = *i->getPosition();
			fprintf(file, "%c ", i->getSign());
			fprintf(file, "%d ", p.getX());
			fprintf(file, "%d ", p.getY());
			fprintf(file, "%d ", i->getStrength());
			fprintf(file, "%d ", i->getInitiative());
			fprintf(file, "%d ", i->getYears());

			if (i->getSign() == '@') {
				fprintf(file, "%d ", dynamic_cast<Human*>(i)->getRoundsSpecial());
			}
			fprintf(file, "\n");
		}
		fclose(file);
		cout << "Game state saved" << endl;
	}
}


void World::loadGameStatus() {
	FILE* file;
	errno_t err;

	err = fopen_s(&file, "game.txt", "r");
	if (err == 0 && file != nullptr) {
		int height, width, numOrganisms;
		int x, y, strength, initiative, year;
		int roundsSpecial;
		char symbol;

		fscanf_s(file, "%d %d", &height, &width);
		board.resize(height, vector<Organism*>(width, nullptr));

		this->height = height;
		this->width = width;

		fscanf_s(file, "%d", &numOrganisms);
		aliveOrganisms.clear();

		for (int i = 0; i < this->height; ++i) {
			for (int j = 0; j < this->width; ++j) {
				eraseOrganism(i, j);
			}
		}

		for (int i = 0; i < numOrganisms; i++) {
			fscanf_s(file, " %c", &symbol);
			fscanf_s(file, "%d %d", &x, &y);
			fscanf_s(file, "%d %d %d", &strength, &initiative, &year);
			Organism* newOrg;
			switch (symbol) {
			case '@':
				newOrg = new Human(this, Position(x, y));
				fscanf_s(file, "%d", &roundsSpecial);
				dynamic_cast<Human*>(newOrg)->setRoundsSpecial(roundsSpecial);
				break;
			case 'W':
				newOrg = new Wolf(this, Position(x, y));
				break;
			case 'A':
				newOrg = new Antelope(this, Position(x, y));
				break;
			case 'b':
				newOrg = new Belladonna(this, Position(x, y));
				break;
			case 'F':
				newOrg = new Fox(this, Position(x, y));
				break;
			case 'g':
				newOrg = new Grass(this, Position(x, y));
				break;
			case 'G':
				newOrg = new Guarana(this, Position(x, y));
				break;
			case 'S':
				newOrg = new Sheep(this, Position(x, y));
				break;
			case '+':
				newOrg = new SosnowskyHogweed(this, Position(x, y));
				break;
			case 's':
				newOrg = new SowThistle(this, Position(x, y));
				break;
			case 'T':
				newOrg = new Turtle(this, Position(x, y));
				break;
			case 'C':
				newOrg = new Cybersheep(this, Position(x, y));
				break;
			default:
				continue;
			}
			newOrg->setStrength(strength);
			newOrg->setInitiative(initiative);
			newOrg->setYears(year);
			newOrg->setMoved(false);
			helpAnimalMove(newOrg, x, y);
			aliveOrganisms.push_back(newOrg);
		}
		fclose(file);
	}
}