#include "Car.h"

Car::Car(const string &make, const string &model, unsigned int year, const string &problem, ProblemSeverity problemPriority, bool isPrivate)
        : Vehicle(make, model, year, problem, problemPriority), isPrivate(isPrivate) {}

bool Car::getIsPrivate() const {
    return isPrivate;
}

void Car::setIsPrivate(bool newIsPrivate) {
    isPrivate = newIsPrivate;
}

Vehicle *Car::clone() const {
    return new Car(*this);
}

Car::Car() : Vehicle(), isPrivate(true) {

}
