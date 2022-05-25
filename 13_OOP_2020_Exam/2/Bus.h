#ifndef EXAMPREPARATION_BUS_H
#define EXAMPREPARATION_BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
private:
    bool isTravelling;

public:
    Bus();

    Bus(const string &make, const string &model, unsigned int year, const string &problem, ProblemSeverity problemPriority, bool isTravelling);

    bool getIsTravelling() const;

    void setIsTravelling(bool newIsTravelling);

    Vehicle *clone() const override;
};


#endif //EXAMPREPARATION_BUS_H
