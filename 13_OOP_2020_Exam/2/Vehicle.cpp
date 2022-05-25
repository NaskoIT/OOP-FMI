#include "Vehicle.h"

Vehicle::Vehicle(const string &make, const string &model, unsigned int year, const string &problem, ProblemSeverity problemPriority) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->problem = problem;
    this->problemSeverity = problemPriority;
}

Vehicle::Vehicle() : year(0), problemSeverity(Low) {}

string Vehicle::getMake() const {
    return make;
}

void Vehicle::setMake(const string &newMake) {
    this->make = newMake;
}

string Vehicle::getModel() const {
    return model;
}

void Vehicle::setModel(const string &newModel) {
    model = newModel;
}

unsigned int Vehicle::getYear() const {
    return year;
}

void Vehicle::setYear(unsigned int newYear) {
    this->year = newYear;
}

void Vehicle::setProblem(const string &newProblem) {
    problem = newProblem;
}

string Vehicle::getProblem() const {
    return problem;
}

ProblemSeverity Vehicle::getProblemSeverity() const {
    return problemSeverity;
}

void Vehicle::setProblemSeverity(ProblemSeverity newProblemSeverity) {
    problemSeverity = newProblemSeverity;
}
