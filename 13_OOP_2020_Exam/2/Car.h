#ifndef EXAMPREPARATION_CAR_H
#define EXAMPREPARATION_CAR_H

#include <string>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle {
private:
    bool isPrivate;

public:
    Car();

    Car(const string &make, const string &model, unsigned int year, const string &problem, ProblemSeverity problemPriority, bool isPrivate);

    bool getIsPrivate() const;

    void setIsPrivate(bool isPrivate);

    Vehicle *clone() const override;
};


#endif //EXAMPREPARATION_CAR_H
