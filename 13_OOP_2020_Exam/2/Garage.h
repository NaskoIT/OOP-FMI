#ifndef EXAMPREPARATION_GARAGE_H
#define EXAMPREPARATION_GARAGE_H

#include <vector>
#include "Vehicle.h"

using namespace std;

const int VEHICLE_GARAGE_MAX_CAPACITY = 10;

class Garage {
private:
    vector<Vehicle *> vehicles;

    int getCurrentCapacity() const;

    void clear();

    void copyVehicles(const Garage &garage);

    static int getCapacityBySeverity(ProblemSeverity severity);

public:
    Garage() = default;

    Garage(const Garage &garage);

    ~Garage();

    Garage &operator=(const Garage &garage);

    void add(const Vehicle *vehicle);

    bool isFull() const;
};


#endif //EXAMPREPARATION_GARAGE_H
