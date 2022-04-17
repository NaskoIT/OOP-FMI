#include "NightClub.h"

NightClub::NightClub(const char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void NightClub::addAlcohol(const Alcohol& alcohol) {
    this->alcoholStore.add(alcohol);
}

void NightClub::addBalloon(const Balloon& balloon) {
    this->balloonsStore.push_back(balloon);
}

