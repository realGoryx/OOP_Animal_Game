#include "Position.h"


Position::Position(int x2, int y2) {
	this->x = x2;
	this->y = y2;
}

int Position::getX() {
	return x;
}

void Position::setX(int x2) {
	this->x = x2;
}

int Position::getY() {
	return y;
}

void Position::setY(int y2) {
	this->y = y2;
}