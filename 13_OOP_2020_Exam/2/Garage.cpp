#include "Garage.h"

Garage::Garage(const Garage &garage) {
    copyVehicles(garage);
}

Garage &Garage::operator=(const Garage &garage) {
    if (this != &garage) {
        clear();
        copyVehicles(garage);
    }

    return *this;
}

void Garage::add(const Vehicle *vehicle) {
    int vehicleCapacity = getCapacityBySeverity(vehicle->getProblemSeverity());
    if (getCurrentCapacity() + vehicleCapacity > VEHICLE_GARAGE_MAX_CAPACITY) {
        return;
    }

    vehicles.push_back(vehicle->clone());
}

Garage::~Garage() {
    clear();
}

int Garage::getCurrentCapacity() const {
    int currentCapacity = 0;
    for (auto vehicle : vehicles) {
        currentCapacity += getCapacityBySeverity(vehicle->getProblemSeverity());
    }

    return currentCapacity;
}

int Garage::getCapacityBySeverity(ProblemSeverity severity) {
    switch (severity) {
        case ProblemSeverity::Low:
            return 1;
        case ProblemSeverity::Medium:
            return 3;
        case ProblemSeverity::High:
            return 5;
    }

    return 0;
}

void Garage::clear() {
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    vehicles.clear();
}

void Garage::copyVehicles(const Garage &garage) {
    for (auto vehicle : garage.vehicles) {
        this->vehicles.push_back(vehicle->clone());
    }
}

bool Garage::isFull() const {
    return getCurrentCapacity() == VEHICLE_GARAGE_MAX_CAPACITY;
}
