#include <iostream>
#include "World.h"
#include "Windows.h"

using namespace std;

#define WORLD_HEIGHT 12
#define WORLD_WIDTH 12

#define INTERFACE_HEIGHT 4
#define INTERFACE_WIDTH 25


int main()
{
    srand((unsigned)time(NULL));
    World* world{};
    world = new World(WORLD_HEIGHT, WORLD_WIDTH);


    cout << "+-------------------------+\n";
    cout << "|  Animal fighting game   |\n";
    cout << "|        193390           |\n";
    cout << "|                         |\n";
    cout << "|    1 - New Game         |\n";
    cout << "|    2 - Load Game        |\n";
    cout << "|                         |\n";
    cout << "+-------------------------+\n";


    char key;
    cin >> key;

    if (key == '1') {
        world->startGame(world);
        world->drawWorld();
    }
    if (key == '2') {
        world = new World();
        world->loadGameStatus();
        world->drawWorld();
    }
    while (true) {
        //Sleep(500);
        world->makeTurn();
        world->drawWorld();
    }
   
}


