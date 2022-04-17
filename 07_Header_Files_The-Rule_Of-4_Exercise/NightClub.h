#ifndef DEMOS_NIGHTCLUB_H
#define DEMOS_NIGHTCLUB_H

#include <cstring>
#include <iostream>
#include <vector>
#include "Balloon.h"
#include "Shisha.h"
#include "Alcohol.h"
#include "AlcoholStore.h"

using namespace std;

class NightClub {
private:
    char *name;
    AlcoholStore alcoholStore;
    vector<Balloon> balloonsStore;

public:
    NightClub(const char *name);

    void addBalloon(const Balloon& balloon);

    void addShisha(const Shisha& shisha);

    void addAlcohol(const Alcohol& alcohol);

    void removeBalloon(Color color);

    void removeShisha(const char* brand, const char* taste);

    void removeAlcohol(char* name);

    bool existsBalloon(Color color);

    bool existsShisha(const char* brand, const char* taste);

    bool existsAlcohol(char* name);

    void print();
};

#endif //DEMOS_NIGHTCLUB_H
