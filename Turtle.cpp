#include "Turtle.h"
#include <windows.h>

Turtle::Turtle() {
    this->strength = 2;
    this->initiative = 1;
    this->setSign('T');
    this->setName("Turtle");
}

Turtle::Turtle(World* world, Position pos) {
    this->strength = 2;
    this->initiative = 1;
    this->setSign('T');
    this->setName("Turtle");
    this->setWorld(world);
    this->setPosition(pos.getX(), pos.getY());
}

void Turtle::action() {
    this->yearsOld += 1;

    int chance;
    chance = rand() % 4;

    if (chance < 2)
        Animal::action();

    return;
}

bool Turtle::specialAttack(Organism* attack, Organism* defend) {
    if (this == defend && attack->getStrength() > 5)
        return false;
    else if (this == defend && attack->getStrength() < 5) {
        world->writeText("Turtle has blocked the attack!");
        Sleep(1000);
        return true;
    }
    else
        return false;
}
