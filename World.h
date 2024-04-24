#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Position;
class Organism;
class World
{
public:
	World();
	World(int height, int width);
	~World();

	void drawWorld();

	void startGame(World* world);

	void addOrganismToBoard(int posX, int posY, char sign);

	void makeTurn();

	void helpAnimalMove(Organism* organism, int h, int w);
	void eraseOrganism(int posX, int posY);


	int getHeight() const;
	int getWidth() const;

	Position checkFreePosition();
	void placeRandomly(Organism* organism);

	char returnSymbol(int h, int w);

	Organism* getOrganism(int h, int w) const;

	void killOrganism(Organism* organism, int h, int w);

	// Logs - information what is happening on the board
	void writeText(const string& text);
	void readText();
	void resetText();


	void saveGameStatus();
	void loadGameStatus();

	void setSaved(bool save);
	bool returnSaved();

	bool checkEndGame();
	void endGame();
	void endText();

	int countSos();
	void getSosnowskysPosition(vector<Position>* posVec);

protected:
	int width;
	int height;
	vector<vector<Organism*>> board;
	vector<Organism*> aliveOrganisms;
	
	bool saved = false;

};

