#include "Organism.h"

using namespace std;

string Organism::getName(){
	return name;
};

void Organism::setName(string namee) {
	this->name = namee;
}


int Organism::getStrength() {
	return strength;
};

void Organism::setStrength(int str) {
	this->strength = str;
}

void Organism::setInitiative(int ini) {
	this->initiative = ini;
}

int Organism::getInitiative() {
	return initiative;
}

void Organism::setSign(char sgn) {
	this->sign = sgn;
}

void Organism::setWorld(World* wrld) {
	this->world = wrld;
}

Position* Organism::getPosition() {
	return &position;
}

void Organism::setPosition(int x, int y) {
	this->position.setX(x);
	this->position.setY(y);
}

char Organism::getSign() {
	return sign;
}

bool Organism::specialAttack(Organism* attack, Organism* defend) {
	return false;
}


int Organism::getYears() {
	return yearsOld;
}


void Organism::setYears(int year) {
	this->yearsOld = year;
}


bool Organism::getMoved() {
	return movedFlag;
}


void Organism::setMoved(bool moved) {
	this->movedFlag = moved;
}


int Organism::getMovementSpeed() {
	return movementSpeed;
}


void Organism::setMovementSpeed(int speed) {
	this->movementSpeed = speed;
}