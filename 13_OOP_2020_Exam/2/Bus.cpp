#include "Bus.h"

Bus::Bus(const string &make, const string &model, unsigned int year, const string &problem, ProblemSeverity problemPriority, bool isTravelling)
        : Vehicle(make, model, year, problem, problemPriority), isTravelling(isTravelling) {}

Bus::Bus() : Vehicle(), isTravelling(false) {}

bool Bus::getIsTravelling() const {
    return isTravelling;
}

void Bus::setIsTravelling(bool newIsTravelling) {
    isTravelling = newIsTravelling;
}

Vehicle *Bus::clone() const {
    return new Bus(*this);
}
