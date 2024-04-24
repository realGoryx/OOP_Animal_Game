#pragma once
#include <iostream>
#include <vector>
#include "Position.h"
#include "World.h"

using namespace std;

class World;
class Organism
{
public:
	Organism() = default;
	virtual ~Organism() = default;


	virtual void action() = 0;
	virtual int collision(Position* attacking) = 0;

	int getStrength();
	void setStrength(int str);
	
	int getInitiative();
	void setInitiative(int ini);

	void setSign(char sgn);

	void setWorld(World* wrld);

	virtual bool specialAttack(Organism* attack, Organism* defend);

	virtual char getSign();

	Position* getPosition();
	void setPosition(int x, int y);

	string getName();
	void setName(string namee);

	int getYears();
	void setYears(int year);

	bool getMoved();
	void setMoved(bool moved);

	int getMovementSpeed();
	void setMovementSpeed(int speed);


protected:
	int strength = 0;
	int initiative = 0;
	int movementSpeed = 0;
	int yearsOld = 0;
	Position position = {};
	char sign;
	string name;
	World* world;
	bool movedFlag = false;
};

